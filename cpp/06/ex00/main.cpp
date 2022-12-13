#include <iostream>
#include "ConvertScalar.class.hpp"

int main(int argc, char **argv) {
  if (argc != 2) {
    std::cerr << "Usage: ./convert <string literal>" << std::endl;
    return (-1);
  }
  ConvertScalar s;
  std::string literal;
  std::string type;

  literal = static_cast<std::string>(argv[1]);
  type = s.findType(literal);
  if (type == "float") {
    float f = std::atof(literal.c_str());
    s.print(f);
  } else if (type == "int") {
    int i = std::atoi(literal.c_str());
    s.print(i);
  } else if (type == "char") {
    char c = literal.at(0);
    s.print(c);
  } else if (type == "double") {
    double d = static_cast<double>(std::atof(literal.c_str()));
    s.print(d);
  } else {
    std::cout << "Invalid character input" << std::endl;
  }
  return (0);
}
