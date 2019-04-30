#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "color.hpp"
#include "vec2.hpp"

class Circle{  
    
    public:
        Circle();
        Circle(float radius, Vec2 const& center, Color col);

    private:
        float m_radius {0.0f}; 
        Vec2 m_center {0.1f, 0.1f};
        Color m_color {0.5, 0.5,0.5};
 

};

#endif