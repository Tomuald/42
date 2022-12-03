#ifndef INTERN_CLASS_HPP_
# define INTERN_CLASS_HPP_

#include <iostream>
#include "Form.class.hpp"

class Intern {
private:
  Form * makeShrubForm(std::string target);
  Form * makeRobotomyForm(std::string target);
  Form * makePardonForm(std::string target);
public:
  Intern(void);
  Intern(const Intern & src);
  ~Intern(void);

  Form * makeForm(std::string form, std::string target);
  Intern & operator=(Intern const & rhs);
};

std::ostream & operator<<(std::ostream & o, Intern const & i);

#endif // INTERN_CLASS_HPP_
