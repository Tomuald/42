#include "Zombie.hpp"

void randomChump(std::string name);

int main(void) {
  Zombie *z;

  z = new Zombie("Bob");
  z->announce();
  randomChump("Harriet");
  delete z;
  return (0);
}
