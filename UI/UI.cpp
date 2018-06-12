#include "UI.h"

UI::UI(){
    touchSensor = new TouchSensorDriver();
    initLCD();
}

UI::~UI(){
    delete touchSensor;
}

bool UI::isTouched(){
    return touchSensor->isPressed();
}

void UI::initLCD(){
    ev3_lcd_fill_rect(0, 0, EV3_LCD_WIDTH, EV3_LCD_HEIGHT, EV3_LCD_WHITE);
    ev3_lcd_draw_string("HackEV app", 0, CALIB_FONT_HEIGHT*1);
    drawRowCount = 2;
}

void UI::drawStringOnLCD(const char *string)
{
    ev3_lcd_draw_string(string, 0, CALIB_FONT_HEIGHT * drawRowCount);
    drawRowCount++;
}