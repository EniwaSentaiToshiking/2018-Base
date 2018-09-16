#include "Straight.h"

Straight::Straight(int speed){
    wheelInfo = new WheelInfo();
    this->speed = speed;
    pid = new PID(0,0,0);
}

Straight::~Straight(){
}

void Straight::init(){
    beginCount = wheelInfo->getInitCount();
}

int Straight::getTurnValue(){
    int32_t *info = wheelInfo->getCount();
    return pidController->getTurn(this->pid, (info[0] - beginCount[0]) - (info[1] - beginCount[1]), 0, 100);
}