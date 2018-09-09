#include "Spin.h"

Spin::Spin(int speed){
    wheelInfo = new WheelInfo();
    this->speed = speed;
    pid = new PID(0,0,0);
}

Spin::~Spin(){
}

int Spin::getTurnValue(){
    int32_t *info = wheelInfo->getCount();
    return pidController->getTurn(this->pid, info[0] - info[1], 0, 100);
}