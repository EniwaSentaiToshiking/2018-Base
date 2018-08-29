#ifndef COURCEMONITOR_H
#define COURCEMONITOR_H

#include "ColorSensorDriver.h"
#include "Filter.h"

using namespace ev3api;

class CourceMonitor
{

  private:
    ColorSensorDriver *colorSensor;
    Filter *filter;

  public:
    CourceMonitor();
    int getCurrentBrightness();
    int getFilterBrightness();
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
