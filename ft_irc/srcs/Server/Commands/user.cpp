#include "../Server.class.hpp"

std::string Server::user(Client & client, Message & msg) {
  if (msg.params.size() < 4)
    throw std::exception();

  client.setUsername(msg.params[0]);

  // size_t i;
  // std::string real_name;
  // for (i = 3; i < msg.params.size(); i++)
  //   real_name.append(msg.params[i]);
  // client.setRealname(real_name);
  std::string real_name = "Thomas Garriss";
  return (real_name + "\r\n");
}
