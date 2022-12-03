#include "Intern.class.hpp"
#include "ShrubberyCreationForm.class.hpp"
#include "RobotomyRequestForm.class.hpp"
#include "PresidentialPardonForm.class.hpp"

std::string lowerString(std::string str);

Intern::Intern(void) {}
Intern::Intern(Intern const & src) {*this = src;}
Intern::~Intern(void) {}

Intern & Intern::operator=(Intern const & rhs) {
  if (this != &rhs) {
    // ...
  }
  return (*this);
}

Form * Intern::makeShrubForm(std::string target) {
  Form *form;

  form = new ShrubberyCreationForm(target);
  return (form);
}

Form * Intern::makeRobotomyForm(std::string target) {
  Form *form;

  form = new RobotomyRequestForm(target);
  return (form);
}

Form * Intern::makePardonForm(std::string target) {
  Form *form;

  form = new PresidentialPardonForm(target);
  return (form);
}

Form * Intern::makeForm(std::string form, std::string target) {
  Form * requestedForm;

  std::string forms[3] = {
    "shrubberycreationform",
    "robotomyrequestform",
    "presidentialpardonform"
  };
  Form * (Intern::*functions[3])(std::string target) = {
    &Intern::makeShrubForm,
    &Intern::makeRobotomyForm,
    &Intern::makePardonForm
  };
  int i = 0;
  while (i < 3) {
    if (forms[i].compare(lowerString(form)) == 0) {
      requestedForm = (this->*functions[i])(target);
      std::cout << "Intern creates " << requestedForm->getName() << std::endl;
      break ;
    }
    i++;
  }
  if (i == 3) {
    std::cerr << "Could not create form" << std::endl;
    return (nullptr);
  }
  return (requestedForm);
}
