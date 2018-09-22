#include "Detecter.h"
#include "CourceMonitor.h"
#include "ev3api.h"

#ifndef BRIGHTNESSLOWERDETECTER_H
#define BRIGHTNESSLOWERDETECTER_H

class BrightnessLowerDetecter : public Detecter
{
  private:
    CourceMonitor *courceMonitor;
    int threshold;

  public:
    BrightnessLowerDetecter(int threshold);

    void init();
    /**
     * detect - 色の条件検知
     *
     * @param  {void}      
     * @return {bool}         true 検出した, false 検出しなかった 
     */
    bool detect();
    virtual ~BrightnessLowerDetecter();
};

#endif