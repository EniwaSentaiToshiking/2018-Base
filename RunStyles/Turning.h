#include "RunStyle.h"
#include "WheelInfo.h"

class Turning : public RunStyle {

private:
    PID *pid;
    WheelInfo *wheelInfo;
    int speed;
    int32_t *beginCount;
    int direction = 0;

public:
    Turning(int direction, int speed);
    void init();
    int getTurnValue();
    virtual ~Turning();
};