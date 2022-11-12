#include <iostream>

int main(void) {
  std::string string = "HI THIS IS BRAIN";
  std::string *stringPTR;
  std::string &stringREF = string;

  stringPTR = &string;

  std::cout << "Addr of string: " << &string << std::endl;
  std::cout << "Addr of stringPTR: " << stringPTR << std::endl;
  std::cout << "Addr of stringREF: " << &stringREF << std::endl;

  std::cout << "Value of string: " << string << std::endl;
  std::cout << "Value of stringPTR: " << *stringPTR << std::endl;
  std::cout << "Value of stringREF: " << stringREF << std::endl;

  return (0);
}
