#include <iostream>
#include "Bureaucrat.class.hpp"
#include "Form.class.hpp"
#include "ShrubberyCreationForm.class.hpp"
#include "RobotomyRequestForm.class.hpp"
#include "PresidentialPardonForm.class.hpp"

int main(int argc, char **argv) {
  (void) argc;
  (void) argv;

  ShrubberyCreationForm form1("TheGarden");
  Bureaucrat FarmerJon("FarmerJon", 137);

  FarmerJon.executeForm(form1);
  std::cout << form1 << std::endl;
  FarmerJon.signForm(form1);
  FarmerJon.executeForm(form1);

  std::cout << "\n=====\n" << std::endl;

  Bureaucrat SketchyScientist("SketchyScientist", 45);
  Bureaucrat fail1("Janitor", 150);
  RobotomyRequestForm form2("UnsuspectingHobo");

  fail1.signForm(form2);
  SketchyScientist.signForm(form2);
  SketchyScientist.executeForm(form2);
  std::cout << form2 << std::endl;

  std::cout << "\n=====\n" << std::endl;

  Bureaucrat Zaphod("Zaphod Beeblebrox", 1);
  PresidentialPardonForm form3("Zaphod Beeblebrox");
  std::cout << form3 << std::endl;
  fail1.executeForm(form3);
  Zaphod.signForm(form3);
  Zaphod.executeForm(form3);

  return 0;
}
