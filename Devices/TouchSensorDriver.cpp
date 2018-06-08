#include "TouchSensorDriver.h"

TouchSensorDriver::TouchSensorDriver()
{
    touchSensor = new TouchSensor(PORT_4);
}

TouchSensorDriver::~TouchSensorDriver()
{
    delete touchSensor;
}

bool TouchSensorDriver::isPressed(void)
{
    return touchSensor->isPressed();
}