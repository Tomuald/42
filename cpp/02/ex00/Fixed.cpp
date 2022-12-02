#include "Fixed.hpp"

Fixed::Fixed (void) : _n(0) {
  std::cout << "constr." << std::endl;
}

Fixed::Fixed(Fixed const & src) {
  std::cout << "copy constr." << std::endl;
  *this = src;
  return ;
}

Fixed::~Fixed(void) {std::cout << "destr." << std::endl;}

int Fixed::getRawBits(void) const {return (this->_n);}
void Fixed::setRawBits(int const raw) {
  this->_n = raw;
}

Fixed & Fixed::operator=(Fixed const & rhs) {
  if (this != &rhs)
    this->_n = rhs.getRawBits();
  return (*this);
}
X
