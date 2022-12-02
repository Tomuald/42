#include "Form.class.hpp"

// ========== Constructors & Destructors ===========================
Form::Form(std::string const & name, int signGrade, int execGrade) : _name(name), _signGrade(signGrade), _execGrade(execGrade) {}
Form::Form(Form const & src) {*this = src;}
Form::~Form(void) {}

// ========== Overloads ============================================
Form & Form::operator=(Form const & rhs) {
  if (this != &rhs) {
    this->_name = rhs.getName();
    this->_signGrade = rhs.getSignGrade();
    this->_execGrade = rhs.getExecGrade();
    this->_isSigned = rhs.getSignState();
  }
  return (*this);
}

// ========== Functions ============================================
std::string const & Form::getName(void) const {
  return (this->_name);
}

bool Form::getSignState(void) const {
  return (this->_isSigned);
}

int Form::getSignGrade(void) const {
  return (this->_signGrade);
}

int Form::getExecGrade(void) const {
  return (this->_execGrade);
}

void Form::beSigned(Bureaucrat & b) {
  if (this->getSignState() == true) {
    throw Form::AlreadySignedException();
  } else if (b.getGrade() <= this->getSignGrade() && b.getGrade() > 0) {
    this->_isSigned = true;
  } else if (b.getGrade() < 1) {
    throw Form::GradeTooHighException();
  } else {
    throw Form::GradeTooLowException();
  }
}

// ========== Exceptions ===========================================
const char * Form::GradeTooHighException::what() const throw() {
  return ("FormException: Grade too high.");
}

const char * Form::GradeTooLowException::what() const throw() {
  return ("FormException: Grade too low.");
}

const char * Form::AlreadySignedException::what() const throw() {
  return ("FormException: Already Signed.");
}

// ========== Other ================================================
std::ostream & operator<<(std::ostream & o, Form const & i) {
  o << "Name: " << i.getName() << std::endl;
  o << "signGrade: " << i.getSignGrade() << std::endl;
  o << "execGrade: " << i.getExecGrade() << std::endl;
  o << "isSigned: " << i.getSignState();
  return (o);
}
