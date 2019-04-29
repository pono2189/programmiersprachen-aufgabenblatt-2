#include "vec2.hpp"

class Rectangle{
    public:
        Rectangle(Vec2 min_, Vec2 max_, float height)
        : m_min_(min_), m_max_(max_), m_height(height){}
    
    private:
        float height {0.0f}; 
}


        