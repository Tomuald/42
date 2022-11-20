#include "ClapTrap.hpp"


ClapTrap::ClapTrap(std::string name) : _name(name) {
  std::cout << "std::string constr." << std::endl;
  this->_hitPoints = 10;
  this->_energyPoints = 10;
  this->_attackDamage = 0;
}
ClapTrap::ClapTrap(ClapTrap const & src) {
  std::cout << "copy constr." << std::endl;
  *this = src;
}
ClapTrap::~ClapTrap(void) {std::cout << "destr." << std::endl;}

ClapTrap & ClapTrap::operator=(ClapTrap const & rhs) {
  std::cout << "using assign operator overload" << std::endl;
  if (this != &rhs) {
    this->_name = rhs._name;
    this->_hitPoints = rhs._hitPoints;
    this->_energyPoints = rhs._energyPoints;
    this->_attackDamage = rhs._attackDamage;
  }
  return (*this);
}

void ClapTrap::attack(const std::string & target) {
  if (this->_energyPoints <= 0) {
    std::cout << "ClapTrap is out of energy, and does nothing." << std::endl;
    return ;
  }
  std::cout << "ClapTrap " << this->_name << " attacks " << target << " for " << this->_attackDamage << " damage. "<< std::endl;
  this->_energyPoints--;
  return ;
}

void ClapTrap::takeDamage(unsigned int amount) {
  std::cout << "ClapTrap " << this->_name << " takes " << amount << " of damage." << std::endl;
  this->_hitPoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount) {
  if (this->_energyPoints <= 0) {
    std::cout << "ClapTrap is out of energy, and does nothing." << std::endl;
    return ;
  }
  std::cout << "ClapTrap " << this->_name << " heals for " << amount << " hit points." << std::endl;
  this->_energyPoints--;
  this->_hitPoints += amount;
  return ;
}

std::string ClapTrap::getName(void) const {
  return (this->_name);
}

unsigned int ClapTrap::getHP(void) const {
  return (this->_hitPoints);
}

unsigned int ClapTrap::getEP(void) const {
  return (this->_energyPoints);
}

std::ostream & operator<<(std::ostream & o, ClapTrap const & i) {
  o << i.getName() << std::endl;
  return (o);
}
