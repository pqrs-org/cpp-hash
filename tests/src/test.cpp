#include <boost/ut.hpp>
#include <cstddef>
#include <pqrs/hash.hpp>
#include <string>

int main() {
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
    {
      std::size_t h1 = 0;
      pqrs::hash::combine(h1, 100);
      pqrs::hash::combine(h1, 200);

      std::size_t h2 = 0;
      pqrs::hash::combine(h2, 100);
      pqrs::hash::combine(h2, 200);

      expect(h1 == h2);
    }
    {
      std::size_t h1 = 0;
      pqrs::hash::combine(h1, 100);
      pqrs::hash::combine(h1, 200);

      std::size_t h2 = 0;
      pqrs::hash::combine(h2, 200);
      pqrs::hash::combine(h2, 100);

      expect(h1 != h2);
    }
    {
      std::size_t h1 = 0;
      pqrs::hash::combine(h1, 100);

      std::size_t h2 = 42;
      pqrs::hash::combine(h2, 100);

      expect(h1 != h2);
    }
  };

  return 0;
}
