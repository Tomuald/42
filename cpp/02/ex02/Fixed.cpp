#include "Fixed.hpp"

// Constructors
Fixed::Fixed (void) : _n(0) {}
Fixed::Fixed(int const n) : _n(n << _nbits) {}
Fixed::Fixed(float const n) : _n(int(roundf(n * (1 << _nbits)))) {}
Fixed::Fixed(Fixed const & src) {*this = src;}

// Destructor
Fixed::~Fixed(void) {}

// member functions
int Fixed::getRawBits(void) const {return (this->_n);}
void Fixed::setRawBits(int const raw) {this->_n = raw;}
float Fixed::toFloat(void) const {return (float(this->_n) / (1 << _nbits));}
int Fixed::toInt(void) const {return (this->_n >> _nbits);}

Fixed & Fixed::min(Fixed & a, Fixed & b) {return (a < b ? a : b);}
const Fixed & Fixed::min(const Fixed & a, const Fixed & b) {return (a._n < b._n ? a : b);}
Fixed & Fixed::max(Fixed & a, Fixed & b) {return (a > b ? a : b);}
const Fixed & Fixed::max(const Fixed & a, const Fixed & b) {return (a._n > b._n ? a : b);}

// assignation overload
Fixed & Fixed::operator=(Fixed const & rhs) {
  if (this != &rhs)
    this->_n = rhs.getRawBits();
  return (*this);
}

// comparison overloads
bool Fixed::operator>(Fixed const & rhs) {
  if (this->_n > rhs._n)
    return (true);
  return (false);
}

bool Fixed::operator<(const Fixed & rhs) {
  if (this->_n < rhs._n)
    return (true);
  return (false);
}

bool Fixed::operator>=(Fixed const & rhs) {
  if (this->_n >= rhs._n)
    return (true);
  return (false);
}

bool Fixed::operator<=(Fixed const & rhs) {
  if (this->_n <= rhs._n)
    return (true);
  return (false);
}

bool Fixed::operator==(Fixed const & rhs) {
  if (this->_n == rhs._n)
    return (true);
  return (false);
}

bool Fixed::operator!=(Fixed const & rhs) {
  if (this->_n != rhs._n)
    return (true);
  return (false);
}

// arithmetic overloads
Fixed Fixed::operator+(const Fixed & rhs) const {
  Fixed _new;

  _new.setRawBits(this->_n + rhs.getRawBits());
  return (_new);
}

Fixed Fixed::operator-(const Fixed & rhs) const {
  Fixed _new;

  _new.setRawBits(this->_n - rhs.getRawBits());
  return (_new);
}

Fixed Fixed::operator*(const Fixed & rhs) const {
  Fixed _new;

  _new.setRawBits((this->_n * rhs.getRawBits()) >> this->_nbits);
  return (_new);
}

Fixed Fixed::operator/(const Fixed & rhs) const {
  Fixed _new;

  _new.setRawBits((this->_n << this->_nbits) / rhs.getRawBits());
  return (_new);
}

// incr/decr overloads
Fixed & Fixed::operator++(void) {
  this->_n++;
  return (*this);
}

Fixed & Fixed::operator--(void) {
  this->_n--;
  return (*this);
}

Fixed Fixed::operator++(int) {
  Fixed tmp(*this);
  operator++();
  return (tmp);
}

Fixed Fixed::operator--(int) {
  Fixed tmp(*this);
  operator--();
  return (tmp);
}

// stream operator overloads
std::ostream & operator<<(std::ostream & o, const Fixed & fixed) {
  o << fixed.toFloat();
  return (o);
}
