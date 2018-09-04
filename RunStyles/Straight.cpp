#include "Straight.h"

Straight::Straight(int speed){
    pidController = new PIDController();
    wheelInfo = new WheelInfo();
    this->speed = speed;
    pid = new PID(0,0,0);
}

Straight::~Straight(){
    delete pidController;
}

int Straight::getTurnValue(){
    int32_t *info = wheelInfo->getCount();
    return pidController->getTurn(this->pid, info[0] - info[1], 0, 100);
}