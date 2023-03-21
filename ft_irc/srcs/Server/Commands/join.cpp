#include "../Server.class.hpp"

std::string Server::join(Client & client, Message & msg) {
  if (msg.params.size() < 1) {
    return ("ERROR\r\n");
  }
  (void) client;
  return ("SUCCESS\r\n");
}
