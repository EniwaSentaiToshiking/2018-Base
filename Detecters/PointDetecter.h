#include "Detecter.h"
#include "Localization.h"
#include "Lot.h"
#include "ev3api.h"

class PointDetecter : public Detecter
{
  private:
    Localization *local;
    Lot *threshold;

  public:
    PointDetecter(Lot *threshold);

    /**
     * detect - 座標の条件検知
     *
     * @param  {void}      
     * @return {bool}         true 検出した, false 検出しなかった 
     */
    bool detect();
    void update(Lot *threshold);
    virtual ~PointDetecter();
};