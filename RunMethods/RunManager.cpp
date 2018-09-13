#include "RunManager.h"

RunManager::RunManager()
{
    changeStatus(this->state);
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
        case PARKING:
            status = new Parking(course);
            break;
        case STOP:
            status = new Stop();
            break;
        case GAME: 
            status = new Game();
            break;
        case AIBLOCKMOVE:
            status = new AiBlockMove();
            break;
    }
}
