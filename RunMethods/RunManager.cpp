#include "RunManager.h"

RunManager::RunManager(){
    runCommander = new RunCommander();
    armCommander    = new ArmCommander();
    tailCommander   = new TailCommander();
    lineTrace = new LineTrace();
    localization = new Localization();
    lotManager = new LotManager(0);
    courceMonitor = new CourceMonitor();
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
    localization->update();
    tailCommander->rotateDefault();
    armCommander->rotateDefault();

    //Todo if 走行区画が変わったら or シナリオが変わったら

    if(lotManager->isChangeCurrentLot()){
        lotManager->changeCurrentLot();
    }

    lineTrace->updateParams(lotManager->getCurrentLotPID(), 100, 10); //(P,I,D,最大PWM, 目標輝度値)
    runCommander->steer(lotManager->getCurrentLotSpeed(), lineTrace->getTurnValue());//(forward値,PID制御の操作量)
}