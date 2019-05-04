#include <math.h>
#include "rectangle.hpp"

Rectangle::Rectangle():
    min_ {0.0f, 0.0f},
    max_ {1.0f, 1.0f}, 
    col_ {0.6, 0.5, 0.5}
    {};

Rectangle::Rectangle(Vec2 const& min, Vec2 const& max, Color col):
    min_ {min}, 
    max_ {max}, 
    col_ {col}
    {};

float const Rectangle::circumference_rect (){
    float height = max_.y - min_.y;
    Vec2 max_left = {min_.x, min_.y + height};
    float length = max_.x - min_.x;
    float circum = height * 2 + length * 2; 
    return circum;
}

void const Rectangle::draw (Window const& w){
    w.draw_line(min_.x, min_.y, min_.x, max_.y, 0.5f, 0.5f, 0.5f, 1.0f);
    w.draw_line(min_.x, max_.y, max_.x, max_.y, 0.5f, 0.5f, 0.5f, 1.0f);
    w.draw_line(max_.x, max_.y, max_.x, min_.y, 0.5f, 0.5f, 0.5f, 1.0f);
    w.draw_line(max_.x, min_.y, min_.x, min_.y, 0.5f, 0.5f, 0.5f, 1.0f);
}

void const Rectangle::draw (Window const& w, float thickness){
    w.draw_line(min_.x, min_.y, min_.x, max_.y, 0.5f, 0.5f, 0.5f, thickness);
    w.draw_line(min_.x, max_.y, max_.x, max_.y, 0.5f, 0.5f, 0.5f, thickness);
    w.draw_line(max_.x, max_.y, max_.x, min_.y, 0.5f, 0.5f, 0.5f, thickness);
    w.draw_line(max_.x, min_.y, min_.x, min_.y, 0.5f, 0.5f, 0.5f, thickness);
}

bool Rectangle::is_inside_ (const Vec2& point) const {
    bool rectangle_x;
    bool rectangle_y;
    if ((point.x >= min_.x) && (point.x <= max_.x)) {
        rectangle_x = true;
        }
    if ((point.y >= max_.y) && (point.y <= min_.y)) { 
        rectangle_y = true;
        }
    if ((rectangle_x == true) && (rectangle_y == true)){
        return true;
    }
    else{
        return false;
    }
}
