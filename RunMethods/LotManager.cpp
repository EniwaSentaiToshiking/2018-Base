#include "LotManager.h"

LotManager::LotManager(Lot *lot_list[])
{
    current_lot = 0;

    /**
     *  Lot
     *  @arg (x0, x1, y0, y1, speed, p, i, d)
     *  @con x0 < x1, y0 < y1
     */
    this->lot_list = lot_list;
}

LotManager::~LotManager()
{
}

int LotManager::getCurrentLot()
{
    return current_lot;
}

int LotManager::getCurrentLotSpeed()
{
    return this->lot_list[current_lot]->speed;
}

PID *LotManager::getCurrentLotPID()
{
    return this->lot_list[current_lot]->pid;
}

Lot *LotManager::getLotInfo()
{
    return this->lot_list[current_lot];
}

void LotManager::changeCurrentLot()
{
    current_lot++;
}

bool LotManager::isFinish()
{
    if (current_lot >= ARRAY_LEN(this->lot_list))
    {
        return true;
    }
    return false;
}