#include <iostream>
#include "iter.hpp"

template<typename T>
void print(T const & x) {std::cout << x << std::endl; return ;}

int main(void) {
  int array1[] = {0, 1, 2, 3, 4, 5};
  float array2[] = {0.1f, 0.2f, 0.3f, 0.4f, 0.5f};

  iter(array1, 10, print);
  iter(array2, 5, print);
  return (0);
}
