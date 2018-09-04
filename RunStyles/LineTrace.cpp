#include "LineTrace.h"

LineTrace::LineTrace(PID *pid, int targetBrightness){
    pidController = new PIDController();
    courceMonitor = new CourceMonitor();
    this->pid = pid;
    this->targetBrightness = targetBrightness;
}

LineTrace::~LineTrace(){
    delete pidController;
    delete courceMonitor;
}

int LineTrace::getTurnValue(){
    return pidController->getTurn(this->pid, this->courceMonitor->getCurrentBrightness(), this->targetBrightness, 100);
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