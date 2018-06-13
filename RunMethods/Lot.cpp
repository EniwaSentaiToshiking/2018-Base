#include "Lot.h"

Lot::Lot(float x0, float x1, float y0, float y1, int speed, float p, float i, float d)
{
    this->x0 = x0;
    this->x1 = x1;
    this->y0 = y0;
    this->y1 = y1;
    this->speed = speed;
    pid = new PID(p, i, d);
}

Lot::~Lot()
{
    delete pid;
}