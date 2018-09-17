#include "Spin.h"
#include <cmath>
using namespace std;

Spin::Spin(TurningDirection direction, int speed){
    wheelInfo = new WheelInfo();
    this->speed = speed;
    this->direction = direction;
    if(speed == 10){
        // pid = new PID(0.8, 0.0, 0.01);
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

    int direction = (this->direction == DIRECTION_LEFT) ? -1:1; //正だったら1返す
    int diff = abs(info[0]-beginCount[0]) - abs(info[1]-beginCount[1]);

    int adjustedVal =
         pidController->getTurn(this->pid, diff , 0, 100);

    return (adjustedVal + 100) * direction;
}

/*
int Spin::getTurnValue(){
    int32_t *info = wheelInfo->getCount();
    int diff = (info[0] - beginCount[0]) + (info[1] - beginCount[1]);

    int turn = 100 + pidController->getTurn(this->pid, diff, 0, 100);

    if(this->direction == DIRECTION_LEFT) {
        turn *= -1;
    }

    return turn;
}
*/