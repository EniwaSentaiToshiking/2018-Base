#include "LineTrace.h"

LineTrace::LineTrace(PID *pid, int targetBrightness, Edge edge, int speed){
    courceMonitor = new CourceMonitor();
    this->pid = pid;
    this->targetBrightness = targetBrightness;
    this->edge = edge;
    this->speed = speed;
    logger = new Logger("pid_linetrace.csv");
}

LineTrace::~LineTrace(){
    delete courceMonitor;
    delete logger;
}

int LineTrace::getTurnValue(){
    int turn = pidController->getTurn(this->pid, this->courceMonitor->getCurrentBrightness(), this->targetBrightness, 100);

    if(this->edge == RIGHT) turn = turn * -1;

    logger->logging((float)turn);

    return turn;
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