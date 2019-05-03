#include "circle.hpp"
#include <math.h>


Circle::Circle():
    radius_ {10.0f},
    center_ {1.0f, 1.0f},
    col_ {0.5, 0.5, 0.5}
    {};


Circle::Circle(float radius, Vec2 const& center, Color const& col):
    radius_ {radius}, 
    center_ {center},
    col_ {col}
    {};


float const Circle::circumference(){
    float circum; 
    circum = 2 * radius_ * M_PI; 
    return circum; 
};

void const Circle::draw(Window const& w){
    int stepper = 100;
    for (int i = 0; i<= stepper; i++){ 
        Vec2 a = make_rotation_mat2(2*M_PI/stepper*i) * Vec2{radius_, 0.0f} + center_;
        Vec2 b = make_rotation_mat2(2*M_PI/stepper*(i+1)) * Vec2{radius_, 0.0f} + center_;
        w.draw_line (a.x, a.y, b.x, b.y, 0.5f, 0.5f, 0.5f, 1.0f);
    }
}
void const Circle::draw(Window const& w, float thickness){
    int stepper = 100;
    for (int i = 0; i<= stepper; i++){ 
         float a_x = (float) sin((2*M_PI*i)/360) * radius_ + center_.x;
        float a_y = (float)cos((2*M_1_PI*i)/360) * radius_+ center_.y;
        float b_x = (float) sin(2*M_PI*(i+1)/360)*radius_ + center_.x;
        float b_y = (float)cos(2*M_1_PI*(i+1)/360)*radius_+ center_.y;
        Vec2 a = {a_x, a_y} ;
        Vec2 b = {b_x, b_y} ;
        w.draw_line (a.x, a.y, b.x, b.y, 0.5f, 0.5f, 0.5f, thickness);
    }
}

