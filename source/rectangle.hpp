#include "window.hpp"
#include "vec2.hpp"
#include "color.hpp"
#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

class Rectangle{
    public:
        Rectangle();
        Rectangle(Vec2 const& min_, Vec2 const& max_, Color col_);
        float const circumference_rect ();
        void const draw( Window const& w);
        void const draw( Window const& w, float thickness);
        bool is_inside_ (const Vec2& point) const;

    private:
        Vec2 min_; 
        Vec2 max_; 
        Color col_; 
};

#endif