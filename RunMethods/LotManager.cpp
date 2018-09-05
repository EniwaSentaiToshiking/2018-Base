#include "LotManager.h"

LotManager::LotManager(Course course)
{
    current_lot = 0;
    /**
     *  Lot
     *  @arg (x0, x1, y0, y1, speed, p, i, d)
     *  @con x0 < x1, y0 < y1
     */
    switch (course)
    {
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
    lot_list[0] = new Lot(-100, 100, -100, 100, 60, 2.0, 0.0, 0.4);
    //lot_list[1] = new Lot(20, 30, -10, 10, 70, 2.5, 0.0, 0.4);
    lot_list[1] = new Lot(20, 30, -10, 10, 80, 1.5, 0.01, 0.18);
    //lot_list[3] = new Lot(200, 220, -20, 20, 80, 3.5, 0.01, 0.7);
    //lot_list[4] = new Lot(180, 210, 80, 130, 80, 2.2, 0.01, 0.4);
    //lot_list[5] = new Lot(140, 160, 80, 120, 80, 3.5, 0.01, 0.7);
    //lot_list[6] = new Lot(100, 120, 10, 40, 80, 3.0, 0.01, 0.7);
    //lot_list[7] = new Lot(30, 60, 0, 50, 80, 3.0, 0.01, 0.7);
    //lot_list[8] = new Lot(30, 60, 70, 90, 80, 2.2, 0.01, 0.4);

    //lot_list[4] = new Lot(160, 180, 100, 120, 90, 3.0, 0.01, 0.7);
    //lot_list[5] = new Lot(10, 30, 90, 110, 90, 2.2, 0.01, 0.7);
    lot_list[2] = new Lot(10000, 20000, 100000, 200000, 20, 5.0, 0.1, 0.0);

    //lot_list[2] = new Lot(50, 80, -30, 30, 40, 0.0, 0.0, 0.0);
    //lot_list[1] = new Lot(10, 20, -10, 10, 60, 6.0, 0.0, 0.5);
}

void LotManager::courseL()
{
    lot_list[0] = new Lot(-100, 100, -100, 100, 60, 2.0, 0.0, 0.4);
    lot_list[1] = new Lot(20, 30, -10, 10, 70, 2.5, 0.0, 0.4);
    lot_list[2] = new Lot(50, 70, -10, 10, 80, 2.0, 0.01, 0.2);

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
    if (current_lot < ARRAY_LEN(this->lot_list))
    {
        return this->lot_list[current_lot + 1];
    }
    else
    {
        return this->defaultLot;
    }
}

void LotManager::changeCurrentLot()
{
    current_lot++;
}

bool LotManager::isFinish()
{
    if (current_lot >= ARRAY_LEN(this->lot_list) - 1)
    {
        return true;
    }
    return false;
}