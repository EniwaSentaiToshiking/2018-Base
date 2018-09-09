#include "ColorSensor.h"
using namespace ev3api;

#ifndef COLORSENSORDRIVER_H
#define COLORSENSORDRIVER_H

class ColorSensorDriver {

private:
    ColorSensor *colorSensor;
    int red = 0;
    int green = 0;
    int blue = 0;

public:
	ColorSensorDriver();

    /**
     * getBrightness - 反射光の強さを測定する 
     *
     * @param  {void}
     * @return {int8_t}      反射光の強さ (0-100) 
     */
	int8_t getBrightness();

    /**
     * getAmbient - 環境光の強さを測定する 
     *
     * @param  {void}
     * @return {uint8_t}      環境光の強さ (0-100) 
     */
    uint8_t getAmbient();

    /**
     * getColorNumber - RGBを測定する 
     *
     * @param  {void}
     * @return {colorid_t}      
     */
    colorid_t getColorNumber();
    void getRawColor();
    int getColorRed();
    int getColorGreen();
    int getColorBlue();

virtual ~ColorSensorDriver();
};

#endif