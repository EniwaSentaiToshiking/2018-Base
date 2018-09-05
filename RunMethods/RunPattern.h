#include <typeinfo>
#include "LineTrace.h"
#include "Straight.h"
#include "Turning.h"
#include "GrayLineDetecter.h"
#include "PointDetecter.h"
#include "DistanceDetecter.h"
#include "DirectionDetecter.h"
#include "RunCommander.h"
#include "ArmCommander.h"
#include "TailCommander.h"

enum Pattern {
    LINE_TRACE, STRAIGHT, TURNING, SPIN,
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
    int brightness = 20;

    bool isInitializeDetecter = false;

    void createRunStyle();
    void createDetecter();

public:
    RunPattern(Pattern pattern, int speed, DetectType type, float threshold, float p = 0.0, float i = 0.0, float d = 0.0, int brightness = 20);

    /**
     * run - 走行する
     *
     * @param  {void}
     * @return {bool}
     */
    bool run();
    virtual ~RunPattern();
};