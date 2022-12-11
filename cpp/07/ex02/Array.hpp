#ifndef ARRAY_HPP_
# define ARRAY_HPP_
# include <iostream>

template <typename T>
class Array {
  private:
    T * _array;
    unsigned int _size;
  public:
  //========== Constructors & Destructors ============================
    Array(void) : _array(NULL), _size(0) {}
    Array(unsigned int n) : _array(new T[n]), _size(n) {}
    Array(const Array & src) :_array(NULL) { *this = src; }
    ~Array(void) { delete[] _array; }
  //========== Overloads  ============================================
    Array & operator=(Array & rhs) {
      if (this == &rhs)
        return (*this);
      delete[] _array;
      this->_array = new T[rhs.getSize()];
      this->_size = rhs.getSize();
      for (unsigned int i = 0; i < _size; i++) {
        this->_array[i] = rhs._array[i];
      }
      return (*this);
    }

    T & operator[](unsigned int i) const {
      if (i < 0 || i > this->getSize()) {
        throw InvalidIndexException();
      }
      return (this->_array[i]);
    }
  //========== Functions  ============================================
    unsigned int getSize(void) const { return (this->_size); }
  //========== Exceptions  ===========================================
  class InvalidIndexException : public std::exception {
    public:
      const char * what() const throw() {
        return ("Invalid Index: Index Out of Range.");
      };
  };
};

template<typename T>
std::ostream & operator<<(std::ostream & o, Array<T> const & i);

#endif // ARRAY_HPP_
