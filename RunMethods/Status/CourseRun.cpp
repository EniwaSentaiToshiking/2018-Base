#include "CourseRun.h"

CourseRun::CourseRun(Course course){
    this->course = course;
    tailCommander = new TailCommander();
    armCommander = new ArmCommander();
    runCommander = new RunCommander();
    lineTrace = new LineTrace();
    pointDetecter = new PointDetecter();
    lotManager = new LotManager(R);
    pointDetecter->update(lotManager->getNextLotInfo());
}

CourseRun::~CourseRun(){
    delete tailCommander;
    delete armCommander;
    delete runCommander;
    delete lineTrace;
    delete pointDetecter;
}

void CourseRun::init(){
    tailCommander->rotateDefault();
    armCommander->rotateDefault();
}

void CourseRun::run(){
    tailCommander->rotateDefault();
    armCommander->rotateDefault();

    lineTrace->updateParams(lotManager->getCurrentLotPID(), 100, 10); //(P,I,D,最大PWM, 目標輝度値)
    runCommander->steer(lotManager->getCurrentLotSpeed(), lineTrace->getTurnValue());//(forward値,PID制御の操作量)

    if(pointDetecter->detect()){
        lotManager->changeCurrentLot();
        pointDetecter->update(lotManager->getNextLotInfo());
    }
}

bool CourseRun::isFinish(){
    if(lotManager->isFinish()){
        return true;
    }
    return false;
}