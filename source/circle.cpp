#include "circle.hpp"


Circle::Circle(){
    radius_ = 1; 
    center_ = Vec2 {1.9f, 1.0f};
    col_ = {0.5, 0.5}; 
}
Circle::Circle(float radius, Vec2 const& center, Color const& col){
    radius_ = radius; 
    center_ = center;
    col_ = col; 
}

float const Circle::circumference(){
    float circum; 
    circum = 2 * radius_ * M_PI; 
    return circum; 
};

void const Circle::draw(Window const& w){
    int stepper = 100;
    for (int i = 0; i<= stepper; i++){ 
        Vec2 a = make_rotation_mat2(M_PI) * Vec2 {radius_, 0.0f} + center_;
        Vec2 b = make_rotation_mat2(M_PI+ 0.5f) * Vec2 {radius_, 0.0f} + center_;
        w.draw_line (a.x, a.y, b.x, b.y, 0.5f, 0.5f, 0.5f, 7.0f);
    }
}

