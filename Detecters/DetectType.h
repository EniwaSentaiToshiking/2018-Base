#include "Detecter.h"
#include "GrayLineDetecter.h"
#include "PointDetecter.h"
#include "DistanceDetecter.h"
#include "DirectionDetecter.h"
#include "AdaptiveDirectionDetecter.h"
#include "ColorDetecter.h"
#include "BlackLineDetecter.h"
#include "BrightnessDetecter.h"
#include "BrightnessLowerDetecter.h"
#include "BrightnessUpperDetecter.h"
#include "ClockDetecter.h"
#include "GotAnswerDetecter.h"

#ifndef DETECTTYPE_H
#define DETECTTYPE_H

enum DetectType {
    POINT, GRAYLINE, DISTANCE, DIRECTION, ADAPTIVEDIRECTION, COLOR, BLACKLINE, BRIGHTNESS, CLOCK, GOT_ANSWER,
    BRIGHTNESSUPPER, BRIGHTNESSLOWER
};

#endif