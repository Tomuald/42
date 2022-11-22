#include "Dog.class.hpp"

Dog::Dog(void) {}
Dog::Dog(Dog const & src) {*this = src;}
Dog::~Dog(void) {}

Dog & Dog::operator=(Dog const & rhs) {
  if (this != &rhs) {
    // ...
  }
  return (*this);
}

std::ostream & operator<<(std::ostream & o, Dog const & i) {
  o << i.<PROPERTY>();
  return (o);
}
