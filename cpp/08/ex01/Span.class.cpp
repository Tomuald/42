#include "Span.class.hpp"
#include <iterator>
#include <list>
#include <algorithm>
#include <iostream>
//#include <stl>

//========== Constructors & Destructors ============================
Span::Span(void) : _max(0) {}
Span::Span(unsigned int n) : _max(n) {}
Span::Span(Span const & src) {*this = src;}
Span::~Span(void) {}

//========== Overloads  ============================================
Span & Span::operator=(Span const & rhs) {
  if (this != &rhs) {
    this->_array = rhs._array;
    this->_max = rhs._max;
  }
  return (*this);
}

//========== Functions  ============================================
void Span::addNumber(int const n) {
  if (this->_array.size() >= this->getMax()) {
    throw Span::AlreadyFullException();
  }
  this->_array.push_back(n);
  return ;
}

int Span::shortestSpan(void)  {
  this->_array.sort();
  std::list<int>::iterator iter = this->_array.begin();
  std::advance(iter, this->_max - 2);
  int before_last = *iter;
  std::list<int>::iterator iter2 = this->_array.begin();
  std::advance(iter2, this->_max - 1);
  int last = *iter2;
  return (std::abs(last - before_last));
}

int Span::longestSpan(void) {
    if (this->getArray().size() < 2)
    throw Span::TooFewNumbersException();
  int min  = *std::min_element(this->getArray().begin(), this->getArray().end());
  int max  = *std::max_element(this->getArray().begin(), this->getArray().end());
  return (max - min);
}

unsigned int Span::getMax(void) const { return (this->_max); }

std::list<int> & Span::getArray(void) {
  return (this->_array);
}
//========== Exceptions  ===========================================

//========== Others  ===============================================
std::ostream & operator<<(std::ostream & o, Span & i) {
  for ( std::list<int>::const_iterator it = i.getArray().begin(); it != i.getArray().end(); ++it )
        o << *it << std::endl;
    return o;
}
