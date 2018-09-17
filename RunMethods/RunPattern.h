#include <typeinfo>
#include "LineTrace.h"
#include "Straight.h"
#include "Turning.h"
#include "Spin.h"
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

    bool isInitializeDetecter = false;

    void createRunStyle();
    void createDetecter();

public:
    //ライントレース or 直進走行
    RunPattern(Pattern pattern, int speed, DetectType type, float threshold, float p = 0.0, float i = 0.0, float d = 0.0, int brightness = 60, Edge edge = LEFT);
    //コース走行
    RunPattern(Pattern pattern, int speed, Lot *threshold, float p = 0.0, float i = 0.0, float d = 0.0, int brightness = 60);
    //旋回走行
    RunPattern(Pattern pattern, int speed, DetectType type, float threshold, TurningDirection direction);

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