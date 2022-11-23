#include "Cat.class.hpp"

Cat::Cat(void) {
  this->type = "Cat";
  this->_brain = new Brain();
  std::cout << this->type << " default constructor" << std::endl;
}

Cat::Cat(Cat const & src) : AAnimal(src) {
  *this = src;
  std::cout << this->type << "copy constructor" << std::endl;
}
Cat::~Cat(void) {
  delete this->_brain;
  std::cout << "Cat destructor" << std::endl;
}

Cat & Cat::operator=(Cat const & rhs) {
  if (this != &rhs) {
    this->type = rhs.type;
  }
  return (*this);
}

std::ostream & operator<<(std::ostream & o, Cat const & i) {
  o << i.getType();
  return (o);
}

void Cat::makeSound(void) const {
  std::cout << "Cat Sound. Amazing." << std::endl;
}
