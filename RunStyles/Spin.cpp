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
    logger = new Logger("wheelinfo.log");
}

Spin::~Spin(){
}

void Spin::init(){
    beginCount = wheelInfo->getInitCount();
}

int Spin::getTurnValue(){
    int32_t *info = wheelInfo->getCount();
    
    int sa = (info[0]) + (info[1]);

    logger->logging(sa);

    int turn = 100 + pidController->getTurn(this->pid, sa, 0, 100);

    if(this->direction >= 0) {
        turn *= -1;
    }

    return turn;
}