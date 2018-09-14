#include "RunStyle.h"
#include "WheelInfo.h"
#include "Logger.h"

#ifndef SPIN_H
#define SPIN_H

class Spin : public RunStyle {

private:
    WheelInfo *wheelInfo;
    int speed;
    int threshold;
    Logger *logger;
    int32_t *beginCount;

public:
    Spin(int threshold, int speed);
    void init();
    int getTurnValue();
    virtual ~Spin();
};

#endif