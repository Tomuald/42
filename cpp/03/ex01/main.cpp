#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void) {
  ScavTrap scavOne;
  ScavTrap scavTwo("Scavicinius");
  ClapTrap C1("C1");

  scavOne.guardGate();
  scavOne.guardGate();
  scavOne.guardGate();
  scavTwo.attack(C1.getName());
  C1.takeDamage(20);
  std::cout << "C1 has: " << C1.getHP() << " hp" << std::endl;
  C1.attack(scavTwo.getName());
  scavTwo.attack(scavOne.getName());
  scavOne.takeDamage(150);
  scavOne.attack(scavTwo.getName());
  scavOne.guardGate();
  scavOne.beRepaired(10);
  std::cout << "This is the intended functionality. The msg gets called from the parent class." << std::endl;
  return (0);
}
