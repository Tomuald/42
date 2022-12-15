#ifndef SPAN_CLASS_HPP_
# define SPAN_CLASS_HPP_

#include <list>
#include <iostream>

class Span {
  private:
    std::list<int> _array;
    unsigned int _max;
  public:
  //========== Constructors & Destructors ============================
    Span(void);
    Span(unsigned int n);
    Span(const Span & src);
    ~Span(void);
  //========== Overloads  ============================================
    Span & operator=(Span const & rhs);
  //========== Functions  ============================================
    void addNumber(int const n);
    int shortestSpan(void) ;
    int longestSpan(void);
    unsigned int getMax(void) const;
    std::list<int> & getArray(void);
  //========== Exceptions  ===========================================
    class AlreadyFullException : public std::exception {
      public:
        virtual const char * what() const throw() {
          return ("Array is already full.");
        }
    };
    class TooFewNumbersException : public std::exception {
      public:
        virtual const char * what() const throw() {
          return ("Array has too few values for comparison.");
        }
    };
};

std::ostream & operator<<(std::ostream & o, Span & i);

#endif // SPAN_CLASS_HPP_
