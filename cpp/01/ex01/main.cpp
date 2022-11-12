#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name);

int main(void) {
  Zombie *horde;
  int size;

  size = 20;
  horde = zombieHorde(size, "Horde01");
  for (int i = 0; i < size; i++)
    horde[i].announce();
  delete [] horde;

  size = 3;
  horde = zombieHorde(size, "Horde02");
  for (int i = 0; i < size; i++)
    horde[i].announce();
  delete [] horde;

  return (0);
}
