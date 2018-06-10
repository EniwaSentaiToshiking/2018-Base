#include "PID.h"

PID::PID(float p, float i, float d)
{
    this->p = p;
    this->i = i;
    this->d = d;
}

PID::~PID()
{
}