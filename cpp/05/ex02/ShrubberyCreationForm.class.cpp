#include "ShrubberyCreationForm.class.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(void) : Form::Form("ShrubberyCreationForm", 145, 137), _target("null") {}
ShrubberyCreationForm::ShrubberyCreationForm(std::string const & target) : Form::Form("ShrubberyCreationForm", 145, 137), _target(target) {}
ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src) {*this = src;}
ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & rhs) {
  if (this != &rhs) {
    // ...
  }
  return (*this);
}

// ========== Functions ============================================
bool ShrubberyCreationForm::execute(Bureaucrat const & b) const {
  std::ofstream ofs;
  std::string tree =  "          &&& &&  & &&\n      && &\\/&\\|& ()|/ @, &&\n      &\\/(/&/&||/& /_/)_&/_&\n   &() &\\/&|()|/&\\/ '%\" & ()\n  &_\\_&&_\\ |& |&&/&__%_/_& &&\n&&   && & &| &| /& & % ()& /&&\n ()&_---()&\\&\\|&&-&&--%---()~\n     &&     \\|||\n             |||\n             |||\n             |||\n       , -=-~  .-^- _\n";

  if (b.getGrade() > this->getExecGrade()) {
    throw Form::GradeTooLowException();
  } else if (this->getSignState() == false) {
    throw Form::UnsignedFormException();
  }
  ofs.open(this->_target + "_shrubbery");
  if (ofs.is_open()) {
    ofs << tree << std::endl;
    ofs.close();
    return (true);
  }
  return (false);
}

// ========== Other ================================================
std::ostream & operator<<(std::ostream & o, ShrubberyCreationForm const & i) {
  o << "Name: " << i.getName() << std::endl;
  o << "signGrade: " << i.getSignGrade() << std::endl;
  o << "execGrade: " << i.getExecGrade() << std::endl;
  o << "isSigned: " << i.getSignState();
  return (o);
}
