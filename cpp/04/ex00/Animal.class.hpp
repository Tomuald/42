#ifndef ANIMAL_CLASS_HPP_
# define ANIMAL_CLASS_HPP_

class Animal {
public:
  Animal(void);
  Animal(const Animal & src);
  ~Animal(void);

  Animal & operator=(Animal const & rhs);
};

std::ostream & operator<<(std::ostream & o, Animal const & i);

#endif // ANIMAL_CLASS_HPP_
