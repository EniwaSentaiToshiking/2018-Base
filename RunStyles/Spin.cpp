#include "Spin.h"
#include <cmath>
using namespace std;

Spin::Spin(int speed){
    wheelInfo = new WheelInfo();
    this->speed = speed;
    pid = new PID(0.1, 0.00, 0.01);
}

Spin::~Spin(){
}

int Spin::getTurnValue(){
    int32_t *info = wheelInfo->getCount();
    return pidController->getTurn(this->pid, abs(info[0])-abs(info[1]), 0, 100);
}