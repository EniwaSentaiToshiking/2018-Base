#include "RunPattern.h"

RunPattern::RunPattern(Pattern pattern, int speed, DetectType type, float threshold, float p, float i, float d, int brightness)
{
    runCommander = new RunCommander();
    armCommander = new ArmCommander();
    tailCommander = new TailCommander();

    this->pattern = pattern;
    this->speed = speed;
    this->detectType = type;
    this->threshold = threshold;
    this->brightness = brightness;
    pid = new PID(p, i, d);
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
    }
}

void RunPattern::createDetecter()
{

    switch (this->detectType)
    {
    case POINT:
        //detecter = new PointDetecter();
        break;
    case GRAYLINE:
        this->detecter = new GrayLineDetecter();
        break;
    case DISTANCE:
        this->detecter = new DistanceDetecter(this->threshold);
        break;
    case DIRECTION:
        this->detecter = new DirectionDetecter(this->threshold);
        break;
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
    runCommander->steer(this->speed, turn);
    
    if(detecter->detect()) return true;
    
    return false;
}