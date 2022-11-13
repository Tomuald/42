#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon) {
  return ;
}

HumanA::~HumanA(void) {
  return ;
}

void HumanA::attack(void) const {
  std::cout << getName() << " attacks with " << getWeapon() << std::endl;
  return ;
}

std::string HumanA::getName(void) const {
  return (this->_name);
}

std::string HumanA::getWeapon(void) const {
  return (this->_weapon.getType());
}
