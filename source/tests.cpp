#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "vec2.hpp"


// 2.2
TEST_CASE ("vec2","[vec2]") {
  Vec2 a; 
  Vec2 b {5.1f , -9.3f};
    REQUIRE(a.x == 0.0f);
    REQUIRE(a.y == 0.0f);
    REQUIRE(b.x == 5.1f);
    REQUIRE(b.y == -9.3f);
}

// 2.3

TEST_CASE ("+=","[+=]") {
  Vec2 a; 
  Vec2 b {5.1f , -9.3f};
  Vec2 c {0.523f, 0.9999f};

  a += b;
  b += c; 
  c += c; 

  REQUIRE(Approx(5.1f) == a.x); //(5.1f, -9.3f) ;
  REQUIRE(Approx(-9.3f) == a.y); //(5.623f, -8.3001);
  REQUIRE(Approx(1.046f) == c.x);
  REQUIRE(Approx(1.9998f) == c.y);
  REQUIRE(Approx(5.623f) == b.x); 
  REQUIRE(Approx(-8.3001f) == b.y);

    
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
