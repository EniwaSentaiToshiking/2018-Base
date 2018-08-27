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

void CourceMonitor::getRawColor(){
	colorSensor->getRawColor();
}

int CourceMonitor::getColorRed(){
	return colorSensor->getColorRed();
}

int CourceMonitor::getColorGreen(){
	return colorSensor->getColorGreen();
}

int CourceMonitor::getColorBlue(){
	return colorSensor->getColorBlue();
}