#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "vec2.hpp"
#include "mat2.hpp"
#include "color.hpp"


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

  REQUIRE(Approx(5.1f) == a.x); 
  REQUIRE(Approx(-9.3f) == a.y); 
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

  REQUIRE(Approx(-5.1f) == a.x);  
  REQUIRE(Approx(9.3f) == a.y); 
  REQUIRE(Approx(0.0f) == c.x);
  REQUIRE(Approx(0.0f) == c.y);
  REQUIRE(Approx(4.577f) == b.x); 
  REQUIRE(Approx(-10.2999f) == b.y);

    
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

  REQUIRE(Approx(5.1f) == b.x);
  REQUIRE(Approx(-9.3f) == b.y); 
  REQUIRE(Approx(0.0f) == a.x);
  REQUIRE(Approx(0.0f) == a.y);
  REQUIRE(Approx(-0.17433333f) == c.x);
  REQUIRE(Approx(-0.3333f) == c.y);
    
}

// Aufgabe 2.4
TEST_CASE ("+","[+]") {
  Vec2 a; 
  Vec2 b {5.1f , -9.3f};
  Vec2 c {0.523f, 0.9999f};

  a = a + b;
  b = b + c; 
  c = c + c; 

  REQUIRE(Approx(5.1f) == a.x); 
  REQUIRE(Approx(-9.3f) == a.y); 
  REQUIRE(Approx(1.046f) == c.x);
  REQUIRE(Approx(1.9998f) == c.y);
  REQUIRE(Approx(5.623f) == b.x); 
  REQUIRE(Approx(-8.3001f) == b.y);
}

TEST_CASE ("-","[-]") {
  Vec2 a; 
  Vec2 b {5.1f , -9.3f};
  Vec2 c {0.523f, 0.9999f};

  a = a - b;
  b = b - c; 
  c = c - c; 

  REQUIRE(Approx(-5.1f) == a.x);  
  REQUIRE(Approx(9.3f) == a.y); 
  REQUIRE(Approx(0.0f) == c.x);
  REQUIRE(Approx(0.0f) == c.y);
  REQUIRE(Approx(4.577f) == b.x); 
  REQUIRE(Approx(-10.2999f) == b.y);
}

TEST_CASE ("*","[*]") {
  Vec2 a; 
  Vec2 b {5.1f , -9.3f};
  Vec2 c {0.523f, 0.9999f};
  a = a * 4.0f;   
  b = b * 0.0f;
  c = c * -3.0f;

  REQUIRE(Approx(0.0f) == a.x);  ;
  REQUIRE(Approx(0.0f) == a.y); 
  REQUIRE(Approx(0.0f) == b.x);
  REQUIRE(Approx(0.0f) == b.y);
  REQUIRE(Approx(-1.569f) == c.x);
  REQUIRE(Approx(-2.9997f) == c.y);  
}

TEST_CASE ("/","[/]") {
  Vec2 a; 
  Vec2 b {5.1f , -9.3f};
  Vec2 c {0.523f, 0.9999f};
  a = a / 4.5f;   
  b = b / 0.0f;
  c = c / -3.0f;

  REQUIRE(Approx(0.0f) == b.x);
  REQUIRE(Approx(0.0f) == b.y); 
  REQUIRE(Approx(0.0f) == a.x);
  REQUIRE(Approx(0.0f) == a.y);
  REQUIRE(Approx(-0.17433333f) == c.x);
  REQUIRE(Approx(-0.3333f) == c.y);  
}

// Aufgabe 2.5

//HELP!!!

TEST_CASE ("describe_mat2*=operator","[mat2]") {

  Mat2 a; 
  Mat2 b {5.1f ,-9.3f ,3.2f ,1.2f};
  Mat2 c {0.52f, 0.99f, 0.0f, 4.3f};
  a *= b;   
  b *= c;

  REQUIRE(Approx(5.1f) == a.e_00);  
  REQUIRE(Approx(-9.3f) == a.e_01); 
  REQUIRE(Approx(3.2f) == a.e_10);
  REQUIRE(Approx(1.2f) == a.e_11);

  REQUIRE(Approx(2.65f).epsilon(0.1) == b.e_00);  
  REQUIRE(Approx(-34.94f).epsilon(0.1) == b.e_01); 
  REQUIRE(Approx(1.66f).epsilon(0.1) == b.e_10);
  REQUIRE(Approx(8.33f).epsilon(0.1) == b.e_11);
  
}


