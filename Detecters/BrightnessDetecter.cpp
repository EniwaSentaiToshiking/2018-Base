#include "BrightnessDetecter.h"

BrightnessDetecter::BrightnessDetecter(int threshold, Compare compare)
{
    courceMonitor = new CourceMonitor();
    this->threshold = threshold;
    this->compare = compare;
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
    if (compare == EQUAL) {
        if(threshold-3 <= currentBrightness && currentBrightness <= threshold+3) return true;
    } else if(compare == LT) {
        if(threshold > currentBrightness) return true;
    } else if(compare == GT) {
        if(threshold < currentBrightness) return true;
    }
    return false;
}