#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed (void) : _n(0) {
  std::cout << "constr." << std::endl;
}

Fixed::Fixed(const int i) {
  this->_n = (i << this->_nbits);
}
Fixed::Fixed(const float f) {
  this->_n = int(roundf(f * (1 << this->nbits)));
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
