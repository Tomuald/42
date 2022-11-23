#include "WrongAnimal.class.hpp"
#include <iostream>

WrongAnimal::WrongAnimal(void) {
  this->type = "WrongAnimal";
  std::cout << this->type << " default constructor" << std::endl;
}
WrongAnimal::WrongAnimal(WrongAnimal const & src) {
  *this = src;
  std::cout << this->type << " copy constructor" << std::endl;
}
WrongAnimal::~WrongAnimal(void) {std::cout << "WrongAnimal destructor" << std::endl;}

WrongAnimal & WrongAnimal::operator=(WrongAnimal const & rhs) {
  if (this != &rhs) {
    this->type = rhs.type;
  }
  return (*this);
}

std::string WrongAnimal::getType(void) const {
  return (this->type);
}

std::ostream & operator<<(std::ostream & o, WrongAnimal const & i) {
  o << i.getType();
  return (o);
}

void WrongAnimal::makeSound(void) const {
  std::cout << "A WrongAnimal makes an animal sound. Scary..." << std::endl;
}
