#ifndef PRESIDENTIALPARDONFORM_CLASS_HPP_
# define PRESIDENTIALPARDONFORM_CLASS_HPP_

#include <iostream>
#include "Form.class.hpp"

class PresidentialPardonForm : public Form {
  private:
    std::string _target;
  public:
    PresidentialPardonForm(void);
    PresidentialPardonForm(std::string const & target);
    PresidentialPardonForm(const PresidentialPardonForm & src);
    virtual ~PresidentialPardonForm(void);

    PresidentialPardonForm & operator=(PresidentialPardonForm const & rhs);

    bool execute(Bureaucrat const & b) const;
    std::string getTarget(void) const;
};

std::ostream & operator<<(std::ostream & o, PresidentialPardonForm const & i);

#endif // PRESIDENTIALPARDONFORM_CLASS_HPP_
