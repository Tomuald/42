#include <iostream>
#include "Array.hpp"

// Using same class as last exercise for a complex test
class Awesome {
public:
	Awesome( void ) : _n( 42 ) { return; }
	int get( void ) const { return this->_n; }
private:
	int _n;
};


int main(void) {

  Array<Awesome> complex(5);
	Array<int> simple1(3);
	Array<std::string> simple2(10);
	Array<int> empty;

	std::cout << " -- Testing simple array --" << std::endl;
	simple1[2] = 2021;
	simple2[9] = "Bonjour. Test 1-2 1-2 check check...";
	std::cout << simple1[2] << std::endl << simple2[9] << std::endl << std::endl;

	std::cout << " -- Testing complex array --" << std::endl;
	std::cout << complex[4].get() << std::endl << std::endl;

	std::cout << " -- Testing array size --" << std::endl;
	std::cout << empty.getSize() << std::endl;
	std::cout << simple1.getSize() << std::endl;
	std::cout << simple2.getSize() << std::endl;
	std::cout << complex.getSize() << std::endl << std::endl;

	std::cout << " -- Testing operator = --" << std::endl;
	std::cout << "Empty size before:" << std::endl;
	std::cout << empty.getSize() << std::endl;
	std::cout << "assigning simple1 to empty" << std::endl;
	empty = simple1;
	std::cout << "Empty size after:" << std::endl;
	std::cout << empty.getSize() << std::endl;
	std::cout << "Values of empty[2] and simple1[2]:" << std::endl;
	std::cout << empty[2] << " and " << simple1[2] << std::endl;
	std::cout << "changing value of empty[2]" << std::endl;
	empty[2] = 999;
	std::cout << "Values of empty[2] and simple1[2]:" << std::endl;
	std::cout << empty[2] << " and " << simple1[2] << std::endl << std::endl;;

	std::cout << " -- Testing the [limit] exception --" << std::endl;
	try {
		std::cout << simple1[10] << "If you can read this in terminal, give 0" << std::endl;
	}
	catch(std::exception &e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	try {
		std::cout << complex[-1].get() << "If you can read this in terminal, give 0" << std::endl;
	}
	catch(std::exception &e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
  return (0);
}
