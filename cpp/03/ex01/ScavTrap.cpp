#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) {
	this->_name = "Default";
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_hitPoints = 20;
	std::cout << this->_name << " ScavTrap created def.constr." << std::endl;
}

ScavTrap::ScavTrap(std::string name) {
  this->_name = name;
  this->_hitPoints = 100;
  this->_energyPoints = 50;
  this->_attackDamage = 20;
  std::cout << this->_name << " ScavTrap created std::string constr." << std::endl;
}
ScavTrap::ScavTrap(ScavTrap const & src) {
  *this = src;
  std::cout << this->_name << " ScavTrap created cpy.constr." << std::endl;
}

ScavTrap::~ScavTrap(void) {std::cout << "Scav destr." << std::endl;}

ScavTrap & ScavTrap::operator=(ScavTrap const & rhs) {
  std::cout << "using assign operator overload" << std::endl;
  if (this != &rhs) {
    this->_name = rhs._name;
    this->_hitPoints = rhs._hitPoints;
    this->_energyPoints = rhs._energyPoints;
    this->_attackDamage = rhs._attackDamage;
  }
  return (*this);
}

void ScavTrap::attack(const std::string & target) {
  if (this->getHP() <= 0) {
    std::cout << this->getName() << " is dead, and can't attack." << std::endl;
    return ;
  }
  if (this->_energyPoints <= 0) {
    std::cout << "ScavTrap is out of energy, and can't attack." << std::endl;
    return ;
  }
  std::cout << "ScavTrap " << this->_name << " attacks " << target << " for " << this->_attackDamage << " damage. "<< std::endl;
  this->_energyPoints--;
  return ;
}

void ScavTrap::guardGate(void) {
  static int state;
  if (this->getHP() <= 0) {
    std::cout << this->getName() << " is dead, and can't guard." << std::endl;
    return ;
  }
  if (state == 0) {
    std::cout << this->getName() << " enters Gate Keeper mode." << std::endl;
    state = 1;
  }
  else {
    std::cout << this->getName() << " exits Gate Keeper mode." << std::endl;
    state = 0;
  }
}
