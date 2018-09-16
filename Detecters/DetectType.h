#include "Detecter.h"
#include "GrayLineDetecter.h"
#include "PointDetecter.h"
#include "DistanceDetecter.h"
#include "DirectionDetecter.h"
#include "ColorDetecter.h"
#include "BlackLineDetecter.h"
#include "BrightnessDetecter.h"
#include "ClockDetecter.h"

#ifndef DETECTTYPE_H
#define DETECTTYPE_H

enum DetectType {
    POINT, GRAYLINE, DISTANCE, DIRECTION, COLOR, BLACKLINE, BRIGHTNESS, CLOCK,
};

#endif