#include "TimeDetecter.h"

TimeDetecter::TimeDetecter(int threshold)
{
    this->threshold = threshold;
    time = Clock.getTim();
}

TimeDetecter::~TimeDetecter()
{
    delete clock;
}

void TimeDetecter::init(){}

bool TimeDetecter::detect()
{
  char c[100];
  sprintf(c, "%f", Clock.getTim() - time);
  ev3_lcd_set_font(EV3_FONT_MEDIUM);
  ev3_lcd_draw_string(c, 10, 60); 

  return clock->now() < this->threshold;
}