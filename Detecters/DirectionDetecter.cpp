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
    local->update();
    prev_direction = local->getCurrentDirection();
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