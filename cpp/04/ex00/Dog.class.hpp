#ifndef DOG_CLASS_HPP_
# define DOG_CLASS_HPP_

# include "Animal.class.hpp"
# include <ostream>

class Dog : public Animal {
  public:
    Dog(void);
    Dog(const Dog & src);
    virtual ~Dog(void);

    Dog & operator=(Dog const & rhs);

    void makeSound(void) const;
};

std::ostream & operator<<(std::ostream & o, Dog const & i);

#endif // DOG_CLASS_HPP_
