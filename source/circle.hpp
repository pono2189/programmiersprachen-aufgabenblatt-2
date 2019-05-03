#include "color.hpp"
#include "vec2.hpp"
#include "window.hpp"
#include "mat2.hpp"
#define _USE_MATH_DEFINES
#include <math.h>
#ifndef CIRCLE_HPP
#define CIRCLE_HPP

class Circle{  
    
    public:
        Circle();
        Circle(float radius_, Vec2 const& center_, Color const& col_);
        float const circumference();
        void const draw(Window const& w);
        void const draw(Window const& w, float thickness);
        bool const is_inside_(const Vec2& point);
    
    private:
        float radius_;
        Vec2 center_;
        Color col_; 
       
};
 

#endif


