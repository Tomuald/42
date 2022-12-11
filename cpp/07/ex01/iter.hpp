#ifndef ITER_HPP_
# define ITER_HPP_

template<typename T>
void iter(T * array, unsigned int size, void(*f)(T const &)) {
  if (!array)
    return ;
  unsigned int i = 0;
  while (i < size)
    f(array[i++]);
  return;
}

#endif // ITER_HPP_