TEST_CASE ("describe_mat2*operator","[mat2]") {

  Mat2 a; 
  Mat2 b {5.1f ,-9.3f ,3.2f ,1.2f};
  Mat2 c {0.52f, 0.99f, 0.0f, 4.3f};
  a = a * b;   
  b = b * c;

  REQUIRE(Approx(5.1f).epsilon(0.1) == a.e_00);  
  REQUIRE(Approx(-9.3f).epsilon(0.1) == a.e_01); 
  REQUIRE(Approx(3.2f).epsilon(0.1) == a.e_10);
  REQUIRE(Approx(1.2f).epsilon(0.1) == a.e_11);

  REQUIRE(Approx(2.65f).epsilon(0.1) == b.e_00);  
  REQUIRE(Approx(-34.94f).epsilon(0.1) == b.e_01); 
  REQUIRE(Approx(1.66f).epsilon(0.1) == b.e_10);
  REQUIRE(Approx(8.33f).epsilon(0.1) == b.e_11);
  
}


// Aufgabe 2.6

TEST_CASE ("inverse","[inverse]") {

  Mat2 a; 
  Mat2 b {5.1f ,-9.3f ,3.2f ,1.2f};
  Mat2 inv_a = inverse(a);  
  Mat2 inv_b = inverse(b);

  REQUIRE(Approx(1.0f) == inv_a.e_00);  
  REQUIRE(Approx(0.0f) == inv_a.e_01); 
  REQUIRE(Approx(0.0f) == inv_a.e_10);
  REQUIRE(Approx(1.0f) == inv_a.e_11);

  REQUIRE(Approx(0.03f).epsilon(0.1) == inv_b.e_00);  
  REQUIRE(Approx(0.3f).epsilon(0.1) == inv_b.e_01); 
  REQUIRE(Approx(-0.089f).epsilon(0.1) == inv_b.e_10);
  REQUIRE(Approx(0.1f).epsilon(0.1) == inv_b.e_11);
  
}


TEST_CASE ("transpose","[transpose]") {

  Mat2 a; 
  Mat2 b {5.1f ,-9.3f ,3.2f ,1.2f};
  a = transpose(a);  
  b = transpose(b);

  REQUIRE(Approx(1.0f) == a.e_00);  
  REQUIRE(Approx(0.0f) == a.e_01); 
  REQUIRE(Approx(0.0f) == a.e_10);
  REQUIRE(Approx(1.0f) == a.e_11);

  REQUIRE(Approx(5.1f) == b.e_00);  
  REQUIRE(Approx(3.2f) == b.e_01); 
  REQUIRE(Approx(-9.3f) == b.e_10);
  REQUIRE(Approx(1.2f) == b.e_11);
  
}

TEST_CASE ("make_rotation_mat2","[make_rotation_mat2]") {

  Mat2 a; 
  Mat2 b;
  a = make_rotation_mat2(1.0);  
  b = make_rotation_mat2(5.3);

  REQUIRE(Approx(0.5403f).epsilon(0.1) == a.e_00);  
  REQUIRE(Approx(-0.84147f).epsilon(0.1) == a.e_01); 
  REQUIRE(Approx(0.84147f).epsilon(0.1) == a.e_10);
  REQUIRE(Approx(0.5403f).epsilon(0.1) == a.e_11);

  REQUIRE(Approx(0.55437f).epsilon(0.1) == b.e_00);  
  REQUIRE(Approx(0.83227f).epsilon(0.1) == b.e_01); 
  REQUIRE(Approx(-0.83227f).epsilon(0.1) == b.e_10);
  REQUIRE(Approx(0.55437f).epsilon(0.1) == b.e_11);
  
}

TEST_CASE ("determinante","[determinante]") {
  Mat2 a; 
  Mat2 b {5.1f ,-9.3f ,3.2f ,1.2f};
  float c = a.det();
  float d = b.det();

  REQUIRE(Approx(35.9).epsilon(0.1) == d);
  REQUIRE(Approx(1.0f).epsilon(0.1) == c);  
}

// Aufgabe 2.7

TEST_CASE ("color","[color]") {
  Color a {}; 
  Color b {0.1f ,0.3f ,0.7f};

  REQUIRE(Approx(0.5f).epsilon(0.1) == a.r);
  REQUIRE(Approx(0.5f).epsilon(0.1) == a.g);  
  REQUIRE(Approx(0.5f).epsilon(0.1) == a.b); 

  REQUIRE(Approx(0.1f).epsilon(0.1) == b.r);
  REQUIRE(Approx(0.3f).epsilon(0.1) == b.g);  
  REQUIRE(Approx(0.7f).epsilon(0.1) == b.b); 
}


int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}

