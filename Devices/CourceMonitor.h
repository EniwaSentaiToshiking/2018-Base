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
    /**
     * getColorNumber - RGBを測定する 
     *
     * @param  {void}
     * @return {colorid_t}      
     */
    colorid_t getColorNumber(); 
    virtual ~CourceMonitor();
};

#endif
