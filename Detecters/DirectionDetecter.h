#include "Detecter.h"
#include "Localization.h"
#include "Lot.h"
#include "ev3api.h"

#ifndef DIRECTIONDETECTER_H
#define DIRECTIONDETECTER_H

class DirectionDetecter : public Detecter
{
  private:
    Localization *local;
    int threshold;
    int prev_direction;

  public:
    DirectionDetecter(int threshold);

    void init();
    /**
     * detect - 座標の条件検知
     *
     * @param  {void}      
     * @return {bool}         true 検出した, false 検出しなかった 
     */
    bool detect();
    virtual ~DirectionDetecter();
};

#endif