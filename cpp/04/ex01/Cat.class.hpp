#ifndef CAT_CLASS_HPP_
# define CAT_CLASS_HPP_

# include "Animal.class.hpp"
# include "Brain.class.hpp"
# include <ostream>

class Cat : public Animal {
  private:
    const Brain * _brain;
  public:
    Cat(void);
    Cat(const Cat & src);
    virtual ~Cat(void);

    Cat & operator=(Cat const & rhs);

    void makeSound(void) const;
};

std::ostream & operator<<(std::ostream & o, Cat const & i);

#endif // CAT_CLASS_HPP_
