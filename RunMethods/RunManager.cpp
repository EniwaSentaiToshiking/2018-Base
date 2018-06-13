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

    // float distance = localization->getCurrentDistance();
    // if (distance > 100) {
    //     ev3_speaker_play_tone (480,100);
    // }

    //Todo if 走行区画が変わったら or シナリオが変わったら
    lineTrace->updateParams(lotManager->getCurrentLotPID(), 100);
    //----------
    if (courceMonitor->getColorNumber() == 5){
        runCommander->steerStop();
        ev3_speaker_play_tone(480,100);
    }
    else if(courceMonitor->getColorNumber() == 2){
        runCommander->steerStop();
        ev3_speaker_play_tone(480,100);
    }else{
        runCommander->steer(lotManager->getCurrentLotSpeed(), lineTrace->getTurnValue());
    }

}