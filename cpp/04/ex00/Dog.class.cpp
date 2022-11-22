#include "Dog.class.hpp"

Dog::Dog(void) {
  this->type = "Dog";
  std::cout << this->getType() << " default constructor" << std::endl;
}

Dog::Dog(Dog const & src) : Animal(src) {
  *this = src;
  std::cout << this->type << "copy constructor" << std::endl;
}
Dog::~Dog(void) {
  std::cout << "Dog destructor" << std::endl;
}

Dog & Dog::operator=(Dog const & rhs) {
  if (this != &rhs) {
    this->type = rhs.type;
  }
  return (*this);
}

std::ostream & operator<<(std::ostream & o, Dog const & i) {
  o << i.getType();
  return (o);
}

void Dog::makeSound(void) const {
  std::cout << "Doglike gibberish." << std::endl;
}
