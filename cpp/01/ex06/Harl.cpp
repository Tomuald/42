#include "Harl.hpp"

Harl::Harl(void) {
  return ;
}

Harl::~Harl(void) {
  return ;
}

void Harl::complain(std::string level) {
  static const int numlevels = 4;
  int i = 0;
  std::string type[numlevels] = {
    "DEBUG",
    "INFO",
    "WARNING",
    "ERROR"
  };
  void (Harl::*functions[numlevels])(void) = {
    &Harl::debug,
    &Harl::info,
    &Harl::warning,
    &Harl::error
  };

  while (i < numlevels) {
    if (type[i].compare(level) == 0)
      break ;
    i++;
  }
  switch (i) {
    case 0:
      (this->*functions[i++])();
    case 1:
      (this->*functions[i++])();
    case 2:
      (this->*functions[i++])();
    case 3:
      (this->*functions[i++])();
      break ;
    default:
      std::cerr << "Invalid level of complaining." << std::endl;
  }
}

void Harl::debug() {
	std::cout
		<< "[ DEBUG ]\n"
		<< "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger."
		<< " I just love it!"
		<< std::endl;
}

void Harl::info() {
	std::cout
		<< "[ INFO ]\n"
		<< "I cannot believe adding extra bacon cost more money."
		<< " You don’t put enough!"
		<< " If you did I would not have to ask for it!"
		<< std::endl;
}

void Harl::warning() {
	std::cout
		<< "[ WARNING ]\n"
		<< "I think I deserve to have some extra bacon for free."
		<< " I’ve been coming here for years and you just started working here last month."
		<< std::endl;
}

void Harl::error() {
	std::cout
		<< "[ ERROR ]\n"
		<< "This is unacceptable, I want to speak to the manager now."
		<< std::endl;
}
