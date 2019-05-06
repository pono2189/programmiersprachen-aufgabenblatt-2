#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "mat2.hpp"
#include "color.hpp"
#include "circle.hpp"
#include "vec2.hpp"
#include "rectangle.hpp"


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
  Vec2 d = 0.8f * c;

  REQUIRE(Approx(0.0f) == a.x);  ;
  REQUIRE(Approx(0.0f) == a.y); 
  REQUIRE(Approx(0.0f) == b.x);
  REQUIRE(Approx(0.0f) == b.y);
  REQUIRE(Approx(-1.569f) == c.x);
  REQUIRE(Approx(-2.9997f) == c.y);  
  REQUIRE(Approx(d.x) == d.x);  
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

TEST_CASE ("mat*vec","[mat*vec]") {
  Mat2 a; 
  Mat2 b {5.1f ,-9.3f ,3.2f ,1.2f};
  Vec2 c; 
  Vec2 d {5.0f, 3.0f};
  c = a*c;
  d = b*d;

  REQUIRE(Approx(0.0f) == c.x);  
  REQUIRE(Approx(0.0f) == c.y); 
  REQUIRE(Approx(-2.4f) == d.x);
  REQUIRE(Approx(19.6f) == d.y);

  d = d*b;
  REQUIRE(Approx(-2.4f) == d.x);
  REQUIRE(Approx(19.6f) == d.y);
}

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

// Aufgabe 2.9

TEST_CASE ("circumference","[circumference]") {
  Vec2 cen = {0.0f, 0.0f};
  Color col_c; 
  Circle c = {3.5f, cen, col_c};
  Circle d = {1.0f, cen, col_c};

  float a = c.circumference();
  float b = d.circumference();

  REQUIRE(Approx(21.89f).epsilon(0.1) == a);
  REQUIRE(Approx(6.283f).epsilon(0.1) == b);
}

TEST_CASE ("circumference_rect","[circumference_rect]") {
  Vec2 min_c = {3.5f, 5.8};
  Vec2 max_c = {2.0f, 4.6};
  Color col_c; 
  Rectangle c = {min_c, max_c, col_c};
  Rectangle d;

  float a = c.circumference_rect();
  float b = d.circumference_rect();

  REQUIRE(Approx(-5.4f).epsilon(0.1) == a);
  REQUIRE(Approx(4.0f).epsilon(0.1) == b);
}


// Aufgabe 2.13

TEST_CASE ("is_inside_circle","[is_inside_circle]") {
  Vec2 cen_a = {0.0f, 0.0f};
  Vec2 cen_b = {400.0f, 300.0f};
  Vec2 cen_c = {3.0f, 4.0f};
  Color col; 
  Circle a = {3.5f, cen_a, col};
  Circle b = {1.0f, cen_b, col};


  REQUIRE(a.is_inside_(cen_a) == true);
  REQUIRE(b.is_inside_(cen_c) == false);

}

TEST_CASE ("is_inside_rectangle","[is_inside_rectangle]") {
  Vec2 min_a = {3.5f, 5.8};
  Vec2 max_a = {2.0f, 4.6};
  Vec2 min_b = {1.5f, 20.6f};
  Vec2 max_b = {10.4f, 2.6f};
  Color col; 
  Rectangle a = {min_a, max_a, col};
  Rectangle b = {min_b, max_b, col};

  REQUIRE(a.is_inside_({3.5f, 5.8f}) == false);
  REQUIRE(b.is_inside_({1.5f, 3.55f}) == true); 

}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}



