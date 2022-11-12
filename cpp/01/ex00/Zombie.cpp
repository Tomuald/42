#include "Zombie.hpp"

Zombie::Zombie(std::string name) : _name(name) {
  std::cout << "Constructing..." << std::endl;
  return ;
}

Zombie::~Zombie(void) {
  std::cout << "Destroying: " << this->_name << std::endl;
  return ;
}

void Zombie::announce(void) const {
  std::cout << this->_name << " : BraiiiiiiinnnzzzZ..." << std::endl;
}
