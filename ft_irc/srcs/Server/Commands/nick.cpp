#include "../Server.class.hpp"

std::string Server::nick(Client & client, Message & msg) {
  if (msg.params.size() != 1) {
    throw std::exception();
  }
  std::vector<Client>::iterator it;
  for (it = this->_userbase.begin(); it != this->_userbase.end(); ++it) {
    if (it->getUsername() == msg.params[0]) {
      throw std::exception();
    }
  }
  client.setNickname(msg.params[0]);
  return ("nickname set!\r\n");
}
