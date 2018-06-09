#include "TailMotorDriver.h"

TailMotorDriver::TailMotorDriver(){
    motor = new Motor(PORT_A);
    reset();
}

TailMotorDriver::~TailMotorDriver(){
    reset();
    delete motor;
}

void TailMotorDriver::reset(){
    motor->reset();
}

int32_t TailMotorDriver::getCount(){
    return motor->getCount();
}

void TailMotorDriver::rotate(int32_t angle)
{
    float pwm = (float)(angle - getCount()) * KP; /* 比例制御 */
    /* PWM出力飽和処理 */
    if (pwm > PWM_ABS_MAX)
    {
        pwm = PWM_ABS_MAX;
    }
    else if (pwm < -PWM_ABS_MAX)
    {
        pwm = -PWM_ABS_MAX;
    }

    motor->setPWM(pwm);
}

void TailMotorDriver::rotateDefault(){
    rotate(DEFAULT_ANGLE);
}

void TailMotorDriver::rotateExtend(){
    rotate(EXTEND_ANGLE);
}