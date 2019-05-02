
#include "vec2.hpp"
#include "color.hpp"

class Rectangle{
    public:
        Rectangle();
        Rectangle(Vec2 const& min_, Vec2 const& max_, Color col_);
        float const circumference_rect ();
        //void const draw_rect();
    private:
        Vec2 min_; 
        Vec2 max_; 
        Color col_; 
};
