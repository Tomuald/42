#include <iostream>
#include "Bureaucrat.class.hpp"
#include "Form.class.hpp"

int main(int argc, char **argv) {
  (void) argc;
  (void) argv;

  Form form1("Basic Form", 15, 1);
  Bureaucrat bob("Bob", 150);
  Form form2("Another Basic Form", 150, 150);
  Bureaucrat fail("Should Fail", -1);

  bob.signForm(form1);
  bob.signForm(form2);
  std::cout << form1 << std::endl;
  std::cout << form2 << std::endl;
  return 0;
}
