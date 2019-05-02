#include "circle.hpp"
#include "color.hpp"
#include <math.h>

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

/*void const Circle::draw(Window w){

}
*/
