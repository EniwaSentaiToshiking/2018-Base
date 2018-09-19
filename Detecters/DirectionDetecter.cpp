#include "DirectionDetecter.h"

DirectionDetecter::DirectionDetecter(int threshold, int shouldBeDirection)
{
    local = new Localization();
    this->threshold = threshold;
    this->shouldBeDirection = shouldBeDirection;
}

DirectionDetecter::~DirectionDetecter()
{
    delete local;
}

void DirectionDetecter::init(){
    local->update();
    if(shouldBeDirection == 999) {
        prev_direction = local->getCurrentDirection();
    } else {
        prev_direction = shouldBeDirection;
    }
}

bool DirectionDetecter::detect()
{
    local->update();
    if(this->threshold >= 0){
        if(local->getCurrentDirection() - prev_direction >= threshold) return true;
    }else {
        if(local->getCurrentDirection() - prev_direction <= threshold) return true;
    }
    return false;
}
