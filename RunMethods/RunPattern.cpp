#include "RunPattern.h"

RunPattern::RunPattern(Pattern pattern, int speed, DetectType type, float threshold, float p, float i, float d, int brightness, Edge edge)
{
    this->pattern = pattern;
    this->speed = speed;
    this->detectType = type;
    this->threshold = threshold;
    this->brightness = brightness;
    this->edge = edge;
    pid = new PID(p, i, d);
    init();
}

RunPattern::RunPattern(Pattern pattern, int speed, Lot *threshold, float p, float i, float d, int brightness)
{
    this->pattern = pattern;
    this->speed = speed;
    this->detectType = POINT;
    this->nextLot = threshold;
    this->brightness = brightness;
    pid = new PID(p, i, d);
    init();
}

RunPattern::RunPattern(Pattern pattern, int speed, DetectType type, float threshold, TurningDirection direction)
{
    this->pattern = pattern;

    if (this->pattern == SPIN)
    {
        this->speed = abs(speed);
    }
    else
    {
        this->speed = speed;
    }
    this->detectType = type;
    this->threshold = threshold;
    this->direction = direction;
    init();
}

void RunPattern::init()
{
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
        runStyle = new LineTrace(this->pid, this->brightness, this->edge);
        break;
    case STRAIGHT:
        runStyle = new Straight(this->speed);
        break;
    case TURNING:
        runStyle = new Turning(this->direction, this->speed);
        break;
    case SPIN:
        runStyle = new Spin(this->direction, this->speed);
        break;
    case CLOTHOID:
        runStyle = new Clothoid(this->direction, this->speed);
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
    case ADAPTIVEDIRECTION:
        this->detecter = new AdaptiveDirectionDetecter(this->threshold);
        break;
    case COLOR:
        this->detecter = new ColorDetecter(this->threshold);
        break;
    case BLACKLINE:
        this->detecter = new BlackLineDetecter(this->threshold);
        break;
    case BRIGHTNESS:
        this->detecter = new BrightnessDetecter(this->threshold);
        break;
    case CLOCK:
        this->detecter = new ClockDetecter(this->threshold);
        break;
    }
}

bool RunPattern::run()
{
    if (!isInitializeDetecter)
    {
        detecter->init();
        runStyle->init();
        isInitializeDetecter = true;
    }

    int turn = runStyle->getTurnValue();
    tailCommander->rotateDefault();
    armCommander->rotateDefault();

    if (this->pattern == BRAKE)
    {
        runCommander->steerStop();
    }
    else
    {
        runCommander->steer(this->speed, turn);
    }

    if (detecter->detect())
        return true;

    return false;
}