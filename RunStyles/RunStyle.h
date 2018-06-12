#include "PID.h"
#include "PIDController.h"

class RunStyle {

protected:
    PIDController *pidController;
    PID *pid;

public:
    virtual int getTurnValue() = 0;
};