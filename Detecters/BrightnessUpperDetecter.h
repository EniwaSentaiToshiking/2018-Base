#include "Detecter.h"
#include "CourceMonitor.h"
#include "ev3api.h"

#ifndef BRIGHTNESSUPPERDETECTER_H
#define BRIGHTNESSUPPERDETECTER_H

class BrightnessUpperDetecter : public Detecter
{
  private:
    CourceMonitor *courceMonitor;
    int threshold;

  public:
    BrightnessUpperDetecter(int threshold);

    void init();
    /**
     * detect - 色の条件検知
     *
     * @param  {void}      
     * @return {bool}         true 検出した, false 検出しなかった 
     */
    bool detect();
    virtual ~BrightnessUpperDetecter();
};

#endif