#include "Server.class.hpp"

Server::Server(std::string port, std::string pass) : _port(port), _password(pass) {
  return;
}

bool Server::clientRegistered(int socket) const {
  std::vector<Client>::const_iterator it = this->_userbase.begin();
  for (it = this->_userbase.begin(); it != this->_userbase.end(); ++it) {
    const Client & obj = *it;
    if (obj.getSocket() == socket) {
      return (true);
    }
  }
  return (false);
}

void Server::registerClient(int socket, std::vector<Message> messages) {
  Client new_client(socket);

  std::cout << "Registering" << std::endl;
  std::vector<Message>::iterator it;
  for (it = messages.begin(); it != messages.end(); ++it) {
     if (it->command == "PASS") {
       std::string response = this->pass(new_client, (*it));
       send(socket, response.c_str(), response.length(), 0);
      }
     else if (it->command == "NICK") {
       std::string response = this->nick(new_client, (*it));
       send(socket, response.c_str(), response.length(), 0);
     } else if (it->command == "USER") {
      std::string response = this->user(new_client, (*it));
      send(socket, response.c_str(), response.length(), 0);
    }
  }
  if (!new_client.getUsername().empty() && \
      !new_client.getNickname().empty() && \
      new_client.passwordIsSet() == true) {
    std::string response = generateResponse(new_client.getNickname(), "001", "Welcome " + new_client.getNickname());
    send(socket, response.c_str(), response.length(), 0);
    this->_userbase.push_back(new_client);
    new_client.setRegistered();
    std::cout << "User registered!" << std::endl;
  } else {
    std::cout << "Failed!" << std::endl;
  }
  return ;
}

Client & Server::getClientBySocket(int socket) {
  std::vector<Client>::iterator it = this->_userbase.begin();
  for (it = this->_userbase.begin(); it != this->_userbase.end(); ++it) {
    Client & obj = *it;
    if (obj.getSocket() == socket) {
      return (obj);
    }
  }
  // return a null object if not found
  Client * _null = nullptr;
  return (*_null);
}

int Server::makeServerSocket(void) {
  this->_server_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (this->_server_socket == -1) {
    throw std::exception();
  }
  std::cout << "socket created" << std::endl;

  // set up addresses for binding
  struct sockaddr_in addr;
  addr.sin_family = AF_INET;
  addr.sin_port = htons(atoi(this->_port.c_str()));
  addr.sin_addr.s_addr = INADDR_ANY;

  if (bind(this->_server_socket, (struct sockaddr *) &addr, sizeof(addr)) == -1) {
    std::cout << strerror(errno) << std::endl;
    return (-1);
  }
  std::cout << "socket bound" << std::endl;

  int flags = fcntl(this->_server_socket, F_GETFL, 0);
  fcntl(this->_server_socket, F_SETFL, flags | O_NONBLOCK);

  if (listen(this->_server_socket, 10) == -1) {
    std::cout << strerror(errno) << std::endl;
    return (-1);
  }
  std::cout << "socket listening" << std::endl;

  return (0);
}

int Server::setUpKQ(void) {
  // set up a kqueue
  this->_kq = kqueue();
  if (this->_kq < 0) {
    std::cerr << strerror(errno) << std::endl;
    return (-1);
  }
  // set up kevent
  struct kevent event;
  EV_SET(&event, this->_server_socket, EVFILT_READ, EV_ADD, 0, 0, NULL);
  if (kevent(this->_kq, &event, 1, NULL, 0, NULL) < 0) {
    std::cerr << strerror(errno) << std::endl;
    return (-1);
  }
  return (0);
}

void Server::handleRequest(int socket, char buffer[1024]) {
  std::cout << buffer << std::endl;

  if (this->clientRegistered(socket) == false) {
    std::vector<Message> messages = this->parse(buffer);
    this->registerClient(socket, messages);
  } else {
    // client exists, handle request
    std::vector<Message> messages = this->parse(buffer);
    std::vector<Message>::iterator it;
    for (it = messages.begin(); it != messages.end(); ++it) {
      Client client = this->getClientBySocket(socket);
      std::string response = this->execute(client, (*it));
      send(socket, response.c_str(), response.length(), 0);
    }
  }
}

void Server::start(void) {
  // init a server socket
  if (this->makeServerSocket() == -1) {
    throw std::exception();
  }
  // init a kqueue
  if (this->setUpKQ() == -1) {
    throw std::exception();
  }
  // main server loop
  while (true) {
    // make this dynamic or larger
    struct kevent events[16];

    int num_events = kevent(this->_kq, NULL, 0, events, 16, NULL);
    if (num_events == -1) {
      std::cerr << strerror(errno) << std::endl;
      throw std::exception();
    }

    for (int i = 0; i < num_events; i++) {
      int socket = events[i].ident;
      if (socket == this->_server_socket) {
           // new connection
           std::cout << "registering new connection" << std::endl;
           int accept_socket = accept(this->_server_socket, NULL, NULL);
           if (accept_socket == -1) {
               std::cerr << strerror(errno) << std::endl;
               continue;
           }
           EV_SET(&this->_event, accept_socket, EVFILT_READ, EV_ADD, 0, 0, NULL);
           if (kevent(this->_kq, &this->_event, 1, NULL, 0, NULL) < 0) {
             std::cerr << "Error: Failed to add client socket to kqueue." << std::endl;
             close(accept_socket);
             continue;
           }
       } else {
        // handle data on client socket
        std::cout << "handling client request" << std::endl;
        char buffer[1024];
        int nbytes = recv(events[i].ident, buffer, sizeof(buffer), 0);
        buffer[nbytes] = '\0';
        if (nbytes < 0) {
           std::cerr << "Error: Failed to receive data from client socket." << std::endl;
           close(events[i].ident);
           continue;
        } else if (nbytes == 0) {
           // Client has disconnected
           close(events[i].ident);
           continue;
        } else {
          std::cout << buffer << std::endl;
          this->handleRequest(socket, buffer);
        }
        memset(buffer, 0, sizeof(*buffer));
      }
    }
  }
  close(this->_server_socket);
}

std::vector<Message> Server::parse(char buffer[1024]) {
  std::vector<Message> messages;
  std::string input(buffer);
  std::istringstream iss(input);

  std::string line;
  while (std::getline(iss, line)) {
    Message msg(line);
    messages.push_back(msg);
  }
  return (messages);
}

std::string Server::execute(Client & client, Message & msg) {
  std::map<std::string, fctPointer> functionMap = this->getFunctionMap();
  std::map<std::string, fctPointer>::iterator it;

  std::string response;
  for (it = functionMap.begin(); it != functionMap.end(); ++it) {
    if (msg.command == it->first) {
      fctPointer func = it->second;
      std::cout << "Executing: " << it->first << std::endl;
      response = (this->*func)(client, msg);
    }
  }
  return (response);
}

// consider building this in your constructors!
std::map<std::string, Server::fctPointer> Server::getFunctionMap(void) {
  std::map<std::string, fctPointer> functionMap;
  // basic functions
  functionMap.insert(make_pair("PASS", &Server::pass));
  functionMap.insert(make_pair("QUIT", &Server::quit));
  // operator functions

  return (functionMap);
}

Server::~Server(void) {return;}