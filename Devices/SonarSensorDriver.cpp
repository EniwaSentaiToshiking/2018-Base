#include "SonarSensorDriver.h"

SonarSensorDriver::SonarSensorDriver()
{
    sonarSensor = new SonarSensor(PORT_3);
}

SonarSensorDriver::~SonarSensorDriver()
{
    delete sonarSensor;
}

int16_t SonarSensorDriver::getDistance(void)
{
    return sonarSensor->getDistance();
}

bool SonarSensorDriver::getListen(void)
{
    return sonarSensor->listen();
}