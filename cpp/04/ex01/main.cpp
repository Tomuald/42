#include <ostream>
#include "Animal.class.hpp"
#include "Cat.class.hpp"
#include "Dog.class.hpp"
#include "WrongAnimal.class.hpp"
#include "WrongCat.class.hpp"

int main(void) {
  Animal *animals[10];

  std::cout << "Creating dogs" << std::endl;
  for (int i = 0; i < 5; i++) {
    animals[i] = new Dog();
  }
  std::cout << "Creating cats" << std::endl;
  for (int i = 5; i < 10; i++) {
    animals[i] = new Cat();
  }
  std::cout << "Deleting everything" << std::endl;
  for (int i = 0; i < 10; i++) {
    delete animals[i];
  }

  std::cout << "Checking deep copy" << std::endl;
  Dog * one = new Dog();
  Dog two = Dog(*one);
  delete one;
  std::cout << "After deleting the pointer, I can still access the copy" << std::endl;
  two.makeSound();
  return (0);
}
