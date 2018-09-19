#include "BrightnessDetecter.h"

BrightnessDetecter::BrightnessDetecter(int threshold)
{
    courceMonitor = new CourceMonitor();
    this->threshold = threshold;
}

BrightnessDetecter::~BrightnessDetecter()
{
    delete courceMonitor;
}

void BrightnessDetecter::init(){
}

bool BrightnessDetecter::detect()
{
    int currentBrightness = courceMonitor->getCurrentBrightness();
    if(currentBrightness == threshold) return true;
    if(threshold-3 <= currentBrightness && currentBrightness <= threshold+3) return true;
    return false;
}