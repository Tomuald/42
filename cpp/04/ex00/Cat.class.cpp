#include "Cat.class.hpp"

Cat::Cat(void) {}
Cat::Cat(Cat const & src) {*this = src;}
Cat::~Cat(void) {}

Cat & Cat::operator=(Cat const & rhs) {
  if (this != &rhs) {
    // ...
  }
  return (*this);
}

std::ostream & operator<<(std::ostream & o, Cat const & i) {
  o << i.<PROPERTY>();
  return (o);
}
