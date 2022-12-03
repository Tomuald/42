#include "RobotomyRequestForm.class.hpp"
#include <fstream>

RobotomyRequestForm::RobotomyRequestForm(void) : Form::Form("RobotomyRequestForm", 72, 45), _target("null") {}
RobotomyRequestForm::RobotomyRequestForm(std::string const & target) : Form::Form("RobotomyRequestForm", 145, 137), _target(target) {}
RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src) {*this = src;}
RobotomyRequestForm::~RobotomyRequestForm(void) {}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const & rhs) {
  if (this != &rhs) {
    // ...
  }
  return (*this);
}

// ========== Functions ============================================
bool RobotomyRequestForm::execute(Bureaucrat const & b) const {
  if (b.getGrade() > this->getExecGrade()) {
    throw Form::GradeTooLowException();
  } else if (this->getSignState() == false) {
    throw Form::UnsignedFormException();
  }
  std::cout << "<drilling noises...>" << std::endl;
  std::cout << "Allright " << this->_target << std::endl;
  std::cout << "This procedure usually works 50% of the time, and I've got no f@(&!ng idea if it worked this time!" << std::endl;
  return (true);
}


// ========== Other ================================================
std::ostream & operator<<(std::ostream & o, RobotomyRequestForm const & i) {
  o << "Name: " << i.getName() << std::endl;
  o << "signGrade: " << i.getSignGrade() << std::endl;
  o << "execGrade: " << i.getExecGrade() << std::endl;
  o << "isSigned: " << i.getSignState();
  return (o);
}
