#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {
  public:
    Fixed(void);
    Fixed(Fixed const & src);
    Fixed(int const n);
    Fixed(float const n);
    ~Fixed(void);
    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat(void) const;
    int toInt(void) const;
    static Fixed & min(Fixed & a, Fixed & b);
    static const Fixed & min(const Fixed & a, const Fixed & b);
    static Fixed & max(Fixed & a, Fixed & b);
    static const Fixed & max(const Fixed & a, const Fixed & b);
    Fixed & operator=(Fixed const & rhs);
    bool operator>(Fixed const & rhs);
    bool operator<(Fixed const & rhs);
    bool operator>=(Fixed const & rhs);
    bool operator<=(Fixed const & rhs);
    bool operator==(Fixed const & rhs);
    bool operator!=(Fixed const & rhs);
    Fixed & operator++(void);
    Fixed & operator--(void);
    Fixed operator++(int);
    Fixed operator--(int);
    Fixed operator+(const Fixed & rhs) const;
    Fixed operator-(const Fixed & rhs) const;
    Fixed operator*(const Fixed & rhs) const;
    Fixed operator/(const Fixed & rhs) const;

  private:
    int _n; // init'd to 0
    static const int _nbits = 8; // always init'd to 8
};

std::ostream & operator<<(std::ostream & o, const Fixed & fixed);

#endif
