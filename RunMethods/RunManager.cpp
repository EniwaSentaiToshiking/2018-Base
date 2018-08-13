#include "RunManager.h"

RunManager::RunManager()
{
    courseRun = new CourseRun(course);

    init();
}

RunManager::~RunManager()
{
    delete courseRun;
}

void RunManager::init()
{
}

void RunManager::run()
{
    switch (state)
    {
    case COURSE_RUN:
        courseRun->run();
        if (courseRun->isFinish())
        {
            //Todo next run status
        }
        break;
    }
}