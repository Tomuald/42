#include <iostream>
#include "Bureaucrat.class.hpp"
#include "Form.class.hpp"
#include "ShrubberyCreationForm.class.hpp"
#include "RobotomyRequestForm.class.hpp"
#include "PresidentialPardonForm.class.hpp"
#include "Intern.class.hpp"

int main(int argc, char **argv) {
  (void) argc;
  (void) argv;

  Intern bootlicker1;
  Form * rff;
  Bureaucrat b("PencilPusher#1", 150);

  rff = bootlicker1.makeForm("ShrubberyCreationForm", "Some Random Garden");
  std::cout << rff->getName() << " targets: " << rff->getTarget() << std::endl;
  b.signForm(*rff);
  b.executeForm(*rff);
  delete rff;
  rff = bootlicker1.makeForm("RobotomyRequestForm", "Some Random Hobo");
  std::cout << rff->getName() << " targets: " << rff->getTarget() << std::endl;
  delete rff;
  rff = bootlicker1.makeForm("PresidentialpardonForm", "Some Random Hobo");
  std::cout << rff->getName() << " targets: " << rff->getTarget() << std::endl;
  delete rff;
  return 0;
}
