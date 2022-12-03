#ifndef FORM_CLASS_HPP_
# define FORM_CLASS_HPP_

#include <iostream>
class Bureaucrat;
#include "Bureaucrat.class.hpp"

class Form {
  private:
    std::string _name;
    bool _isSigned;
    int const _signGrade;
    int const _execGrade;

  public:
  // ========== Constructors & Destructors ===========================
    Form(void);
    Form(std::string const & name, const int signGrade, const int execGrade);
    Form(const Form & src);
    virtual ~Form(void);
  // ========== Functions ============================================
    const std::string & getName(void) const;
    bool const & getSignState(void) const;
    bool const & getExecState(void) const;
    int const & getSignGrade(void) const;
    int const & getExecGrade(void) const;

    void beSigned(Bureaucrat & b);

    virtual bool execute(Bureaucrat const & b) const = 0;
  // ========== Overloads ============================================
    Form const & operator=(Form const & rhs);
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
    class UnsignedFormException : public std::exception {
      public:
        virtual const char * what() const throw();
    };
};

std::ostream & operator<<(std::ostream & o, Form const & i);

#endif // FORM_CLASS_HPP_
