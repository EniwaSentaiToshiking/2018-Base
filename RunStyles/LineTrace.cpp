#include "LineTrace.h"

LineTrace::LineTrace(){
    pidController = new PIDController();
    pid = new PID(0,0,0);
    courceMonitor = new CourceMonitor();
}

LineTrace::~LineTrace(){
    delete pidController;
    delete courceMonitor;
}

void LineTrace::updateParams(PID *pid, int absMaxSpeed, int targetBrightness) {
    this->pid = pid;
    this->targetBrightness = targetBrightness;
    this->absMaxSpeed = absMaxSpeed;
}

int LineTrace::getTurnValue(){
    return pidController->getTurn(this->pid, this->courceMonitor->getCurrentBrightness(), this->targetBrightness, this->absMaxSpeed);
}

int LineTrace::getTurnValueByOnOFF(){
    
    int turn = 0;
    
    if (this->courceMonitor->getCurrentBrightness() >= this->targetBrightness)
    {
        turn = 30;
    }
    else
    {
        turn = -30;
    }

    return turn;
}