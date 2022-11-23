#include <ostream>
#include "Animal.class.hpp"
#include "Cat.class.hpp"
#include "Dog.class.hpp"
#include "WrongAnimal.class.hpp"
#include "WrongCat.class.hpp"

int main(void) {
  const Animal * meta = new Animal();
  const Animal * j = new Dog();
  const Animal * i = new Cat();
  const WrongAnimal * w = new WrongAnimal();
  const WrongAnimal * c = new WrongCat();

  meta->makeSound();
  j->makeSound();
  i->makeSound();
  w->makeSound();
  c->makeSound();
  delete meta;
  delete i;
  delete j;
  delete w;
  delete c;
  return (0);
}
