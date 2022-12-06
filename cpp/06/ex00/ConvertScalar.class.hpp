#ifndef CONVERTSCALAR_CLASS_HPP_
# define CONVERTSCALAR_CLASS_HPP_

#include <iostream>

class ConvertScalar {
  public:
    ConvertScalar(void);
    ConvertScalar(char *literal);
    ConvertScalar(const ConvertScalar & src);
    ~ConvertScalar(void);

    ConvertScalar & operator=(ConvertScalar const & rhs);

    //===== Functions ================================================
    std::string findType(std::string literal) const;
    void print(char c) const;
    void print(int i) const;
    void print(double d) const;
    void print(float f) const;
};

std::ostream & operator<<(std::ostream & o, ConvertScalar const & i);

#endif // CONVERTSCALAR_CLASS_HPP_
