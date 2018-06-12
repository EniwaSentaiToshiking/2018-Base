#include "RunManager.h"

RunManager::RunManager(){
    runCommander = new RunCommander();
    armCommander    = new ArmCommander();
    tailCommander   = new TailCommander();
    lineTrace = new LineTrace();
    localization = new Localization();
    lotManager = new LotManager(0);
}

RunManager::~RunManager(){
    delete runCommander;
    delete armCommander;
    delete tailCommander;
    delete lineTrace;
}

void RunManager::init(){
    tailCommander->rotateDefault();
    armCommander->rotateDefault();
}

void RunManager::run(){
    tailCommander->rotateDefault();
    armCommander->rotateDefault();
    //Todo if 走行区画が変わったら or シナリオが変わったら
    lineTrace->updateParams(lotManager->getCurrentLotPID());
    //----------
    runCommander->steer(30, lineTrace->getTurnValue());
}