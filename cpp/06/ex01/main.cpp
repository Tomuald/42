#include <iostream>
#include "Data.hpp"

uintptr_t serialize(Data * ptr) {
  uintptr_t raw = reinterpret_cast<uintptr_t>(ptr);
  return (raw);
}

Data * deserialize(uintptr_t raw) {
  Data * data = reinterpret_cast<Data *>(raw);
  return (data);
}

int main(int argc, char **argv) {
  (void) argc;
  (void) argv;
  std::string s = "An awesome string!";
  int n = 4;
  Data * data = new Data;

  data->s = s;
  data->i = n;
  uintptr_t r;
  std::cout << data->s << std::endl;
  std::cout << data->i << std::endl;
  r = serialize(data);

  Data * bla;

  bla = deserialize(r);
  std::cout << bla->s << std::endl;
  std::cout << bla->i << std::endl;
  delete data;
  return (0);
}
