#include <iostream>
#include "Bureaucrat.class.hpp"

int main(int argc, char **argv) {
  (void) argc;
  (void) argv;

  Bureaucrat simple;
  std::cout << simple << std::endl;
  Bureaucrat bob("Bob", 1);
  std::cout << bob << std::endl;
  Bureaucrat high("TooHigh", 0);
  Bureaucrat low("TooLow", 151);
  std::cout << "trying to upgrade Bob" << std::endl;
  bob.addGrade();
  std::cout << bob << std::endl;
  std::cout << "trying to dowgrade Bob" << std::endl;
  bob.downGrade();
  std::cout << bob << std::endl;
  Bureaucrat sheep(bob);
  std::cout << sheep << std::endl;

  return 0;
}
