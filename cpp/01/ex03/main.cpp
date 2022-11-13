#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"
#include <iostream>

int main(void) {
  Weapon club = Weapon("a crude club");
  std::cout << club.getType() << std::endl;

  HumanA bob("bob", club);
  bob.attack();
  club.setType("some other type of club");
  bob.attack();
  HumanB jon("jon");
  jon.attack();
  jon.setWeapon(club);
  jon.attack();
  return (0);
}
