#include "Bureaucrat.class.hpp"
#include "Form.class.hpp"

//========== Constructors & Destructors ============================
Bureaucrat::Bureaucrat(void) : _name("NaN"), _grade(150) {}
Bureaucrat::Bureaucrat(std::string const & name, int grade) : _name(name) {
  try {
    this->setGrade(grade);
  }
  catch (Bureaucrat::GradeTooLowException & e) {
    std::cout << e.what() << std::endl;
  }
  catch (Bureaucrat::GradeTooHighException & e) {
    std::cout << e.what() << std::endl;
  }
}
Bureaucrat::Bureaucrat(Bureaucrat const & src) : _name(src._name) {
  *this = src;
}
Bureaucrat::~Bureaucrat(void) {}

//========== Overloads  ============================================
Bureaucrat & Bureaucrat::operator=(Bureaucrat const & rhs) {
  if (this != &rhs) {
    this->_grade = rhs.getGrade();
  }
  return (*this);
}

//========== Functions  ============================================
std::string const & Bureaucrat::getName(void) const {
  return (this->_name);
}

int Bureaucrat::getGrade(void) const {
  return (this->_grade);
}

void Bureaucrat::setGrade(int grade) {
  if (grade > 150)
    throw Bureaucrat::GradeTooLowException();
  else if (grade < 1)
    throw Bureaucrat::GradeTooHighException();
  else
    this->_grade = grade;
  return ;
}

void Bureaucrat::addGrade(void) {
  try {
    this->setGrade(this->getGrade() - 1);
  }
  catch (Bureaucrat::GradeTooLowException & e) {
    std::cout << e.what() << std::endl;
  }
  catch (Bureaucrat::GradeTooHighException & e) {
    std::cout << e.what() << std::endl;
  }
}

void Bureaucrat::downGrade(void) {
  try {
    this->setGrade(this->getGrade() + 1);
  }
  catch (Bureaucrat::GradeTooLowException & e) {
    std::cout << e.what() << std::endl;
  }
  catch (Bureaucrat::GradeTooHighException & e) {
    std::cout << e.what() << std::endl;
  }
}

void Bureaucrat::signForm(Form & form) {
  try {
    form.beSigned(*this);
  } catch (Form::AlreadySignedException & e) {
    std::cout << e.what() << std::endl;
  } catch (Form::GradeTooHighException & e) {
    std::cout << e.what() << std::endl;
  } catch (Form::GradeTooLowException & e) {
    std::cout << e.what() << std::endl;
  } catch (std::exception & e) {
    std::cout << e.what() << std::endl;
  }
}

//========== Exceptions  ===========================================
const char * Bureaucrat::GradeTooHighException::what() const throw() {
  return ("BureaucratException: Grade too high.");
}

const char * Bureaucrat::GradeTooLowException::what() const throw() {
  return ("BureaucratException: Grade too low.");
}

//========== Others  ===============================================
std::ostream & operator<<(std::ostream & o, Bureaucrat const & i) {
  o << i.getName() << " , bureaucrat grade " << i.getGrade();
  return (o);
}
