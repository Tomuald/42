#include "Message.class.hpp"

Message::Message(void) { return ; }

Message::Message(Message const & src) {
  this->prefix = src.prefix;
  this->command = src.command;
  this->params = src.params;
  return ;
}

Message::Message(const std::string & line) {
  //std::cout << line << std::endl;
  std::string::size_type pos = 0;
  if (line[pos] == ':') {
    std::string::size_type prefix_end = line.find(' ', pos);
    if (prefix_end != std::string::npos) {
      this->prefix = line.substr(pos + 1, prefix_end - pos - 1);
      pos = prefix_end + 1;
    }
  }

  std::string::size_type cmd_end = line.find(' ', pos);
  if (cmd_end != std::string::npos) {
    this->command = line.substr(pos, cmd_end - pos);
    pos = cmd_end + 1;
    //std::cout << "Command: " << this->command << std::endl;
  }

  while (pos < line.length()) {
    std::string param;
    if (line[pos] == ':') {
      param = line.substr(pos + 1);
      this->params.push_back(param);
      break ;
    } else {
      std::string::size_type param_end = line.find(' ', pos);
      if (param_end != std::string::npos) {
        param = line.substr(pos, param_end - pos);
        this->params.push_back(param);
        pos = param_end + 1;
      } else {
        param = line.substr(pos);
        params.push_back(param);
        break ;
      }
    }
  }
}

Message::~Message(void) { return ; }

Message & Message::operator=(Message const & rhs) {
  if (this != &rhs) {
    this->prefix = rhs.prefix;
    this->command = rhs.command;
    this->params = rhs.params;
  }
  return (*this);
}

std::ostream & operator<<(std::ostream & o, Message const & i) {
  o << "Print something";
  (void) i;
  return (o);
}
