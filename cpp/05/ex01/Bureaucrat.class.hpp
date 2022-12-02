#ifndef BUREAUCRAT_CLASS_HPP_
# define BUREAUCRAT_CLASS_HPP_

#include <iostream>
#include <stdexcept>

class Bureaucrat {
  private:
    std::string const _name;
    int _grade;
  public:
  //========== Constructors & Destructors ============================
    Bureaucrat(void);
    Bureaucrat(std::string const & name, int grade);
    Bureaucrat(const Bureaucrat & src);
    ~Bureaucrat(void);
  //========== Overloads  ============================================
    Bureaucrat & operator=(Bureaucrat const & rhs);
  //========== Functions  ============================================
    std::string const & getName(void) const;
    int getGrade(void) const;
    void setGrade(int grade);
    void addGrade(void);
    void downGrade(void);
  //========== Exceptions  ===========================================
    class GradeTooHighException : public std::exception {
      public:
        virtual const char * what() const throw();
    };
    class GradeTooLowException : public std::exception {
      public:
        virtual const char * what() const throw();
    };
};

std::ostream & operator<<(std::ostream & o, Bureaucrat const & i);

#endif // BUREAUCRAT_CLASS_HPP_
