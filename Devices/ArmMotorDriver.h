#include "Motor.h"
#include "Clock.h"
using namespace ev3api;

#ifndef ARMMOTORDRIVER_H
#define ARMMOTORDRIVER_H

class ArmMotorDriver {

private:
    Motor *motor;
    Clock *clock;
    const int DEFAULT_ANGLE = 30;

    const int KP = 2.5F;
    const int PWM_ABS_MAX = 60;

public:
    ArmMotorDriver();

    /**
     * reset - モータリセット モータ停止および角位置の0リセット、オフセット初期化を行う  
     *
     * @param  {void}
     * @return {void}
     */
    void reset();
    void calibration();

    /**
     * getCount - オフセット付き角位置取得 
     *
     * @param  {void}
     * @return {int32_t} モータ角位置 [deg] 
     */
    int32_t getCount();

    void setPWM(int pwm);

    /**
     * rotate - 腕を動かす
     *
     * @param  {int32_t}     angle	角度 [deg] 
     * @return {void} 
     */
    void rotate(int32_t angle);

    /**
     * rotateDefault - デフォルトの位置まで動かす
     *
     * @param  {void}
     * @return {void} 
     */
    void rotateDefault();


    virtual ~ArmMotorDriver();

};

#endif