#include "Brain.class.hpp"

Brain::Brain(void) {
  std::cout << "Brain default constr." << std::endl;
}

Brain::Brain(Brain const & src) {
  *this = src;
  std::cout << "Brain cpy constr." << std::endl;
}
Brain::~Brain(void) {
  std::cout << "Brain default destr." << std::endl;
}

Brain & Brain::operator=(Brain const & rhs) {
  if (this != &rhs) {
    std::copy(rhs._ideas, rhs._ideas + 100, this->_ideas);
  }
  return (*this);
}
