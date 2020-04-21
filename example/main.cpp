#include <iostream>
#include <pqrs/hash.hpp>

int main(void) {
  std::size_t h = 0;

  int x = 100;
  pqrs::hash::combine(h, x);
  std::cout << h << std::endl;

  int y = 200;
  pqrs::hash::combine(h, y);
  std::cout << h << std::endl;

  return 0;
}
