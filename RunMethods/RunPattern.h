#include <typeinfo>
#include "LineTrace.h"
#include "Straight.h"
#include "Turning.h"
#include "Spin.h"
#include "GrayLineDetecter.h"
#include "PointDetecter.h"
#include "DistanceDetecter.h"
#include "DirectionDetecter.h"
#include "ColorDetecter.h"
#include "BrightnessDetecter.h"
#include "Clothoid.h"
#include "DetectType.h"
#include "RunCommander.h"
#include "ArmCommander.h"
#include "TailCommander.h"

#define _USE_MATH_DEFINES
#include <math.h>

#ifndef RUNPATTERN_H
#define RUNPATTERN_H

enum Pattern {
    LINE_TRACE, STRAIGHT, TURNING, SPIN, BRAKE, CLOTHOID,
};

class RunPattern {

private:
    RunCommander *runCommander;
    ArmCommander *armCommander;
    TailCommander *tailCommander;
    RunStyle *runStyle;
    Detecter *detecter;
    Pattern pattern;
    DetectType detectType;
    PID *pid;
    int speed = 0;
    float threshold = 0;
    Lot *nextLot;
    int brightness = 20;
    Edge edge = LEFT;
    TurningDirection direction = DIRECTION_LEFT;
    Compare compare = EQUAL;
    int shouldBeDirection = 999;

    bool isInitializeDetecter = false;

    void createRunStyle();
    void createDetecter();

public:
    //ライントレース or 直進走行
    RunPattern(Pattern pattern, int speed, DetectType type, float threshold, float p = 0.0, float i = 0.0, float d = 0.0, int brightness = 60, Edge edge = LEFT, Compare comp=EQUAL);
    //コース走行
    RunPattern(Pattern pattern, int speed, Lot *threshold, float p = 0.0, float i = 0.0, float d = 0.0, int brightness = 60);
    //旋回走行
    RunPattern(Pattern pattern, int speed, DetectType type, float threshold, TurningDirection direction, int shouldBeDirection);

    void init();

    /**
     * run - 走行する
     *
     * @param  {void}
     * @return {bool}
     */
    bool run();
    virtual ~RunPattern();
};

#endif