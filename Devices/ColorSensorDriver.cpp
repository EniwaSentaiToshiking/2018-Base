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