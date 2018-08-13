#ifndef LOTMANAGER_H
#define LOTMANAGER_H

#include "Lot.h"
#include "ev3api.h"

#define ARRAY_LEN(ARR) (sizeof(ARR) / sizeof((ARR)[0]))

class LotManager
{

private:
  unsigned int current_lot;
  Lot **lot_list;

public:
  LotManager(Lot *lot_list[]);
  virtual ~LotManager();

  int getCurrentLot();
  int getCurrentLotSpeed();
  PID *getCurrentLotPID();
  Lot *getLotInfo();
  void changeCurrentLot();
  bool isChangeCurrentLot();
  bool isFinish();
};

#endif