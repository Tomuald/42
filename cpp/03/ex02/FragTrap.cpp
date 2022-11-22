#include "FragTrap.hpp"

FragTrap::FragTrap(void) {
  this->_name = "default FragTrap";
  this->_hitPoints = 100;
  this->_energyPoints = 100;
  this->_attackDamage = 30;
  std::cout << "Creating Fragtrap: " << this->_name << std::endl;
}
FragTrap::FragTrap(std::string name) {
  this->_name = name;
  this->_hitPoints = 100;
  this->_energyPoints = 100;
  this->_attackDamage = 30;
  std::cout << "Creating Fragtrap: " << this->_name << std::endl;
}

FragTrap::FragTrap(FragTrap const & src) {
  *this = src;
  std::cout << "Copying Fragtrap: " << this->_name << std::endl;
}
FragTrap::~FragTrap(void) {
  std::cout << "Destroying Fragtrap: " << this->_name << std::endl;
}

FragTrap & FragTrap::operator=(FragTrap const & rhs) {
  if (this != &rhs) {
    this->_name = rhs._name;;
    this->_hitPoints = rhs._hitPoints;
    this->_energyPoints = rhs._energyPoints;
    this->_attackDamage = rhs._attackDamage;
  }
  return (*this);
}

void FragTrap::highFivesGuys(void) {
  std::cout << "FragTrap " << this->getName() << " says: High Fives guys!?" << std::endl;
}

std::ostream & operator<<(std::ostream & o, FragTrap const & i) {
  o << i.getName();
  return (o);
}
