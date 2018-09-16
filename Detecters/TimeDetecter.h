#include "Detecter.h"
#include "Clock.h"
using namespace ev3api;

#ifndef TIMEDETECTER_H
#define TIMEDETECTER_H


class TimeDetecter : public Detecter
{
  private:
    Clock *clock;
    int time;
    int threshold;

  public:
    TimeDetecter(int);

    /**
     * detect - 座標の条件検知
     *
     * @param  {void}      
     * @return {bool}         true 検出した, false 検出しなかった 
     */
    bool detect();
    void init();
    virtual ~TimeDetecter();
};

#endif