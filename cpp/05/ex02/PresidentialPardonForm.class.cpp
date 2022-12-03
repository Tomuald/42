#include "PresidentialPardonForm.class.hpp"
#include <fstream>

PresidentialPardonForm::PresidentialPardonForm(void) : Form::Form("PresidentialPardonForm", 25, 5), _target("null") {}
PresidentialPardonForm::PresidentialPardonForm(std::string const & target) : Form::Form("PresidentialPardonForm", 25, 5), _target(target) {}
PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src) {*this = src;}
PresidentialPardonForm::~PresidentialPardonForm(void) {}

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const & rhs) {
  if (this != &rhs) {
    // ...
  }
  return (*this);
}

// ========== Functions ============================================
bool PresidentialPardonForm::execute(Bureaucrat const & b) const {
  if (b.getGrade() > this->getExecGrade()) {
    throw Form::GradeTooLowException();
  } else if (this->getSignState() == false) {
    throw Form::UnsignedFormException();
  }
  std::cout << this->_target << ". You have been pardonned by Zaphod Beeblebrox!" << std::endl;
  return (true);
}
// ========== Other ================================================
std::ostream & operator<<(std::ostream & o, PresidentialPardonForm const & i) {
  o << "Name: " << i.getName() << std::endl;
  o << "signGrade: " << i.getSignGrade() << std::endl;
  o << "execGrade: " << i.getExecGrade() << std::endl;
  o << "isSigned: " << i.getSignState();
  return (o);
}
