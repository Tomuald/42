#include "RPN.class.hpp"


int main(int argc, char *argv[]) {
  if (argc != 2) {
    std::cerr << "usage: ./RPN '<expression>'" << std::endl;
    return (-1);
  }
  std::string expr(argv[1]);
  RPN rpn(expr);
  rpn.evaluate(argv[1]);
  return 0;
}
