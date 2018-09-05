#include "RunStatus.h"

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
    }else {
        return true;
    }
    return false;
}