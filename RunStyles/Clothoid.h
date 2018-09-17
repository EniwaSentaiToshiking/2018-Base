#include "RunStyle.h"
#include "WheelInfo.h"

#ifndef CLOTHOID_H
#define CLOTHOID_H

class Clothoid : public RunStyle {

private:
    WheelInfo *wheelInfo;
    int speed;
    int32_t *beginCount;
    TurningDirection direction = DIRECTION_LEFT;
    int turn = 0;
    int count = 0;

public:
    Clothoid(TurningDirection direction, int speed);
    void init();
    int getTurnValue();
    virtual ~Clothoid();
};

#endif