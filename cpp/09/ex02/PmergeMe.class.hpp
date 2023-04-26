#ifndef PMERGEME_CLASS_HPP_
# define PMERGEME_CLASS_HPP_

# include <ctime>
# include <iostream>
# include <string>
# include <istream>
# include <sstream>
# include <cstdlib>
# include <vector>
# include <deque>

class PmergeMe {
public:
  PmergeMe(void);
  PmergeMe(std::string numbers);
  PmergeMe(PmergeMe const & src);
  ~PmergeMe(void);

  // Getters
  std::vector<int> & getVector(void);
  std::deque<int> & getDeque(void);
  // Checkers
  bool isDuplicate(int n) const;
  // Sorting functions
  std::vector<int> sortVector(std::vector<int> & _vector, int size);
  std::deque<int> sortDeque(std::deque<int> & _deque, int size);

  PmergeMe& operator=(PmergeMe const & rhs);

private:
  std::vector<int> _vector;
  std::deque<int> _deque;
};

std::ostream & operator<<(std::ostream & o, PmergeMe const & i);
#endif // PMERGEME_CLASS_HPP_
