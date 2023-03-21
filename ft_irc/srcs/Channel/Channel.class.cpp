#include "Channel.class.hpp"

Channel::Channel(void) { return ; }

Channel::Channel(Channel const & src) {
  *this = src;
  return ;
}

Channel::~Channel(void) { return ; }

// Getters
std::string Channel::getName(void) const {
  return (this->_name);
}


Channel & Channel::operator=(Channel const & rhs) {
  if (this != &rhs) {
    this->_name = rhs._name;
    this->_clientsConnected = rhs._clientsConnected;
  }
  return (*this);
}

std::ostream & operator<<(std::ostream & o, Channel const & i) {
  o << i.getName();
  return (o);
}
