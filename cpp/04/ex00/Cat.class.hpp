#ifndef CAT_CLASS_HPP_
# define CAT_CLASS_HPP_

class Cat {
public:
  Cat(void);
  Cat(const Cat & src);
  ~Cat(void);

  Cat & operator=(Cat const & rhs);
};

std::ostream & operator<<(std::ostream & o, Cat const & i);

#endif // CAT_CLASS_HPP_
