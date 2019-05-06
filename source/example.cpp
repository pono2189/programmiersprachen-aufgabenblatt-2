#include "window.hpp"
#include <GLFW/glfw3.h>
#include <utility>
#include <cmath>
#include "rectangle.hpp"
#include "mat2.hpp"
#include "circle.hpp"
#include "vec2.hpp"
#include "color.hpp"
#include <vector>
#include <array>


int main(int argc, char* argv[])
{
  Window win{std::make_pair(800,800)};

  while (!win.should_close()) {
    
    if (win.get_key(GLFW_KEY_ESCAPE) == GLFW_PRESS) {
      win.close();
    }


    bool left_pressed = win.get_mouse_button(GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS;

    auto t = win.get_time();

    float x1 = 400.f + 380.f * std::sin(t);
    float y1 = 400.f + 380.f * std::cos(t);

    float x2 = 400.f + 380.f * std::sin(2.0f*t);
    float y2 = 400.f + 380.f * std::cos(2.0f*t);

    float x3 = 400.f + 380.f * std::sin(t-10.f);
    float y3 = 400.f + 380.f * std::cos(t-10.f);

    win.draw_point(x1, y1, 1.0f, 0.0f, 0.0f);
    win.draw_point(x2, y2, 0.0f, 1.0f, 0.0f);
    win.draw_point(x3, y3, 0.0f, 0.0f, 1.0f);

    auto mouse_position = win.mouse_position();
    if (left_pressed) {
      win.draw_line(30.0f, 30.0f, // FROM pixel idx with coords (x=30, y=30)
                    mouse_position.first, mouse_position.second, // TO mouse position in pixel coords
                    1.0,0.0,0.0, // color with r,g,b in [0.0, 1.0]
                    1.0);        // line thickness = 1.0 * default thickness
    }

    win.draw_line(0, mouse_position.second, 10, mouse_position.second, 0.0, 0.0, 0.0);
    win.draw_line(win.window_size().second - 10, mouse_position.second, win.window_size().second, mouse_position.second, 0.0, 0.0, 0.0);

    win.draw_line(mouse_position.first, 0, mouse_position.first, 10, 0.0, 0.0, 0.0);
    win.draw_line(mouse_position.first, win.window_size().second - 10, mouse_position.first, win.window_size().second, 0.0, 0.0, 0.0);

    std::string display_text = "mouse position: (" + std::to_string(mouse_position.first) + ", " + std::to_string(mouse_position.second) + ")";
    
    int text_offset_x = 10;
    int text_offset_y = 5;
    unsigned int font_size = 35;
    
    win.draw_text(text_offset_x, text_offset_y, font_size, display_text);
     
    // Aufgabe 2.11
    Vec2 cen_c = {400.0f, 400.0f};
    Vec2 cen_d = {300.0f, 300.0f};
    Color col_c = {1.0f, 0.0f, 0.0f};
    Circle c = {50.0f, cen_c, col_c};
    Circle d = {130.0f, cen_d, col_c};
    c.draw(win);

    Vec2 min_r = {300.5f, 500.8};
    Vec2 max_r = {200.0f, 400.6};
    Vec2 min_a = {100.0f, 700.0f};
    Vec2 max_a = {250.0f, 500.0f};
    Color col_r = {0.0f, 1.0f, 0.0f};; 
    Color col_a = {0.0f, 0.0f, 1.0f};
    Rectangle r = {min_r, max_r, col_r};
    Rectangle a = {min_a, max_a, col_a};
    r.draw(win);

    //Aufgabe 2.13
    
    std::array <Rectangle,2> Rectangles = {r, a};

    for (int w = 0; w < Rectangles.size(); ++w) {
        if (Rectangles[w].is_inside_(Vec2{float(mouse_position.first), float(mouse_position.second)})) {
            Rectangles[w].draw(win, 10.0f);
        } 
        else {
            Rectangles[w].draw(win, 2.0f);
        }
}

    win.update(); 
  }

  return 0;
}
