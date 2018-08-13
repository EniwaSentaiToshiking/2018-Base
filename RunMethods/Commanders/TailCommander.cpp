#include "TailCommander.h"

TailCommander::TailCommander(){
    motor = new TailMotorDriver();
}

TailCommander::~TailCommander(){
    delete motor;
}

void TailCommander::rotate(int32_t angle){
    motor->rotate(angle);
}

void TailCommander::rotateDefault(){
    motor->rotateDefault();
}

void TailCommander::rotateExtend(){
    motor->rotateExtend();
}

void TailCommander::reset(){
    motor->reset();
}