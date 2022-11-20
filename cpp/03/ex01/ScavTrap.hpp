#ifndef SCAVTRAP_HPP_
# define SCAVTRAP_HPP_

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
public:
  ScavTrap(void);
  ScavTrap(std::string name);
  ScavTrap(const ScavTrap & src);
  ~ScavTrap(void);

  void attack(const std::string & target);
  void guardGate(void);
  ScavTrap & operator=(ScavTrap const & rhs);
};

std::ostream & operator<<(std::ostream & o, ScavTrap const & i);

#endif // SCAVTRAP_HPP_
