#ifndef LOTMANAGER_H
#define LOTMANAGER_H

#include "Lot.h"
#include "Localization.h"
#include "ev3api.h"

class LotManager
{

  private:
    int current_lot;
    Lot *lot_list[8];
    Localization *local;

  public:
    LotManager(int flag);
    virtual ~LotManager();

    int getCurrentLot();
    int getCurrentLotSpeed();
    PID *getCurrentLotPID();
    void changeCurrentLot();
    bool isChangeCurrentLot();
    void courseR();
    void courseL();
};

#endif