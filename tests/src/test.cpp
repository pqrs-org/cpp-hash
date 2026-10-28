#include <boost/ut.hpp>
#include <cstddef>
#include <pqrs/hash.hpp>
#include <string>
#include <utility>
#include <variant>
#include <vector>

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

  "pair"_test = [] {
    std::size_t h1 = 0;
    pqrs::hash::combine(h1,
                        std::pair(100,
                                  std::string("hello")));

    std::size_t h2 = 0;
    pqrs::hash::combine(h2,
                        std::pair(100,
                                  std::string("hello")));

    std::size_t h3 = 0;
    pqrs::hash::combine(h3,
                        std::pair(200,
                                  std::string("hello")));

    expect(h1 == h2);
    expect(h1 != h3);
  };

  "vector"_test = [] {
    std::size_t h1 = 0;
    pqrs::hash::combine(h1,
                        std::vector{
                            100,
                            200,
                        });

    std::size_t h2 = 0;
    pqrs::hash::combine(h2,
                        std::vector{
                            100,
                            200,
                        });

    std::size_t h3 = 0;
    pqrs::hash::combine(h3,
                        std::vector{
                            200,
                            100,
                        });

    expect(h1 == h2);
    expect(h1 != h3);
  };

  "empty_vector"_test = [] {
    std::size_t h = 42;
    pqrs::hash::combine(h,
                        std::vector<int>{});

    expect(h != 42);
  };

  "nested_vector_boundaries"_test = [] {
    std::size_t h1 = 0;
    pqrs::hash::combine(h1,
                        std::vector<std::vector<int>>{
                            {1},
                            {2},
                        });

    std::size_t h2 = 0;
    pqrs::hash::combine(h2,
                        std::vector<std::vector<int>>{
                            {1, 2},
                            {},
                        });

    expect(h1 != h2);
  };

  "vector_bool"_test = [] {
    std::size_t h1 = 0;
    pqrs::hash::combine(h1,
                        std::vector<bool>{
                            true,
                            false,
                        });

    std::size_t h2 = 0;
    pqrs::hash::combine(h2,
                        std::vector<bool>{
                            true,
                            false,
                        });

    expect(h1 == h2);
  };

  "variant"_test = [] {
    using value_t = std::variant<int, std::string>;

    std::size_t h1 = 0;
    pqrs::hash::combine(h1,
                        value_t(100));

    std::size_t h2 = 0;
    pqrs::hash::combine(h2,
                        value_t(100));

    std::size_t h3 = 0;
    pqrs::hash::combine(h3,
                        value_t("hello"));

    expect(h1 == h2);
    expect(h1 != h3);
  };

  "nested"_test = [] {
    using value_t = std::variant<std::vector<std::pair<int, std::string>>, int>;

    value_t value1(std::vector{
        std::pair(100,
                  std::string("hello")),
        std::pair(200,
                  std::string("world")),
    });
    value_t value2(std::vector{
        std::pair(100,
                  std::string("hello")),
        std::pair(200,
                  std::string("world")),
    });

    std::size_t h1 = 0;
    pqrs::hash::combine(h1,
                        value1);

    std::size_t h2 = 0;
    pqrs::hash::combine(h2,
                        value2);

    expect(h1 == h2);
  };

  return 0;
}
