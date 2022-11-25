#include "WrongCat.class.hpp"
#include <iostream>

WrongCat::WrongCat(void) {
  this->type = "WrongCat";
  std::cout << this->type << " default constructor" << std::endl;
}

WrongCat::WrongCat(WrongCat const & src) : WrongAnimal(src) {
  *this = src;
  std::cout << this->type << "copy constructor" << std::endl;
}
WrongCat::~WrongCat(void) {
  std::cout << "WrongCat destructor" << std::endl;
}

WrongCat & WrongCat::operator=(WrongCat const & rhs) {
  if (this != &rhs) {
    this->type = rhs.type;
  }
  return (*this);
}

std::ostream & operator<<(std::ostream & o, WrongCat const & i) {
  o << i.getType();
  return (o);
}

void WrongCat::makeSound(void) const {
  std::cout << "WrongCat Sound. Amazing." << std::endl;
}
