#ifndef FORM_CLASS_HPP_
# define FORM_CLASS_HPP_

#include <iostream>
#include "Bureaucrat.class.hpp"

class Form {
  private:
    std::string const _name;
    bool isSigned;
    int signGrade;
    int execGrade;

  public:
  // ========== Constructors & Destructors ===========================
    Form(void);
    Form(const Form & src);
    ~Form(void);
  // ========== Functions ============================================
    std::string const getName(void) const;
    bool getSignState(void) const;
    int getSignGrade(void) const;
    int getExecGrade(void) const;

    void beSigned(Bureaucrat & b);
  // ========== Overloads ============================================
    Form & operator=(Form const & rhs);
};

std::ostream & operator<<(std::ostream & o, Form const & i);

#endif // FORM_CLASS_HPP_
