#ifndef WRONGCAT_CLASS_HPP_
# define WRONGCAT_CLASS_HPP_

#include "WrongAnimal.class.hpp"
#include <ostream>

class WrongCat : public WrongAnimal {
  public:
    WrongCat(void);
    WrongCat(const WrongCat & src);
    ~WrongCat(void);

    WrongCat & operator=(WrongCat const & rhs);

    void makeSound(void) const;
};

std::ostream & operator<<(std::ostream & o, WrongCat const & i);
#endif // WRONGCAT_CLASS_HPP_
