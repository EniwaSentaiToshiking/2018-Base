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
    switch (state)
    {
    case COURSE_RUN: {
        bool isFinish = status->run();
        if(isFinish) state = STOP;
        break;
    }
    case STOP:
        ev3_speaker_play_tone(480, 100);
        break;
    }
}

void RunManager::changeStatus(){
}