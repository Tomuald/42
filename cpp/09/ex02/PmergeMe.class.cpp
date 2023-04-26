#include "PmergeMe.class.hpp"

// forward declarations
void print_vector(std::string name, std::vector<int> v);

bool PmergeMe::isDuplicate(int n) const {
  std::vector<int>::const_iterator itv;
  for (itv = this->_vector.begin(); itv != this->_vector.end(); ++itv) {
    if (n == *itv) {
      std::cerr << "Error: duplicate number" << std::endl;
      return (true);
    }
  }

  std::deque<int>::const_iterator itq;
  for (itq = this->_deque.begin(); itq != this->_deque.end(); ++itq) {
    if (n == *itq) {
      std::cerr << "Error: duplicate number" << std::endl;
      return (true);
    }
  }
  return (false);
}

PmergeMe::PmergeMe(void) { return ; }

PmergeMe::PmergeMe(std::string numbers) {
  std::istringstream iss(numbers);
  std::string token;

  while (iss >> token) {
    int n = std::atoi(token.c_str());
    if ((n == 0 && token != "0") || n < 0 || this->isDuplicate(n)) {
      std::cerr << "Error: invalid input" << std::endl;
      exit(-1);
    }
    this->_vector.push_back(n);
    this->_deque.push_back(n);
  }
}

PmergeMe::PmergeMe(PmergeMe const & src) {
  *this = src;
  return ;
}

PmergeMe::~PmergeMe(void) { return ; }

std::vector<int> & PmergeMe::getVector(void) {
  return (this->_vector);
}

std::deque<int> & PmergeMe::getDeque(void) {
  return (this->_deque);
}

std::vector<int> mergeVector(std::vector<int> left, std::vector<int> right) {
  std::vector<int> result;
  size_t i = 0, j = 0;

  while (i < left.size() && j < right.size()) {
    if (left[i] <= right[j]) {
      result.push_back(left[i]);
      i++;
    } else {
      result.push_back(right[j]);
      j++;
    }
  }
  while (i < left.size()) {
    result.push_back(left[i]);
    i++;
  }
  while (j < right.size()) {
    result.push_back(right[j]);
    j++;
  }
  return (result);
}

std::vector<int> PmergeMe::sortVector(std::vector<int> & _vector, int size) {
  if (size <= 1) {
    return (_vector);
  } else if (size == 2) {
    if (_vector[0] > _vector[1]) {
      std::swap(_vector[0], _vector[1]);
    }
    return (_vector);
  } else {
    int mid = size / 2;
    std::vector<int> left(_vector.begin(), _vector.begin() + mid);
    left = sortVector(left, left.size());
    std::vector<int> right(_vector.begin() + mid, _vector.end());
    right = sortVector(right, right.size());
    std::vector<int> merged = mergeVector(left, right);
    return (merged);
  }
}

std::deque<int> mergeDeque(std::deque<int> left, std::deque<int> right) {
  std::deque<int> result;
  size_t i = 0, j = 0;

  while (i < left.size() && j < right.size()) {
    if (left[i] <= right[j]) {
      result.push_back(left[i]);
      i++;
    } else {
      result.push_back(right[j]);
      j++;
    }
  }
  while (i < left.size()) {
    result.push_back(left[i]);
    i++;
  }
  while (j < right.size()) {
    result.push_back(right[j]);
    j++;
  }
  return (result);
}

std::deque<int> PmergeMe::sortDeque(std::deque<int> & _deque, int size) {
  if (size <= 1) {
    return (_deque);
  } else if (size == 2) {
    if (_deque[0] > _deque[1]) {
      std::swap(_deque[0], _deque[1]);
    }
    return (_deque);
  } else {
    int mid = size / 2;
    std::deque<int> left(_deque.begin(), _deque.begin() + mid);
    left = sortDeque(left, left.size());
    std::deque<int> right(_deque.begin() + mid, _deque.end());
    right = sortDeque(right, right.size());
    std::deque<int> merged = mergeDeque(left, right);
    return (merged);
  }
}

PmergeMe & PmergeMe::operator=(PmergeMe const & rhs) {
  if (this != &rhs) {
    //
  }
  return (*this);
}

std::ostream & operator<<(std::ostream & o, PmergeMe & i) {
  std::vector<int>::iterator it;
  for (it = i.getVector().begin(); it != i.getVector().end(); ++it) {
    o << *it << " ";
  }
  return (o);
}

void print_vector(std::string name, std::vector<int> v) {
  std::vector<int>::iterator it;
  std::cout << name << ": ";
  for (it = v.begin(); it != v.end(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
}


void print_deque(std::string name, std::deque<int> d) {
  std::deque<int>::iterator it;
  std::cout << name << ": ";
  for (it = d.begin(); it != d.end(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
}
