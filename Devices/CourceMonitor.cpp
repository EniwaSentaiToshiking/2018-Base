#include "CourceMonitor.h"

CourceMonitor::CourceMonitor()
{
    colorSensor = new ColorSensorDriver();
    filter = new Filter();
}

CourceMonitor::~CourceMonitor()
{
    delete colorSensor;
}

int CourceMonitor::getCurrentBrightness()
{
    return colorSensor->getBrightness();
}

int CourceMonitor::getFilterBrightness(){
    return filter->lowpass(colorSensor->getBrightness());
}

colorid_t CourceMonitor::getColorNumber(){
	return colorSensor->getColorNumber();
}