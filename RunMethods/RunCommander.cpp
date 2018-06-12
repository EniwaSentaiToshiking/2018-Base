#include "RunCommander.h"

RunCommander::RunCommander(){
    leftMotor   = new WheelMotorDriver(PORT_C);
    rightMotor  = new WheelMotorDriver(PORT_B);
    steering = new Steering(*leftMotor->motor, *rightMotor->motor);
}

RunCommander::~RunCommander(){
    delete leftMotor;
    delete rightMotor;
}

void RunCommander::steer(int power, int turn){
    steering->setPower(power, turn);
}

void RunCommander::steerStop(){
    steering->setPower(0, 0);
}

void RunCommander::run(int pwmL, int pwmR){
    leftMotor->controlMotor(pwmL);
    rightMotor->controlMotor(pwmR);
}
