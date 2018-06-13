#include "RunManager.h"
#define UNKNOWN 0
#define BLACK 1
#define BLUE 2
#define GREEN 3
#define YELLOW 4
#define RED 5
#define WHITE 6
#define BROWN 7

int flag = 0; //テスト用、削除していい。色検知したらフラグを1にする

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
    if (courceMonitor->getColorNumber() == RED){
        ev3_speaker_play_tone(480,100);
        flag = 1;
    }else if (flag == 0){
        runCommander->steer(lotManager->getCurrentLotSpeed(), lineTrace->getTurnValue());
    }
    else {
        runCommander->steerStop();
    }

}