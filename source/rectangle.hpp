
#include "vec2.hpp"
#include "color.hpp"

class Rectangle{
    public:
        Rectangle(Vec2 const& min_, Vec2 const& max_);
    
    private:
        Vec2 min_; 
        Vec2 max_; 
};
