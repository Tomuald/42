#ifndef DOG_CLASS_HPP_
# define DOG_CLASS_HPP_

class Dog {
public:
  Dog(void);
  Dog(const Dog & src);
  ~Dog(void);

  Dog & operator=(Dog const & rhs);
};

std::ostream & operator<<(std::ostream & o, Dog const & i);

#endif // DOG_CLASS_HPP_
