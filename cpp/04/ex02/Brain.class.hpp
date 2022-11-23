#ifndef BRAIN_CLASS_HPP_
# define BRAIN_CLASS_HPP_

#include <iostream>

class Brain {
  public:
    Brain(void);
    Brain(const Brain & src);
    ~Brain(void);

    Brain & operator=(Brain const & rhs);
  private:
    std::string _ideas[100];
};

#endif // BRAIN_CLASS_HPP_
