#include <ostream>
#include "Animal.class.hpp"
#include "Cat.class.hpp"
#include "Dog.class.hpp"

int main(void) {
  Animal a1;
  Cat c1;
  Dog d1;

  a1.makeSound();
  c1.makeSound();
  d1.makeSound();
  return (0);
}
