#include "ColorSensorDriver.h"

ColorSensorDriver::ColorSensorDriver()
{
    colorSensor = new ColorSensor(PORT_2);
}

ColorSensorDriver::~ColorSensorDriver()
{
    delete colorSensor;
}

int8_t ColorSensorDriver::getBrightness() {
    return colorSensor->getBrightness();
}

uint8_t ColorSensorDriver::getAmbient() {
    return colorSensor->getAmbient();
}
colorid_t ColorSensorDriver::getColorNumber(){
	return colorSensor->getColorNumber();
}

void ColorSensorDriver::getRawColor(){
 	rgb_raw_t rgb;
	colorSensor->getRawColor(rgb);
	red = rgb.r;
	green = rgb.g;
	blue = rgb.b;
}

int ColorSensorDriver::getColorRed(){
	return red;
}

int ColorSensorDriver::getColorGreen(){
	return green;
}
int ColorSensorDriver::getColorBlue(){
	return blue;
}