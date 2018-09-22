#include "BrightnessUpperDetecter.h"

BrightnessUpperDetecter::BrightnessUpperDetecter(int threshold)
{
    courceMonitor = new CourceMonitor();
    this->threshold = threshold;
}

BrightnessUpperDetecter::~BrightnessUpperDetecter()
{
    delete courceMonitor;
}

void BrightnessUpperDetecter::init(){
}

bool BrightnessUpperDetecter::detect()
{
    int currentBrightness = courceMonitor->getCurrentBrightness();
    if(threshold-3 <= currentBrightness) return true;
    return false;
}