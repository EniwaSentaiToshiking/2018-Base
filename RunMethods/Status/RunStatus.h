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

class RunStatus
{
  protected:
    vector<RunPattern *> patterns;
    unsigned int currentPattern = 0;

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
    virtual bool changeNextPattern();
    virtual ~RunStatus();
};

#endif