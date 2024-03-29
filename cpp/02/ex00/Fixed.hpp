#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {
  public:
    Fixed(void);
    Fixed(Fixed const & src);
    ~Fixed(void);
    int getRawBits(void) const; // gets _n
    void setRawBits(int const raw); //sets _n
    Fixed & operator=(Fixed const & rhs);
  private:
    int _n; // init'd to 0
    static const int _nbits = 8; // always init'd to 8
};

#endif
