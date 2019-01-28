#include <iostream>
#include <pqrs/hash.hpp>

int main(void) {
  std::size_t h = 0;

  int x = 100;
  pqrs::hash_combine(h, x);

  int y = 200;
  pqrs::hash_combine(h, y);

  std::cout << h << std::endl;

  return 0;
}
