#include <iostream>
#include "Bureaucrat.class.hpp"
#include "Form.class.hpp"

int main(int argc, char **argv) {
  (void) argc;
  (void) argv;

  Form f("Basic Form", 15, 1);
  Bureaucrat b("Bob", 150);

  b.signForm(f);
  return 0;
}
