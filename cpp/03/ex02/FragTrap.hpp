#ifndef FRAGTRAP_HPP_
# define FRAGTRAP_HPP_

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
public:
  FragTrap(void);
  FragTrap(std::string name);
  FragTrap(const FragTrap & src);
  ~FragTrap(void);

  FragTrap & operator=(FragTrap const & rhs);

  void highFivesGuys(void);
};

std::ostream & operator<<(std::ostream & o, FragTrap const & i);

#endif // FRAGTRAP_HPP_
