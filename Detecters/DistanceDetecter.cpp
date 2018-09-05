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
    local->update();
    prev_distance = local->getCurrentDistance();
}

bool DistanceDetecter::detect()
{
    local->update();
    if(abs(local->getCurrentDistance() - prev_distance) >= threshold) return true;
    return false;
}