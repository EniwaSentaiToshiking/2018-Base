#include "PID.h"
#include "PIDController.h"

#ifndef RUNSTYLE_H
#define RUNSTYLE_H

class RunStyle {

protected:
    PIDController *pidController;
    PID *pid;

public:
    RunStyle();
    virtual int getTurnValue() = 0;
    virtual ~RunStyle();
};

#endif