#include "Detecter.h"
#include "Localization.h"
#include "Lot.h"
#include "ev3api.h"
#include <cstdlib>

#ifndef DISTANCEDETECTER_H
#define DISTANCEDETECTER_H

class DistanceDetecter : public Detecter
{
  private:
    Localization *local;
    int threshold;
    int prev_distance;

  public:
    DistanceDetecter(int threshold);

    void init();
    /**
     * detect - 座標の条件検知
     *
     * @param  {void}      
     * @return {bool}         true 検出した, false 検出しなかった 
     */
    bool detect();
    virtual ~DistanceDetecter();
};

#endif