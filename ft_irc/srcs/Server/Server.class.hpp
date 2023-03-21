#ifndef SERVER_CLASS_HPP_
# define SERVER_CLASS_HPP_

# include <sys/types.h>
# include <sys/event.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <fcntl.h>
# include <unistd.h>
# include <cstdlib>
# include <iostream>
# include <map>
# include <string>
# include <vector>
# include <sstream>

# include "../Client/Client.class.hpp"
# include "../Channel/Channel.class.hpp"
# include "../Message/Message.class.hpp"

std::string generateResponse(std::string command, std::string code, std::string msg);

class Server {
  public:
    // function pointer for the functionMap
    typedef std::string (Server::*fctPointer)(Client & client, Message & msg);

    Server(void);
    Server(Server const & src);
    Server(std::string port, std::string pass);
    ~Server(void);

    // general functions
    int makeServerSocket(void);
    bool clientRegistered(int socket) const;
    void registerClient(int socket, std::vector<Message> messages);
    void handleRequest(int socket, char buffer[1024]);
    void start(void);
    int setUpKQ(void);
    Client & getClientBySocket(int socket);
    std::string execute(Client & client, Message & msg);
    std::vector<Message> parse(char buffer[1024]);
    std::map<std::string, fctPointer> getFunctionMap(void);

    // Commands (found in ./Commands/*.cpp)
    std::string pass(Client & client, Message & msg);
    std::string nick(Client & client, Message & msg);
    std::string user(Client & client, Message & msg);
    std::string quit(Client & client, Message & msg);
    std::string join(Client & client, Message & msg);

    // Overloads
    Server & operator=(Server const & rhs);
  private:
    std::string _port;
    std::string _password;
    int _server_socket;
    int _kq;
    struct kevent _event;
    std::vector<Client> _userbase;
    std::vector<Channel> _channels;

};

std::ostream & operator<<(std::ostream & o, Server const & i);

#endif // SERVERCLASS_H_
