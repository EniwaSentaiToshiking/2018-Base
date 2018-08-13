#include "CourseRun.h"

CourseRun::CourseRun(Course course){
    this->course = course;
    tailCommander = new TailCommander();
    armCommander = new ArmCommander();
    runCommander = new RunCommander();
    lineTrace = new LineTrace();
    pointDetecter = new PointDetecter();

    Lot *lot_list[2];
    lot_list[0] = new Lot(0, 180, -30, 30, 20, 5.0, 0.1, 0.0);
    lot_list[1] = new Lot(0, 180, -30, 30, 20, 5.0, 0.1, 0.0);
    lotManager = new LotManager(lot_list);
    init();
}

CourseRun::~CourseRun(){
    delete tailCommander;
    delete armCommander;
    delete runCommander;
    delete lineTrace;
    delete pointDetecter;
}

void CourseRun::init(){
    switch(this->course){
        case L:
        break;
        case R:
        break;
    }

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
        pointDetecter->update(lotManager->getLotInfo());
    }
}

bool CourseRun::isFinish(){
    if(lotManager->isFinish()){
        return true;
    }
    return false;
}