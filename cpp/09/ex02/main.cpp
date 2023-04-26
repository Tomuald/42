#include <iostream>
#include "PmergeMe.class.hpp"
#include <unistd.h>

void print_vector(std::string name, std::vector<int> v);
void print_deque(std::string name, std::deque<int> d);

// nums=$(ruby -e 'puts (1..10).to_a.shuffle[0,10].join(" ")' | tr "\n" " ")
// ./PmergeMe $(echo $nums)
int main(int argc, char *argv[]) {
  if (argc < 2) {
    std::cerr << "usage: ./PmergeMe <Numbers>" << std::endl;
    exit(-1);
  }
  std::string numbers;
  int i = 0;
  while (argv[++i]) {
    numbers.append(argv[i]);
    numbers.append(" ");
  }
  PmergeMe _class(numbers);
  std::clock_t start_time = std::clock();
  print_vector("Before", _class.getVector());
  std::vector<int> sorted_vector = _class.sortVector(_class.getVector(), _class.getVector().size());
  print_vector("After", sorted_vector);
  std::clock_t end_time = std::clock();
  double elapsed_time = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC * 1e6;
  std::cout << "Time to process " << _class.getVector().size() << " elements with std::vector --> " << elapsed_time << " microseconds" << std::endl;

  print_deque("Basic Deque", _class.getDeque());

  start_time = std::clock();
  print_deque("Before", _class.getDeque());
  std::deque<int> sorted_deque = _class.sortDeque(_class.getDeque(), _class.getDeque().size());
  print_deque("After", sorted_deque);
  end_time = std::clock();
  elapsed_time = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC * 1e6;
  std::cout << "Time to process " << _class.getDeque().size() << " elements with std::deque --> " << elapsed_time << " microseconds" << std::endl;


  return 0;
}
