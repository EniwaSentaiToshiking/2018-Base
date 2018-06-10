#include "WheelMotorDriver.h"
#include "Steering.h"
using namespace ev3api;

class RunCommander {

private:
    WheelMotorDriver *leftMotor;
    WheelMotorDriver *rightMotor;
    Steering *steering;

public:
    RunCommander();

    /**
     * steer - ステアリング走行をする turnが+25である場合、左モータのパワーは power で，右モータのパワーは power の75になり、 車体は右へ転回する 
     *
     * @param  {int, int}   power モータのパワー [-100..+100] マイナスの値は後退 
     *                      turn  ステアリングの度合い [-100..100] マイナスの値は左への転回、プラスの値は右への転回 
     * @return {void}
     */
    void steer(int power, int turn);

    /**
     * steerStop - ステアリング走行を止める
     *
     * @param  {void}
     * @return {void}
     */
    void steerStop();

    /**
     * run - 左右モータを動かす
     *
     * @param  {int, int} pwmL 左モータのPWM, pwmR 右モータのPWM
     * @return {void}
     */
    void run(int pwmL, int pwmR);
    virtual ~RunCommander();
};