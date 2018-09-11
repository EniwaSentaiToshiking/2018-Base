#include "CourseRun.h"
#include "Parking.h"
#include "Stop.h"

#ifndef RUNMANAGER_H
#define RUNMANAGER_H

class RunManager {

private:
    Course course = L;
    RunState state = COURSE_RUN;
    RunStatus *status;

public:
    RunManager();

    /**
     * init - 走行前の初期設定
     *
     * @param  {void}
     * @return {void}
     */
    void init();

    /**
     * run - 走行する
     *
     * @param  {void}
     * @return {void}
     */
    void run();
    void changeStatus(RunState state);
    virtual ~RunManager();
};

#endif