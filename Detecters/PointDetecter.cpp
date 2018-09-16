#include "PointDetecter.h"

PointDetecter::PointDetecter(Lot *threshold)
{
    local = new Localization();
    this->threshold = threshold;
    //loggerX = new Logger("point_x.txt");
    //loggerY = new Logger("point_y.txt");
}

PointDetecter::~PointDetecter()
{
    delete local;
}

void PointDetecter::init(){}

bool PointDetecter::detect()
{
    local->update();

    //loggerX -> logging(local->point_x);
    //loggerY -> logging(local->point_y);

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