#include "Zombie.hpp"

Zombie::Zombie(std::string name) {
  std::cout << "Constructing..." << std::endl;
  setName(name);
  return ;
}

Zombie::~Zombie(void) {
  std::cout << "Destroying: " << this->_name << std::endl;
  return ;
}

void Zombie::announce(void) const {
  std::cout << this->getName() << " : BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name) {
  this->_name = name;
  return ;
}

std::string Zombie::getName(void) const {
  return (this->_name);
}
