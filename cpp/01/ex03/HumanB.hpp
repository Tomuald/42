#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <string>
#include "Weapon.hpp"

class HumanB {
  private:
    std::string _name;
    Weapon *_weapon;
  public:
    HumanB(std::string name);
    ~HumanB(void);
    void attack(void) const;
    void setWeapon(Weapon &weapon);
    std::string getName(void) const;
};

#endif
