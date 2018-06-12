#include "LotManager.h"

LotManager::LotManager(int flag)
{
    current_lot = 0;

    /**
     *  Lot
     *  @arg (x0, x1, y0, y1, speed, p, i, d)
     *  @con x0 < x1, y0 < y1
     */

    if(flag==0){
        courseR();
    }else{
        courseL();
    }

    local = new Localization();

}

LotManager::~LotManager()
{
    delete local;
}

void LotManager::courseR()
{
    lot_list[0] = new Lot(0, 180, -30, 30, 30, 0.4, 0.01, 0.03);
}

void LotManager::courseL()
{
    lot_list[0] = new Lot(0, 180, -30, 30, 30, 0.4, 0.01, 0.03);
}


int LotManager::getCurrentLot()
{
    return current_lot;
}

int LotManager::getCurrentLotSpeed()
{
    return lot_list[current_lot]->speed;
}

PID *LotManager::getCurrentLotPID()
{
    return lot_list[current_lot]->pid;
}

void LotManager::changeCurrentLot()
{
    current_lot++;
    ev3_speaker_play_tone(880, 100);
}

bool LotManager::isChangeCurrentLot()
{
    local->update();

    if (current_lot < int((sizeof(lot_list) / sizeof(lot_list[0]) - 1)))
    {
        int next_lot = current_lot + 1;

        if (local->point_x > lot_list[next_lot]->x0 && local->point_x < lot_list[next_lot]->x1){
            if (local->point_y > lot_list[next_lot]->y0 && local->point_y < lot_list[next_lot]->y1){
                ev3_speaker_play_tone (480,100);
                return true;
            }
        }
    }

    return false;
}
