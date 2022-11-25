#ifndef ANIMAL_CLASS_HPP_
# define ANIMAL_CLASS_HPP_

#include <iostream>

class AAnimal {
  protected:
    std::string type;
  public:
    AAnimal(void);
    AAnimal(const AAnimal & src);
    virtual ~AAnimal(void);

    AAnimal & operator=(AAnimal const & rhs);
    std::string getType(void) const;
    virtual void makeSound(void) const = 0;
};

#endif // ANIMAL_CLASS_HPP_
