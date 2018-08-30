#include "RunStyle.h"
#include "WheelInfo.h"

class Straight : public RunStyle {

private:
    PID *pid;
    WheelInfo *wheelInfo;
    int absMaxSpeed;

public:
    Straight();
    void updateParams();
    int getTurnValue();
    virtual ~Straight();

};