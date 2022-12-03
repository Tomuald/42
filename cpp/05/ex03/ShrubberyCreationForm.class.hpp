#ifndef SHRUBBERYCREATIONFORM_CLASS_HPP_
# define SHRUBBERYCREATIONFORM_CLASS_HPP_

#include <iostream>
#include "Form.class.hpp"

class ShrubberyCreationForm : public Form {
  private:
    std::string _target;
  public:
    ShrubberyCreationForm(void);
    ShrubberyCreationForm(std::string const & target);
    ShrubberyCreationForm(const ShrubberyCreationForm & src);
    virtual ~ShrubberyCreationForm(void);

    ShrubberyCreationForm & operator=(ShrubberyCreationForm const & rhs);

    bool execute(Bureaucrat const & b) const;
    std::string getTarget(void) const;
};

std::ostream & operator<<(std::ostream & o, ShrubberyCreationForm const & i);

#endif // SHRUBBERYCREATIONFORM_CLASS_HPP_
