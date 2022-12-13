#include <iostream>
#include "Base.class.hpp"
#include "A.class.hpp"
#include "B.class.hpp"
#include "C.class.hpp"
#include <cstdlib>
#include <ctime>

Base * generate(void) {
  std::srand(time(NULL));
  int n = rand() % 3 + 1;
  Base * ptr;

  switch (n) {
    case 1:
      std::cout << "Created A." << std::endl;
      ptr = new A();
      return (ptr);
    case 2:
      std::cout << "Created B." << std::endl;
      ptr = new B();
      return (ptr);
    case 3:
      std::cout << "Created C." << std::endl;
      ptr = new C();
      return (ptr);
  }
  return (nullptr);
}

void identify(Base * p) {
  if (dynamic_cast<A *>(p) != NULL) {
    std::cout << "A Identified." << std::endl;
    return ;
  } else if (dynamic_cast<B *>(p) != NULL) {
    std::cout << "B Identified." << std::endl;
    return ;
  } else if (dynamic_cast<C *>(p) != NULL) {
    std::cout << "C Identified." << std::endl;
    return ;
  } else {
    std::cout << "Type not identifiable.";
  }
}

void identify(Base & p) {
  try {
    Base & bsvar = dynamic_cast<A &>(p);
    std::cout << "A Identified" << std::endl;
    (void) bsvar;
  } catch (...) {}
  try {
    Base & bsvar = dynamic_cast<B &>(p);
    std::cout << "B Identified" << std::endl;
    (void) bsvar;
  } catch (...) {}
  try {
    Base & bsvar = dynamic_cast<C &>(p);
    (void) bsvar;
    std::cout << "C Identified" << std::endl;
  } catch (...) {}
}

int main(int argc, char **argv) {
  (void) argc;
  (void) argv;
  Base * b;

  b = generate();
  identify(b);
  identify(*b);
  delete b;
  return (0);
}
