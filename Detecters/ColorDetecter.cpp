#include "ColorDetecter.h"

ColorDetecter::ColorDetecter(int threshold)
{
    courceMonitor = new CourceMonitor();
    this->threshold = threshold;
}

ColorDetecter::~ColorDetecter()
{
    delete courceMonitor;
}

void ColorDetecter::init(){
}

bool ColorDetecter::detect()
{
    int currentColor = courceMonitor->getColorNumber();
    if(currentColor == threshold) return true;
    return false;
}