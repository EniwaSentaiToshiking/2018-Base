#include "RunStyle.h"
#include "WheelInfo.h"

#ifndef SPIN_H
#define SPIN_H

class Spin : public RunStyle {

private:
    WheelInfo *wheelInfo;
    int speed;
    int threshold;

public:
    Spin(int threshold, int speed);
    int getTurnValue();
    virtual ~Spin();
};

#endif