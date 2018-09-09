#include "CourceMonitor.h"

CourceMonitor::CourceMonitor()
{
    colorSensor = new ColorSensorDriver();
}

CourceMonitor::~CourceMonitor()
{
    delete colorSensor;
}

int CourceMonitor::getCurrentBrightness()
{
    return colorSensor->getBrightness();
}

colorid_t CourceMonitor::getColorNumber(){
	return colorSensor->getColorNumber();
}