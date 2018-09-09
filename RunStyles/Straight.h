#include "RunStyle.h"
#include "WheelInfo.h"

#ifndef STRAIGHT_H
#define STRAIGHT_H

class Straight : public RunStyle {

private:
    WheelInfo *wheelInfo;
    int speed;

public:
    Straight(int speed);
    int getTurnValue();
    virtual ~Straight();

};

#endif