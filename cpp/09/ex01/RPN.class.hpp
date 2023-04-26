#ifndef RPN_CLASS_HPP_
# define RPN_CLASS_HPP_

# include <iostream>
# include <stack>
# include <string>
# include <istream>
# include <sstream>
# include <cstdlib>

class RPN {
public:
  RPN(void);
  RPN(std::string expression);
  RPN(RPN const & src);
  ~RPN(void);

  void evaluate(std::string expression);

  RPN& operator=(RPN const & rhs);

private:
  std::stack<std::string> _stack;
};

std::ostream & operator<<(std::ostream & o, RPN const & i);
#endif // RPN_CLASS_HPP_
