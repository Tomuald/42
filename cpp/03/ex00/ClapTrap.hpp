#ifndef CLAPTRAP_H_
# define CLAPTRAP_H_

# include <iostream>

class ClapTrap {
  public:
    ClapTrap(void);
    ClapTrap(std::string name);
    ClapTrap(ClapTrap const & src);
    ~ClapTrap(void);

    ClapTrap & operator=(ClapTrap const & rhs);

    void attack(const std::string & target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

    std::string getName(void) const;
    unsigned int getHP(void) const;
    unsigned int getEP(void) const;
  private:
    std::string _name;
    unsigned int _hitPoints;
    unsigned int _energyPoints;
    unsigned int _attackDamage;
};

std::ostream & operator<<(std::ostream & o, ClapTrap const & i);
#endif // CLAPTRAP_H_
