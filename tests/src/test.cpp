#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <iostream>
#include <pqrs/hash.hpp>
#include <string>

TEST_CASE("hash_combine") {
  {
    std::size_t h = 0;

    int i = 100;
    pqrs::hash::combine(h, i);

    REQUIRE(h != 0);
  }
  {
    std::size_t h = 0;

    double d = 100.5;
    pqrs::hash::combine(h, d);

    REQUIRE(h != 0);
  }
  {
    std::size_t h = 0;

    std::string s("hello");
    pqrs::hash::combine(h, s);

    REQUIRE(h != 0);
  }
}
