#ifndef FORM_CLASS_HPP_
# define FORM_CLASS_HPP_

#include <iostream>
class Bureaucrat;
#include "Bureaucrat.class.hpp"

class Form {
  private:
    std::string _name;
    bool _isSigned;
    int _signGrade;
    int _execGrade;

  public:
  // ========== Constructors & Destructors ===========================
    Form(std::string const & name, const int signGrade, const int execGrade);
    Form(const Form & src);
    ~Form(void);
  // ========== Functions ============================================
    std::string const & getName(void) const;
    bool getSignState(void) const;
    int getSignGrade(void) const;
    int getExecGrade(void) const;

    void beSigned(Bureaucrat & b);
  // ========== Overloads ============================================
    Form & operator=(Form const & rhs);
  // ========== Exceptions ===========================================
    class GradeTooHighException : public std::exception {
      public:
        virtual const char * what() const throw();
    };
    class GradeTooLowException : public std::exception {
      public:
        virtual const char * what() const throw();
    };
    class AlreadySignedException : public std::exception {
      public:
        virtual const char * what() const throw();
    };
};

std::ostream & operator<<(std::ostream & o, Form const & i);

#endif // FORM_CLASS_HPP_
