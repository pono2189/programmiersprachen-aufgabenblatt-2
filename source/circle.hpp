#include "color.hpp"
#include "vec2.hpp"
#include "window.hpp"
#ifndef CIRCLE_HPP
#define CIRCLE_HPP

class Circle{  
    
    public:
        Circle();
        Circle(float radius_, Vec2 const& center_, Color const& col_);
        float const circumference();
        //void const draw();
    
    private:
        float radius_;
        Vec2 center_;
        Color col_; 
       
};
 

#endif

