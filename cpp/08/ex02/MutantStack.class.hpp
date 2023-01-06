#ifndef MUTANTSTACK_CLASS_HPP_
# define MUTANTSTACK_CLASS_HPP_
# include <stack>
# include <deque>
# include <iterator>
# include <list>

template <typename T>
class MutantStack : public std::stack<T> {
  public:
  //========== Iterators  ============================================
    typedef typename std::deque<T>::iterator iterator;
  //========== Constructors & Destructors ============================
    MutantStack(void) : std::stack<T>() {};
    MutantStack(const MutantStack & src) : std::stack<T>() { *this = src; }
    virtual ~MutantStack() {};
  //========== Overloads  ============================================
    MutantStack & operator=(MutantStack const & rhs) {std::stack<T>::operator=(rhs); return (*this);};
  //========== Functions  ============================================
    iterator begin() { return (this->c.begin());};
    iterator end() { return (this->c.end());};
  //========== Exceptions  ===========================================
};

#endif // MUTANTSTACK_CLASS_HPP_
