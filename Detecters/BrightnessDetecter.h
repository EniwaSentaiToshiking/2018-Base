#include "Detecter.h"
#include "CourceMonitor.h"
#include "ev3api.h"

#ifndef BRIGHTNESSDETECTER_H
#define BRIGHTNESSDETECTER_H

class BrightnessDetecter : public Detecter
{
  private:
    CourceMonitor *courceMonitor;
    int threshold;

  public:
    BrightnessDetecter(int threshold);

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