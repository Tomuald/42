#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {
  public:
    Fixed(void);
    Fixed(const int i);
    Fixed(const float f);
    Fixed(Fixed const & src);
    ~Fixed(void);
    int getRawBits(void) const; // gets _n
    void setRawBits(int const raw); //sets _n
    Fixed & operator=(Fixed const & rhs);
    float toFloat(void) const;
    int toInt(void) const;
  private:
    int _n; // init'd to 0
    static const int _nbits = 8; // always init'd to 8
};

std::ostream & operator<<(std::ostream & out, Fixed const & rhs);

#endif
