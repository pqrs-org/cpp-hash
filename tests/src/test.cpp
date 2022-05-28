#include <boost/ut.hpp>
#include <iostream>
#include <pqrs/hash.hpp>
#include <string>

int main(void) {
  using namespace boost::ut;
  using namespace boost::ut::literals;

  "hash_combine"_test = [] {
    {
      std::size_t h = 0;

      int i = 100;
      pqrs::hash::combine(h, i);

      expect(h != 0);
    }
    {
      std::size_t h = 0;

      double d = 100.5;
      pqrs::hash::combine(h, d);

      expect(h != 0);
    }
    {
      std::size_t h = 0;

      std::string s("hello");
      pqrs::hash::combine(h, s);

      expect(h != 0);
    }
  };

  return 0;
}
