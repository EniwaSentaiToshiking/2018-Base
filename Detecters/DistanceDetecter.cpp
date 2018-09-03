#include "DistanceDetecter.h"

DistanceDetecter::DistanceDetecter(int threshold)
{
    local = new Localization();
    this->threshold = threshold;
}

DistanceDetecter::~DistanceDetecter()
{
    delete local;
}

void DistanceDetecter::init(){
    prev_distance = local->getCurrentDistance();
}

bool DistanceDetecter::detect()
{
    local->update();
    if(local->getCurrentDistance() - prev_distance >= threshold) return true;
    return false;
}