#include <iostream>
#include "iter.hpp"

template<typename T>
void print(T const & x) {std::cout << x << std::endl; return ;}

int main(void) {
  int array1[] = {0, 1, 2, 3, 4, 5};
  float array2[] = {0.1f, 0.2f, 0.3f, 0.4f, 0.5f};
  std::string array3[] = {"Hello", "World"};

  std::cout << "Array1 <int>" << std::endl;
  iter(array1, 6, print);
  std::cout << "Array2 <float>" << std::endl;
  iter(array2, 5, print);
  std::cout << "Array3 <std::string>" << std::endl;
  iter(array3, 2, print);
  return (0);
}
