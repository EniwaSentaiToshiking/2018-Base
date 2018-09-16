#include "AIRun.h"

AIRun::AIRun(){
    analogLog  = new AnalogLog();
    digitalLog = new DigitalLog();

    patterns.push_back(new RunPattern(STRAIGHT, 15, DISTANCE, 10));
    patterns.push_back(new RunPattern(STRAIGHT, 10, COLOR, 0));
    patterns.push_back(new RunPattern(STRAIGHT, 10, DISTANCE, 5));
    patterns.push_back(new RunPattern(BRAKE, 10, TIME , 10000));
    patterns.push_back(new RunPattern(SPIN, 15, DIRECTION, 90));
    patterns.push_back(new RunPattern(STRAIGHT, 10, DISTANCE, 9));
    patterns.push_back(new RunPattern(BRAKE, 10, TIME , 1000));
    patterns.push_back(new RunPattern(SPIN, 15, DIRECTION, -90));
    patterns.push_back(new RunPattern(STRAIGHT, -10, DISTANCE, 3));

    patterns.push_back(new RunPattern(STRAIGHT, 10, DISTANCE, 11));

    patterns.push_back(new RunPattern(STRAIGHT, 10, DISTANCE, 13));

    patterns.push_back(new RunPattern(STRAIGHT, 10, DISTANCE, 7));
    patterns.push_back(new RunPattern(BRAKE, 10, TIME , 1000));
    patterns.push_back(new RunPattern(SPIN, 15, DIRECTION, 90));
    patterns.push_back(new RunPattern(STRAIGHT, 10, DISTANCE, 13));
    patterns.push_back(new RunPattern(BRAKE, 10, TIME , 1000));
    patterns.push_back(new RunPattern(SPIN, 15, DIRECTION, 90));
    patterns.push_back(new RunPattern(STRAIGHT, 10, DISTANCE, 10));

    patterns.push_back(new RunPattern(STRAIGHT, 10, DISTANCE, 7));
    patterns.push_back(new RunPattern(BRAKE, 10, TIME , 1000));
    patterns.push_back(new RunPattern(SPIN, 15, DIRECTION, 90));
    patterns.push_back(new RunPattern(STRAIGHT, 10, DISTANCE, 10));
    patterns.push_back(new RunPattern(STRAIGHT, 10, DISTANCE, 10));

    patterns.push_back(new RunPattern(BRAKE, 10, DISTANCE, 10));

    setNextState();
}

AIRun::~AIRun(){
    delete analogLog;
    delete digitalLog;
}

void AIRun::init(){
}

void AIRun::setNextState(){
    nextState = STOP;
}

bool AIRun::run() {
    bool isFinishPattern = patterns[currentPattern]->run();
    if (isFinishPattern)
    {
        saveLog();
        digitalLog->finishLogging();
        bool isFinishStatus = changeNextPattern();
        if(isFinishStatus) return true;
    } else {
  
        if(shouldLogging() == ANALOG_LOG){
            analogLog->logging();
        }
        if(shouldLogging() == DIGITAL_LOG) {
            digitalLog->logging();
        }
    }
    return false;
}

void AIRun::saveLog() {
    digitalLog->saveLog("digitalNumber.log");
    analogLog->saveLog("analogNumber.log");
}

LogType AIRun::shouldLogging() {
    if(logPattern[currentPattern] == 1) {
        return DIGITAL_LOG;
    }
    if(logPattern[currentPattern] == 2) {
        return ANALOG_LOG;
    }
    return NONE_LOG;
}
