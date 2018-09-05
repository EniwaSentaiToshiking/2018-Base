#include "RunManager.h"

RunManager::RunManager()
{
    status = new CourseRun(course);
}

RunManager::~RunManager()
{
    delete status;
}

void RunManager::init()
{
    status->init();
}

void RunManager::run()
{
    bool isFinish = status->run();
    if(isFinish) status->changeNextStatus(this);
}

void RunManager::changeStatus(RunState state){
    switch(state){
        case COURSE_RUN:
            status = new CourseRun(course);
            break;
        case STOP:
            status = new Stop();
            break;
    }
}