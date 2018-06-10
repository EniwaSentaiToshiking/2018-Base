#ifndef COURCEMONITOR_H
#define COURCEMONITOR_H

#include "ColorSensorDriver.h"

using namespace ev3api;

class CourceMonitor
{

  private:
    ColorSensorDriver *colorSensor;

  public:
    CourceMonitor();
    int getCurrentBrightness();
    virtual ~CourceMonitor();
};

#endif
