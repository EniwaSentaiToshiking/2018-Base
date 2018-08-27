#include "WheelMotorDriver.h"
#include "Steering.h"
#include "Grid.h"
#include "PID.h"
#include "PIDController.h"

using namespace ev3api;

class RunCommander {

private:
    WheelMotorDriver *leftMotor;
    WheelMotorDriver *rightMotor;
    Steering *steering;
    Grid *grid;
    PID* pid;
    PIDController* pidController;
    float P = 0.0;
    float I = 0.0;
    float D = 0.0;
    void adjustPWM(int32_t &leftPWM, int32_t &rightPWM);
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

    /**
     * goAhead - 直進する．
     *
     * @param  {int} pwm モータのPWM
     * @return {void}
     */
    void goStraight(int pwm);

    /**
     * gridRun -  目標の座標まで移動する
     *
     * @param  aX,aY(現在座標), bX,bY(目標座標),方向、距離
     * @return {void}
     */
    void gridRun(int aX, int aY, int bX, int bY, int pwm, float direction, float distance);

    int grid_flag = 0;
    float grid_direction = 0;
    float grid_distance = 0;

    virtual ~RunCommander();
};