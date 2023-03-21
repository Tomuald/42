#include "../Server.class.hpp"

std::string Server::quit(Client & client, Message & message) {
  std::vector<Client>::iterator it;
  for (it = this->_userbase.begin(); it != this->_userbase.end(); ++it) {
    if (it->getSocket() == client.getSocket()) {
      close(client.getSocket());
      this->_userbase.erase(it);
      break ;
    }
  }

  std::string response = generateResponse(message.command, "000", "Has quit");
  return (response);
}
