#include "RunStyle.h"
#include "WheelInfo.h"

#ifndef TURNING_H
#define TURNING_H

class Turning : public RunStyle {

private:
    WheelInfo *wheelInfo;
    int speed;
    int32_t *beginCount;
    TurningDirection direction = DIRECTION_LEFT;

public:
    Turning(TurningDirection direction, int speed);
    void init();
    int getTurnValue();
    virtual ~Turning();
};

#endif