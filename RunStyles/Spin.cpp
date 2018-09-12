#include "Spin.h"

Spin::Spin(int threshold, int speed){
    wheelInfo = new WheelInfo();
    this->speed = speed;
    this->threshold = threshold;
    pid = new PID(0,0,0);
}

Spin::~Spin(){
}

int Spin::getTurnValue(){
    int32_t *info = wheelInfo->getCount();
    
    int turn = 100 + pidController->getTurn(this->pid, info[0] - info[1], 0, 100);

    if(this->threshold >= 0) {
        turn *= -1;
    }

    return turn;
}