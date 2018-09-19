#include "RunPattern.h"
#include <vector>
#include <algorithm>

using namespace std;

#ifndef RUNSTATUS_H
#define RUNSTATUS_H

struct DeleteObject
{
    template <typename T>
    void operator()(const T *ptr) const
    {
        delete ptr;
    }
};

//走行状態
enum RunState {
    COURSE_RUN,
    PARKING,
    STOP,
    GAME,
    AIBLOCKMOVE,
    AI_RUN,
};

class RunManager;

class RunStatus
{
  protected:
    vector<RunPattern *> patterns;
    unsigned int currentPattern = 0;
    RunState nextState;

  public:
    /**
     * init - 走行前の初期設定
     *
     * @param  {void}
     * @return {void}
     */
    virtual void init() = 0;

    /**
     * run - 走行する
     *
     * @param  {void}
     * @return {bool}
     */
    virtual bool run();
    virtual void setNextState() = 0;
    virtual bool changeNextPattern();
    virtual void changeNextStatus(RunManager *manager);
    virtual ~RunStatus();
};

#endif
