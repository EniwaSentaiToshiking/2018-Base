#include "PointDetecter.h"

PointDetecter::PointDetecter(Lot *threshold)
{
    local = new Localization();
    this->threshold = threshold;
}

PointDetecter::~PointDetecter()
{
    delete local;
}

bool PointDetecter::detect()
{
    local->update();

    if (local->point_x > threshold->x0 && local->point_x < threshold->x1)
    {
        if (local->point_y > threshold->y0 && local->point_y < threshold->y1)
        {
            ev3_speaker_play_tone(480, 100);
            return true;
        }
    }
    return false;
}

void PointDetecter::update(Lot *threshold)
{
    this->threshold = threshold;
}