#ifndef CONVERTSCALAR_CLASS_HPP_
# define CONVERTSCALAR_CLASS_HPP_

#include <iostream>

class ConvertScalar {
  public:
    ConvertScalar(void);
    ConvertScalar(char *literal);
    ConvertScalar(const ConvertScalar & src);
    ~ConvertScalar(void);

    //===== Functions ================================================
    std::string findType(std::string literal) const;
    void print(char c) const;
    void print(int i) const;
    void print(double d) const;
    void print(float f) const;
};

#endif // CONVERTSCALAR_CLASS_HPP_
