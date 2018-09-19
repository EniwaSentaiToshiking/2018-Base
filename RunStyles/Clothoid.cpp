#include "Clothoid.h"

Clothoid::Clothoid(TurningDirection direction, int speed){
    pid = new PID(0,0,0);
    wheelInfo = new WheelInfo();
    this->direction = direction;
    this->speed = speed;
    init();
}

Clothoid::~Clothoid(){
}

void Clothoid::init(){
    beginCount = wheelInfo->getInitCount();
}

int Clothoid::getTurnValue(){
    int32_t *info = wheelInfo->getCount();
    int32_t error = (info[0] - beginCount[0]) - (info[1] - beginCount[1]);

    //Todo params調整        周期      どのくらい旋回量を上昇させるか
    // if(++count == (speed * ??) / 4) {
    //     turn += ??;
    //     count = 0;
    // } 

    if(turn >= 50){
        turn = 50;
    }

    if(this->direction == DIRECTION_LEFT){
        turn += pidController->getTurn(this->pid, error, (info[0] - beginCount[0]) * -1, 100);
        turn = turn * -1;
    }else {
        turn += pidController->getTurn(this->pid, error, (info[0] - beginCount[0]) / 2, 100);
    }
    return turn;
}