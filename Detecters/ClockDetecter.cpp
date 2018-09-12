#include "ClockDetecter.h"

ClockDetecter::ClockDetecter(int threshold)
{
    clock = new Clock();
    this->threshold = threshold;
}

ClockDetecter::~ClockDetecter()
{
    delete clock;
}

void ClockDetecter::init(){
    prev_clock = clock->now();
}

bool ClockDetecter::detect()
{
    if(clock->now() - prev_clock >= threshold) return true;
    return false;
}