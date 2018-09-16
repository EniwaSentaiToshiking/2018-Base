#include "DirectionDetecter.h"

DirectionDetecter::DirectionDetecter(int threshold)
{
    local = new Localization();
    this->threshold = threshold;
}

DirectionDetecter::~DirectionDetecter()
{
    delete local;
}

void DirectionDetecter::init(){
    local->distance_reset();
    // local->update();
    // prev_direction = local->getCurrentDirection();
}

bool DirectionDetecter::detect()
{
    local->update();
    if(this->threshold >= 0){
        if(local->getCurrentDirection()>= threshold) return true;
    }else {
        if(local->getCurrentDirection()<= threshold) return true;
    }
    return false;
}