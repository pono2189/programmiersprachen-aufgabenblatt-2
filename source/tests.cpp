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
TEST_CASE ("-=","[-=]") {
  Vec2 a; 
  Vec2 b {5.1f , -9.3f};
  Vec2 c {0.523f, 0.9999f};

  a -= b;
  b -= c; 
  c -= c; 

  REQUIRE(Approx(-5.1f) == a.x);  ;
  REQUIRE(Approx(9.3f) == a.y); 
  REQUIRE(Approx(0.0f) == c.x);
  REQUIRE(Approx(0.0f) == c.y);
  REQUIRE(Approx(4.577f) == b.x); 
  //REQUIRE(Approx(-10,2999f) == b.y); ??????

    
}

TEST_CASE ("*=","[*=]") {
  Vec2 a; 
  Vec2 b {5.1f , -9.3f};
  Vec2 c {0.523f, 0.9999f};
  a *= 4.0f;   
  b *= 0.0f;
  c *= -3.0f;

  

  REQUIRE(Approx(0.0f) == a.x);  ;
  REQUIRE(Approx(0.0f) == a.y); 
  REQUIRE(Approx(0.0f) == b.x);
  REQUIRE(Approx(0.0f) == b.y);
  REQUIRE(Approx(-1.569f) == c.x);
  REQUIRE(Approx(-2.9997f) == c.y);
  
}
TEST_CASE ("/=","[/=]") {
  Vec2 a; 
  Vec2 b {5.1f , -9.3f};
  Vec2 c {0.523f, 0.9999f};
  a /= 4.5f;   
  b /= 0.0f;
  c /= -3.0f;

  

  //REQUIRE(Approx(0.0f) == b.x); == error???  ;
  //REQUIRE(Approx(0.0f) == b.y); 
  REQUIRE(Approx(0.0f) == a.x);
  REQUIRE(Approx(0.0f) == a.y);
  REQUIRE(Approx(-0.17433333f) == c.x);
  REQUIRE(Approx(-0.3333f) == c.y);
    
}



int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
