#include "RunStatus.h"
#include "RunManager.h"

RunStatus::~RunStatus(){
    for_each(patterns.begin(), patterns.end(), DeleteObject());
    patterns.clear();
}

bool RunStatus::run(){
    bool isFinishPattern = patterns[currentPattern]->run();
    if (isFinishPattern)
    {
        bool isFinishStatus = changeNextPattern();
        if(isFinishStatus) return true;
    }
    return false;
}

bool RunStatus::changeNextPattern(){
    if(currentPattern < patterns.size() - 1){
        currentPattern++;
        ev3_speaker_play_tone (480,100);
    }else {
        return true;
    }
    return false;
}

void RunStatus::changeNextStatus(RunManager *manager){
    manager->changeStatus(this->nextState);
}