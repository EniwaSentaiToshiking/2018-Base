#include "Detecter.h"
#include "CourceMonitor.h"
#include "ev3api.h"

#ifndef COLORDETECTER_H
#define COLORDETECTER_H

class ColorDetecter : public Detecter
{
  private:
    CourceMonitor *courceMonitor;
    int threshold;

  public:
    ColorDetecter(int threshold);

    void init();
    /**
     * detect - 色の条件検知
     *
     * @param  {void}      
     * @return {bool}         true 検出した, false 検出しなかった 
     */
    bool detect();
    virtual ~ColorDetecter();
};

#endif