#include "RunPattern.h"

RunPattern::RunPattern(Pattern pattern, int speed, DetectType type, float threshold, float p, float i, float d, int brightness)
{
    this->pattern = pattern;
    this->speed = speed;
    this->detectType = type;
    this->threshold = threshold;
    this->brightness = brightness;
    pid = new PID(p, i, d);
    init();
}

RunPattern::RunPattern(Pattern pattern, int speed, Lot *threshold, float p, float i, float d, int brightness){
    this->pattern = pattern;
    this->speed = speed;
    this->detectType = POINT;
    this->nextLot = threshold;
    this->brightness = brightness;
    pid = new PID(p, i, d);
    init();
}

void RunPattern::init(){
    runCommander = new RunCommander();
    armCommander = new ArmCommander();
    tailCommander = new TailCommander();
    createRunStyle();
    createDetecter();
}

RunPattern::~RunPattern()
{
    delete runCommander;
    delete armCommander;
    delete tailCommander;
    delete runStyle;
    delete detecter;
    delete nextLot;
}

void RunPattern::createRunStyle()
{
    switch (this->pattern)
    {
    case LINE_TRACE:
        runStyle = new LineTrace(this->pid, this->brightness);
        break;
    case STRAIGHT:
        runStyle = new Straight(this->speed);
        break;
    case TURNING:
        runStyle = new Turning(this->threshold, this->speed);
        break;
    case SPIN:
        break;
    case BRAKE:
        runStyle = new Straight(this->speed);
        break;
    }
}

void RunPattern::createDetecter()
{

    switch (this->detectType)
    {
    case POINT:
        this->detecter = new PointDetecter(this->nextLot);
        break;
    case GRAYLINE:
        this->detecter = new GrayLineDetecter(this->threshold);
        break;
    case DISTANCE:
        this->detecter = new DistanceDetecter(this->threshold);
        break;
    case DIRECTION:
        this->detecter = new DirectionDetecter(this->threshold);
        break;
    case COLOR:
        this->detecter = new ColorDetecter(this->threshold);
    }
}

bool RunPattern::run()
{
    if(!isInitializeDetecter) {
        detecter->init();
        isInitializeDetecter = true;
    }

    int turn = runStyle->getTurnValue();
    tailCommander->rotateDefault();
    armCommander->rotateDefault();

    if(this->pattern == BRAKE) {
        runCommander->steerStop();
    }else {
        runCommander->steer(this->speed, turn);
    }

    if(detecter->detect()) return true;
    
    return false;
}