#include "../Server.class.hpp"

std::string Server::pass(Client & client, Message & msg) {
  if (msg.params.size() != 1)
    throw std::exception();
  if (!msg.params[0].empty()) {
    msg.params[0].erase(msg.params[0].length() - 1, 1);
  }
  if (this->_password.compare(msg.params[0]) != 0)
    throw std::exception();
  client.setPassword(msg.params[0]);
  return ("password ok \r\n");
}
