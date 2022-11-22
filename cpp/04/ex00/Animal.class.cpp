#include "Animal.class.hpp"

Animal::Animal(void) {
  this->type = "Animal";
  std::cout << this->type << " default constructor" << std::endl;
}
Animal::Animal(Animal const & src) {
  *this = src;
  std::cout << this->type << " copy constructor" << std::endl;
}
Animal::~Animal(void) {std::cout << "Animal destructor" << std::endl;}

Animal & Animal::operator=(Animal const & rhs) {
  if (this != &rhs) {
    this->type = rhs.type;
  }
  return (*this);
}

std::string Animal::getType(void) const {
  return (this->type);
}

std::ostream & operator<<(std::ostream & o, Animal const & i) {
  o << i.getType();
  return (o);
}

void Animal::makeSound(void) const {
  std::cout << "An animal makes an animal sound. Wow." << std::endl;
}
