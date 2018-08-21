#include "ArmCommander.h"

ArmCommander::ArmCommander(){
    motor = new ArmMotorDriver();
}

ArmCommander::~ArmCommander(){
    delete motor;
}

void ArmCommander::rotate(int32_t angle){
    motor->rotate(angle);
}

void ArmCommander::rotateDefault(){
    motor->rotateDefault();
}

void ArmCommander::reset(){
    motor->reset();
}