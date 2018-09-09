#include "ArmMotorDriver.h"

ArmMotorDriver::ArmMotorDriver(){
    motor = new Motor(PORT_D);
    clock = new Clock();
}

ArmMotorDriver::~ArmMotorDriver(){
    delete motor;
}

void ArmMotorDriver::reset(){
    motor->reset();
}

int32_t ArmMotorDriver::getCount(){
    return motor->getCount();
}

void ArmMotorDriver::setPWM(int pwm){
    motor->setPWM(pwm);
}

void ArmMotorDriver::calibration()
{
    int prevArmMotorCount = -10;
    while (motor->getCount() - prevArmMotorCount != 0)
    {
        motor->setPWM(-10);
        prevArmMotorCount = motor->getCount();
        clock->sleep(100);
    }

    motor->reset();
}

void ArmMotorDriver::rotate(int32_t angle)
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

void ArmMotorDriver::rotateDefault(){
    rotate(DEFAULT_ANGLE);
}