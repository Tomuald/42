#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL) {
  return ;
}

HumanB::~HumanB(void) {
  return ;
}

void HumanB::attack(void) const {
  if (_weapon == NULL)
  {
    std::cout << this->getName() << " has no weapon." << std::endl;
    return ;
  }
  std::cout << this->getName() << " attacks with " << this->_weapon->getType() << std::endl;
  return ;
}

std::string HumanB::getName(void) const {
  return (this->_name);
}

void HumanB::setWeapon(Weapon &weapon) {
  this->_weapon = &weapon;
  return ;
}
