#include "Turning.h"

Turning::Turning(int direction, int speed){
    pid = new PID(0,0,0);
    pidController = new PIDController();
    wheelInfo = new WheelInfo();
    this->direction = direction;
    this->speed = speed;
    init();
}

Turning::~Turning(){
    delete pidController;
}

void Turning::init(){
    beginCount = wheelInfo->getCount();
}

int Turning::getTurnValue(){
    int32_t *info = wheelInfo->getCount();
    int32_t error = (info[0] - beginCount[0]) - (info[1] - beginCount[1]);
    int turn = speed;
    if(this->direction >= 0){
        turn += pidController->getTurn(this->pid, error, (info[0] - beginCount[0]) * -1, 100);
    }else {
        turn += pidController->getTurn(this->pid, error, (info[0] - beginCount[0]) / 2, 100);
    }
    return speed + turn;
}