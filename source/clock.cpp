 #include "clock.hpp"
 #include "window.hpp"
 #include "color.hpp"

int main(int argc, char* argv[])
{
  Window win{std::make_pair(800,800)};

  while (!win.should_close()) {

auto time = win.get_time();

int hour = time / 3600;
int minute = time / 60;
int second = (int)time % 60;
    
std::string display_text =  std::to_string(hour) + " hours " + std::to_string(minute) + " minutes " + std::to_string(second) + " seconds ";

int text_offset_x = 10;
int text_offset_y = 5;
unsigned int font_size = 20;
    
win.draw_text(text_offset_x, text_offset_y, font_size, display_text);


Vec2 center = {400.0f, 400.0f};

float angle_h = (2 * M_PI) / 60;
float angle_m = (2 * M_PI) / 60;
float angle_s = (int)(2 * M_PI) % 12;
                                                                            
win.draw_line(center.x, center.y, 180.0f * cos(angle_h * (second - 15)) + 400.0f, 180.0f * sin(angle_h * (second - 15)) + 400.0f, 1.0f, 0.0f, 0.0f);
win.draw_line(center.x, center.y, 150.0f * cos(angle_h * (minute - 15)) + 400.0f, 150.0f * sin(angle_h * (minute - 15)) + 400.0f, 0.0f, 0.0f, 1.0f);
win.draw_line(center.x, center.y, 90.0f * cos(angle_h * 5 * (hour - 15)) + 400.0f, 90.0f * sin(angle_h * 5 * (hour - 15)) + 400.0f, 0.0f, 1.0f, 0.0f);

auto mouse_position = win.mouse_position();

win.update();

  }
}