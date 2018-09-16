#include "Detecter.h"
#include "Localization.h"
#include "Lot.h"
#include "ev3api.h"
#include "Logger.h"

#ifndef POINTDETECTER_H
#define POINTDETECTER_H

class PointDetecter : public Detecter
{
  private:
    Localization *local;
    Lot *threshold;

    //Logger *loggerX;
    //Logger *loggerY;

  public:
    PointDetecter(Lot *threshold);

    /**
     * detect - 座標の条件検知
     *
     * @param  {void}      
     * @return {bool}         true 検出した, false 検出しなかった 
     */
    bool detect();
    void init();
    virtual ~PointDetecter();
};

#endif