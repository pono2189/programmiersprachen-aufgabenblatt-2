#include <math.h>
#include "rectangle.hpp"

Rectangle::Rectangle(){
    min_ = Vec2 {0.0f, 0.0f};
    max_ = Vec2 {1.0f, 1.0f}; 
    Color col {0.6, 0.5, 0.5};
}

Rectangle::Rectangle(Vec2 const& min, Vec2 const& max, Color col){
    min_ = min; 
    max_ = max; 
    col_ = col;
}

float const Rectangle::circumference_rect (){
    float height = max_.y - min_.y;
    Vec2 max_left{min_.x, min_.y + height};
    float length = max_.x - min_.x;
    float circum = height * 2 + length * 2; 
    return circum;
}
/*void const Rectangle::draw (Window w){

}*/
