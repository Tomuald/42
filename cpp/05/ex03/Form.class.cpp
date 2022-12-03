#include "Form.class.hpp"

// ========== Constructors & Destructors ===========================
Form::Form(void): _name("default"), _isSigned(0), _signGrade(30), _execGrade(60) {}
Form::Form(std::string const & name, int const signGrade, int const execGrade) : _name(name), _signGrade(signGrade), _execGrade(execGrade) {
  this->_isSigned = false;
}

Form::Form(Form const & src) : _name(src._name), _signGrade(src._signGrade), _execGrade(src._execGrade) {*this = src;}
Form::~Form(void) {}

// ========== Overloads ============================================
Form const & Form::operator=(const Form & rhs) {
  if (this != &rhs) {
    this->_isSigned = rhs._isSigned;
  }
  return (*this);
}

// ========== Functions ============================================
const std::string & Form::getName(void) const {
  return (this->_name);
}

bool const & Form::getSignState(void) const {
  return (this->_isSigned);
}

int const & Form::getSignGrade(void) const {
  return (this->_signGrade);
}

int const & Form::getExecGrade(void) const {
  return (this->_execGrade);
}

std::string Form::getTarget(void) const {
  std::string _temp;
  return (_temp);
}

void Form::beSigned(Bureaucrat & b) {
  if (this->getSignState() == true) {
    std::cout << b.getName() << " could not sign " << this->getName() << " because form already signed" << std::endl;
    throw Form::AlreadySignedException();
  } else if (b.getGrade() <= this->getSignGrade() && b.getGrade() > 0) {
    this->_isSigned = true;
    std::cout << b.getName() << " signed " << this->getName() << std::endl;
  } else if (b.getGrade() < 1) {
    std::cout << b.getName() << " could not sign " << this->getName() << " because grade too high" << std::endl;
    throw Form::GradeTooHighException();
  } else {
    std::cout << b.getName() << " could not sign " << this->getName() << " because grade too low" << std::endl;
    throw Form::GradeTooLowException();
  }
}

bool Form::execute(Bureaucrat const & b) const {
  if (b.getGrade() > this->getSignGrade()) {
    throw Form::GradeTooLowException();
  } else if (this->_isSigned == false) {
    throw Form::UnsignedFormException();
  } else {
    std::cout << b.getName() << " executes form " << this->getName();
    return (true);
  }
  return (false);
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

const char * Form::UnsignedFormException::what() const throw() {
  return ("FormException: Unsigned Form.");
}

// ========== Other ================================================
std::ostream & operator<<(std::ostream & o, Form const & i) {
  o << "Name: " << i.getName() << std::endl;
  o << "signGrade: " << i.getSignGrade() << std::endl;
  o << "execGrade: " << i.getExecGrade() << std::endl;
  o << "isSigned: " << i.getSignState();
  return (o);
}
