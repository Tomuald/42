#ifndef ROBOTOMYREQUESTFORM_CLASS_HPP_
# define ROBOTOMYREQUESTFORM_CLASS_HPP_

#include <iostream>
#include "Form.class.hpp"

class RobotomyRequestForm : public Form {
  private:
    std::string _target;
  public:
    RobotomyRequestForm(void);
    RobotomyRequestForm(std::string const & target);
    RobotomyRequestForm(const RobotomyRequestForm & src);
    virtual ~RobotomyRequestForm(void);

    RobotomyRequestForm & operator=(RobotomyRequestForm const & rhs);

    bool execute(Bureaucrat const & b) const;
    std::string getTarget(void) const;
};

std::ostream & operator<<(std::ostream & o, RobotomyRequestForm const & i);

#endif // ROBOTOMYREQUESTFORM_CLASS_HPP_
