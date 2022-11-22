#include <iostream>
#include "FragTrap.hpp"

int main(void) {
  FragTrap fg1;
  FragTrap fg2("Bob");

  fg1.highFivesGuys();
  fg1.attack("Another FragTrap!");
  return (0);
}
