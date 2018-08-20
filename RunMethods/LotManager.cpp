#include "LotManager.h"

LotManager::LotManager(Course course)
{
    current_lot = 0;
    /**
     *  Lot
     *  @arg (x0, x1, y0, y1, speed, p, i, d)
     *  @con x0 < x1, y0 < y1
     */
    switch(course){
        case L:
            courseL();
        break;
        case R:
            courseR();
        break;
    }
}

LotManager::~LotManager()
{
}

void LotManager::courseR()
{
    lot_list[0] = new Lot(0, 180, -30, 30, 20, 0.0, 0.0, 0.0);
    lot_list[1] = new Lot(30, 50, -30, 30, 30, 0.0, 0.0, 0.0);
    lot_list[2] = new Lot(50, 80, -30, 30, 40, 0.0, 0.0, 0.0);
    lot_list[3] = new Lot(50000, 800000, -30, 30, 40, 0.0, 0.0, 0.0);
}

void LotManager::courseL()
{
    lot_list[0] = new Lot(0, 180, -30, 30, 20, 5.0, 0.1, 0.0);
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

Lot *LotManager::getNextLotInfo()
{
    return this->lot_list[current_lot + 1];
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