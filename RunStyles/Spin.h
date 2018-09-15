#include "RunStyle.h"
#include "WheelInfo.h"

#ifndef SPIN_H
#define SPIN_H

class Spin : public RunStyle {

private:
    WheelInfo *wheelInfo;
    int speed;
    TurningDirection direction;
    int32_t *beginCount;

public:
    Spin(TurningDirection direction, int speed);
    void init();
    int getTurnValue();
    virtual ~Spin();
};

#endif