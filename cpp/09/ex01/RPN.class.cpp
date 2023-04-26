#include "RPN.class.hpp"

RPN::RPN(void) { return ; }

bool isNumeric(std::string str) {
  if (str >= "0" && str <= "9") {
    return (true);
  }
  return (false);
}

bool isOperator(std::string str) {
  std::string operators = "+-/*";
  if (operators.find(str) != std::string::npos) {
    return (true);
  }
  return (false);
}

int calculate(int x, int y, std::string op) {
  int value;
  if (op == "+") {
    value = x + y;
  } else if (op == "-") {
    value = x - y;
  } else if (op == "/") {
    value = x / y;
  } else if (op == "*") {
    value = x * y;
  } else {
    std::cerr << "Something fucked up" << std::endl;
    exit(-1);
  }
  return (value);
}

RPN::RPN(std::string expression) {
  std::istringstream iss(expression);
  std::string token;
  std::string previous_token;
  int operands = 0;
  int operators = 0;

  while (iss >> token) {
    if (isNumeric(token)) {
      operands++;
    } else if (isOperator(token)) {
      operators++;
    } else {
      std::cerr << "Error: invalid character" << std::endl;
      exit(-1);
    }
    if (previous_token == "0" && token == "/") {
      std::cerr << "Error: division by zero" << std::endl;
      exit(-1);
    }
    previous_token = token;
  }
  if (operands - 1 != operators) {
    std::cerr << "Error: malformed RPN expression" << std::endl;
    exit(-1);
  }
}

void RPN::evaluate(std::string expression) {
  std::istringstream iss(expression);
  std::string token;
  int result = 0;

  while (iss >> token) {
    if (isNumeric(token)) {
      this->_stack.push(token);
    } else if (isOperator(token) && this->_stack.size() >= 2) {
      int x = std::atoi(this->_stack.top().c_str());
      this->_stack.pop();
      int y = std::atoi(this->_stack.top().c_str());
      this->_stack.pop();
      result = calculate(y, x, token);
      std::stringstream ss;
      ss << result;
      this->_stack.push(ss.str());
    } else {
      std::cerr << "Something fucked up" << std::endl;
      exit(-1);
    }
  }
  if (this->_stack.size() == 1) {
    std::cout << this->_stack.top() << std::endl;
  } else {
    std::cerr << "Invalid RPN expression" << std::endl;
  }
}

RPN::RPN(RPN const & src) {
  *this = src;
  return ;
}

RPN::~RPN(void) { return ; }

RPN & RPN::operator=(RPN const & rhs) {
  if (this != &rhs) {
    *this = rhs;
  }
  return (*this);
}

std::ostream & operator<<(std::ostream & o, RPN const & i) {
  o << "Print something";
  (void) i;
  return (o);
}
