#include "RunManager.h"

RunManager::RunManager(){
    runCommander = new RunCommander();
    armCommander    = new ArmCommander();
    tailCommander   = new TailCommander();
    lineTrace = new LineTrace();
    localization = new Localization();
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
    float distance = localization->getCurrentDistance();
    if (distance > 100) {
        ev3_speaker_play_tone (480,100);
    }
    runCommander->steer(30, lineTrace->getTurnValueByOnOFF());
}