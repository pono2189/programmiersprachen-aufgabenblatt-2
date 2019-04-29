#include "vec2.hpp"

class Rectangle{
    public:
        Rectangle(Vec2 min_, Vec2 max_, float height, Color col)
        : m_min_(min_), m_max_(max_), m_height(height), m_col(col) {}
    
    private:
        float height {0.0f}; 
}


        