#pragma once
#include "Motor.h"
using namespace ev3api;

#ifndef WHEELMOTORDRIVER_H
#define WHEELMOTORDRIVER_H

class WheelMotorDriver {

private:

public:
    Motor *motor;

    WheelMotorDriver(ePortM port);

    /**
     * reset - モータリセット モータ停止および角位置の0リセット、オフセット初期化を行う  
     *
     * @param  {void}
     * @return {void}
     */
    void reset();

    /**
     * getCount - オフセット付き角位置取得 
     *
     * @param  {void}
     * @return {int32_t} モータ角位置 [deg] 
     */
    int32_t getCount();

    /**
     * controlMotor - モータPWM値設定 ブレーキモードでPWM値が0の場合、モータを停止する 
     *
     * @param  {int}     pwm	PWM値 (-100 - 100) 
     * @return {int32_t} モータ角位置 [deg] 
     */
    void controlMotor(int pwm);

    /**
     * stop - モータの回転を止める
     *
     * @param  {void} 
     * @return {void}
     */
    void stop();

    virtual ~WheelMotorDriver();

};

#endif