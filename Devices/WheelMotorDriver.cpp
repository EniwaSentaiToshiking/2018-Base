#include "WheelMotorDriver.h"

WheelMotorDriver::WheelMotorDriver(ePortM port){
    motor = new Motor(port);
    reset();
}

WheelMotorDriver::~WheelMotorDriver(){
    reset();
    delete motor;
}

void WheelMotorDriver::reset(){
    motor->reset();
}

int32_t WheelMotorDriver::getCount(){
    return motor->getCount();
}

void WheelMotorDriver::controlMotor(int pwm){
    motor->setPWM(pwm);
}

void WheelMotorDriver::stop(){
    motor->stop();
}