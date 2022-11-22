#include "Animal.class.hpp"

Animal::Animal(void) {}
Animal::Animal(Animal const & src) {*this = src;}
Animal::~Animal(void) {}

Animal & Animal::operator=(Animal const & rhs) {
  if (this != &rhs) {
    // ...
  }
  return (*this);
}

std::ostream & operator<<(std::ostream & o, Animal const & i) {
  o << i.<PROPERTY>();
  return (o);
}
