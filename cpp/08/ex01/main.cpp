#include <iostream>
#include "Span.class.hpp"
#include <time.h>

#define MAX_VAL 25

void print(int i) { std::cout << i << std::endl; }

int main(int argc, char **argv) {
  (void) argc;
  (void) argv;
  Span s(MAX_VAL);

  srand(time(NULL));
  for (unsigned int i = 0; i < MAX_VAL; i++) {
    try {
      s.addNumber(static_cast<int>(rand()));
    } catch (Span::AlreadyFullException & e) {
      std::cout << e.what() << std::endl;
    }
  }
  std::cout << "=== Printing array ===" << std::endl;
  s.getArray().sort();
  //for_each(s.getArray().begin(), s.getArray().end(), print);
  std::cout << s << std::endl;
  std::cout << "======================" << std::endl;
  std::cout << "Array filled. Trying to add one extra." << std::endl;
  try {
    s.addNumber(-1);
  } catch (Span::AlreadyFullException & e) {
    std::cout << e.what() << std::endl;
  }
  std::cout << "Trying to retrieve shortest span" << std::endl;
  try {
    std::cout << "Short span: " << s.shortestSpan() << std::endl;
  } catch (Span::TooFewNumbersException & e) {
    std::cout << e.what() << std::endl;
  }
  std::cout << "Trying to retrieve longest span" << std::endl;
  try {
    std::cout << "Long span: " << s.longestSpan() << std::endl;
  } catch (Span::TooFewNumbersException & e) {
    std::cout << e.what() << std::endl;
  }
  return (0);
}
