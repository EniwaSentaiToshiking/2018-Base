#include "Spin.h"

Spin::Spin(TurningDirection direction, int speed){
    wheelInfo = new WheelInfo();
    this->speed = speed;
    this->direction = direction;
    if(speed == 10){
        pid = new PID(0.0, 0.0, 0.0);
    }else {
        pid = new PID(0,0,0);
    }
}

Spin::~Spin(){
}

void Spin::init(){
    beginCount = wheelInfo->getInitCount();
}

int Spin::getTurnValue(){
    int32_t *info = wheelInfo->getCount();
    
    int diff = (info[0] - beginCount[0]) + (info[1] - beginCount[1]);

    int turn = 100 + pidController->getTurn(this->pid, diff, 0, 100);

    if(this->direction == DIRECTION_LEFT) {
        turn *= -1;
    }

    return turn;
}