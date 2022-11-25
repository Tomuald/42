#include <ostream>
#include "Animal.class.hpp"
#include "Cat.class.hpp"
#include "Dog.class.hpp"
#include "WrongAnimal.class.hpp"
#include "WrongCat.class.hpp"

int main(void) {
  const AAnimal * a = new Dog();

  a->makeSound();
  return (0);
}
