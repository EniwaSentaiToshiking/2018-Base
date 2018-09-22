#include "BrightnessLowerDetecter.h"

BrightnessLowerDetecter::BrightnessLowerDetecter(int threshold)
{
    courceMonitor = new CourceMonitor();
    this->threshold = threshold;
}

BrightnessLowerDetecter::~BrightnessLowerDetecter()
{
    delete courceMonitor;
}

void BrightnessLowerDetecter::init(){
}

bool BrightnessLowerDetecter::detect()
{
    int currentBrightness = courceMonitor->getCurrentBrightness();
    if(threshold+3 >= currentBrightness) return true;
    return false;
}