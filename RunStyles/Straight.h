#include "RunStyle.h"
#include "WheelInfo.h"

#ifndef STRAIGHT_H
#define STRAIGHT_H

class Straight : public RunStyle {

private:
    WheelInfo *wheelInfo;
    int speed;
    int32_t *beginCount;

public:
    Straight(int speed);
    void init();
    int getTurnValue();
    virtual ~Straight();

};

#endif