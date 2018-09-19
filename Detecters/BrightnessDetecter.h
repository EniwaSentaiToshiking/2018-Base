#include "Detecter.h"
#include "CourceMonitor.h"
#include "ev3api.h"

#ifndef BRIGHTNESSDETECTER_H
#define BRIGHTNESSDETECTER_H

enum Compare{
  EQUAL,
  LT,
  GT
};

class BrightnessDetecter : public Detecter
{
  private:
    CourceMonitor *courceMonitor;
    int threshold;
    Compare compare;

  public:
    BrightnessDetecter(int threshold, Compare compare);

    void init();
    /**
     * detect - 色の条件検知
     *
     * @param  {void}      
     * @return {bool}         true 検出した, false 検出しなかった 
     */
    bool detect();
    virtual ~BrightnessDetecter();
};

#endif