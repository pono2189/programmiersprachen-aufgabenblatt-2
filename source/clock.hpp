# ifndef CLOCK_HPP
# define CLOCK_HPP
# include <cmath>
# include "vec2.hpp"
# include "rectangle.hpp"
# include "window.hpp"
# include "circle.hpp"
# include "mat2.hpp"
# include <GLFW/glfw3.h>
# include <utility>
# include "color.hpp"
# include <vector>

struct NVGcontext;
struct GLFWwindow;

class Clock {

public: 
    
    Clock();
    Clock(Circle const& cir);
    void draw(Window const& win, float thickness = 1.0f) const;
    
};

# endif