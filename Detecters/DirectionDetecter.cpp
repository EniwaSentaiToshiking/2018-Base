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
    prev_direction = local->getCurrentDirection();
}

bool DirectionDetecter::detect()
{
    local->update();
    if(local->getCurrentDirection() - prev_direction >= threshold) return true;
    return false;
}