#include "Animal.class.hpp"

AAnimal::AAnimal(void) {
  this->type = "AAnimal";
  std::cout << this->type << " default constructor" << std::endl;
}
AAnimal::AAnimal(AAnimal const & src) {
  *this = src;
  std::cout << this->type << " copy constructor" << std::endl;
}
AAnimal::~AAnimal(void) {std::cout << "AAnimal destructor" << std::endl;}

AAnimal & AAnimal::operator=(AAnimal const & rhs) {
  if (this != &rhs) {
    this->type = rhs.type;
  }
  return (*this);
}

std::string AAnimal::getType(void) const {
  return (this->type);
}

std::ostream & operator<<(std::ostream & o, AAnimal const & i) {
  o << i.getType();
  return (o);
}
