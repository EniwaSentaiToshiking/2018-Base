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
    return false;
}