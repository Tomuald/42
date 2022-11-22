#ifndef ANIMAL_CLASS_HPP_
# define ANIMAL_CLASS_HPP_

#include <iostream>

class Animal {
  protected:
    std::string type;
  public:
    Animal(void);
    Animal(const Animal & src);
    ~Animal(void);

    Animal & operator=(Animal const & rhs);
    std::string getType(void) const;
    void makeSound(void) const;
};

std::ostream & operator<<(std::ostream & o, Animal const & i);

#endif // ANIMAL_CLASS_HPP_
