#include "RunStyle.h"
#include "WheelInfo.h"

class Straight : public RunStyle {

private:
    PID *pid;
    WheelInfo *wheelInfo;
    int speed;

public:
    Straight(int speed);
    int getTurnValue();
    virtual ~Straight();

};