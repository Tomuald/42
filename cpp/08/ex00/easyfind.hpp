#ifndef EASYFIND_HPP_
# define EASYFIND_HPP_

# include <iterator>
# include <algorithm>

template<typename T>
int easyfind(T & container, int n) {
  typename T::iterator iter = std::find(container.begin(), container.end(), n);

  if (iter == container.end()) {
    return (0);
  } else {
    return (1);
  }
  return (0);
}
#endif // EASYFIND_HPP_
