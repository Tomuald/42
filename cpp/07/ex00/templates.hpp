#ifndef TEMPLATES_HPP_
# define TEMPLATES_HPP_

template<typename T>
void swap(T & a, T & b) {
  T tmp;

  tmp = a;
  a = b;
  b = tmp;
}

template<typename T>
T min(T & a, T & b) {
  if (a == b)
    return (b);
  return (a < b ? a : b);
}

template<typename T>
T max(T & a, T & b) {
  if (a == b)
    return (b);
  return (a > b ? a : b);
}

#endif // TEMPLATES_HPP_
