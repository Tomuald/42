#include <iostream>
#include "Array.hpp"

int main(void) {
	std::cout << "Simple tests" << std::endl;
	Array<int> array_one(10);
	array_one[2] = 42;
	std::cout << array_one[2] << std::endl;

	Array<std::string> array_two(2);
	array_two[0] = "Hello world!";
	std::cout << array_two[0] << std::endl;

	std::cout << "exception tests" << std::endl;
	try {
		array_one[-1] = -42;
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	try {
		array_two[3] = "wrong index!";
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	return (0);
}
