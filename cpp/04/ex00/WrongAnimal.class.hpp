#ifndef WRONGANIMAL_CLASS_HPP_
# define WRONGANIMAL_CLASS_HPP_

#include <ostream>

class WrongAnimal {
  protected:
    std::string type;
  public:
    WrongAnimal(void);
    WrongAnimal(const WrongAnimal & src);
    virtual ~WrongAnimal(void);

    WrongAnimal & operator=(WrongAnimal const & rhs);
    std::string getType(void) const;
    void makeSound(void) const;
};

std::ostream & operator<<(std::ostream & o, WrongAnimal const & i);
#endif // WRONGANIMAL_CLASS_HPP_
