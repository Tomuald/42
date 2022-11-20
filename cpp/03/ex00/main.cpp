#include "ClapTrap.hpp"

int main(void) {
  ClapTrap one("C1");
  ClapTrap mock("mock");
  ClapTrap two("C2");

  std::cout << one.getName() << " | HP: " << one.getHP() << " | EP: " << one.getEP() << std::endl;
  one.attack(two.getName());
  std::cout << "C1 now has " << one.getEP() << " energy." << std::endl;
  std::cout << "Mock is: " << mock;
  mock = two;
  std::cout << "Mock is now named: " << mock;
  two.beRepaired(10);
  std::cout << two.getName() << " now has " << two.getHP() << " hp" << std::endl;
  two.takeDamage(5);
  std::cout << two.getName() << " now has " << two.getHP() << " hp" << std::endl;
  std::cout << "Mock: " << mock.getName() << " still has " << mock.getHP() << " hp" << std::endl;
  int remain = one.getEP();
  for (int i = 0; i < remain; i++) {
    one.attack("The Blowing Wind");
  }
  one.attack("The Blowing Wind");
  one.beRepaired(5000);
  two.beRepaired(-1);
  two.takeDamage(4294967295);
  return (0);
}
