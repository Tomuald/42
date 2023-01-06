#include <iostream>
#include "easyfind.hpp"
#include <list>

int main(int argc, char **argv) {
  (void) argc;
  (void) argv;

  std::list<int> list;

  list.push_back(0);
  list.push_back(55);
  list.push_back(170);
  list.push_back(2);
  list.push_back(24);
  list.push_back(18);
  printf("%d\n", easyfind(list, 18));
  printf("%d\n", easyfind(list, 255));
  return (0);
}
