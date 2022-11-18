#include "Fixed.hpp"

int main(void) {
  Fixed a;
  Fixed b(10);
  Fixed c(42.42f);
  Fixed d(b);
  Fixed const e(Fixed (5.05f) * Fixed(2));

  a = Fixed(1234.4321f);
  std::cout << "---base numbers---" << std::endl;
  std::cout << "a is " << a << std::endl;
  std::cout << "b is " << b << std::endl;
  std::cout << "c is " << c << std::endl;
  std::cout << "d is " << d << std::endl;
  std::cout << "e is " << e << std::endl;

  std::cout << "---comparison overloads---" << std::endl;
  std::cout << "a > b: " << (a > b) << std::endl;
  std::cout << "a < b: " << (a < b) << std::endl;
  std::cout << "b == b: " << (b == b) << std::endl;
  std::cout << "c != b: " << (a > b) << std::endl;
  std::cout << "b >= d: " << (b >= d) << std::endl;
  std::cout << "b <= d: " << (b <= d) << std::endl;

  std::cout << "---arithmetic overloads---" << std::endl;
  std::cout << "a + b: " << (a + b) << std::endl;
  std::cout << "b - a: " << (b - a) << std::endl;
  std::cout << "a * c: " << (a * c) << std::endl;
  std::cout << "d / b: " << (d / b) << std::endl;
  std::cout << "---incr/decr overloads---" << std::endl;
  std::cout << "pre incremented a: " << ++a << std::endl;
  b++;
  std::cout << "post incremented b: " << b << std::endl;
  std::cout << "---min & max---" << std::endl;
  std::cout << "max: " << Fixed::max(a, b) << std::endl;
  std::cout << "min: " << Fixed::min(a, b) << std::endl;
  return (0);
}
