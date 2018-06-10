#include "RunManager.h"

RunManager::RunManager(){
    runCommander = new RunCommander();
    armCommander    = new ArmCommander();
    tailCommander   = new TailCommander();
    lineTrace = new LineTrace();
}

RunManager::~RunManager(){
    delete runCommander;
    delete armCommander;
    delete tailCommander;
    delete lineTrace;
}

void RunManager::run(){
    tailCommander->rotateDefault();
    armCommander->rotateDefault();
    runCommander->steer(30, lineTrace->getTurnValueByOnOFF());
}