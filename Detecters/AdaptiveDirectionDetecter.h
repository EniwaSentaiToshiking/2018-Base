#include "Detecter.h"
#include "Localization.h"
#include "Lot.h"
#include "ev3api.h"
#include "Logger.h"
#include <cmath>

#ifndef ADAPTIVEDIRECTIONDETECTER_H
#define ADAPTIVEDIRECTIONDETECTER_H

class AdaptiveDirectionDetecter : public Detecter
{
  private:
    Localization *local;
    int threshold;
    int prev_direction;
    int direction;
    int absDirection(int);

  public:
    AdaptiveDirectionDetecter(int direction);

    void init();
    /**
     * detect - 座標の条件検知
     *
     * @param  {void}      
     * @return {bool}         true 検出した, false 検出しなかった 
     */
    bool detect();
    virtual ~AdaptiveDirectionDetecter();
};

#endif