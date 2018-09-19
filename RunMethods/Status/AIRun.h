#ifndef AIRUN_H 
#define AIRUN_H

#include "RunStatus.h"
#include "AnalogLog.h"
#include "DigitalLog.h"
#include "AIAnswer.h"
#include "Localization.h"

#define SLOW 10
#define NORMAL 17
#define HIGH 20
#define AI_GREEN_WHITE  100
#define AI_GREEN_WHITER 110
#define AI_WHITE 120
#define EDGE 50


enum LogType {
  ANALOG_LOG,
  DIGITAL_LOG,
  DIGITAL_ANSWER,
  ANALOG_ANSWER,
  NONE_LOG,
};

class AIRun : public RunStatus
{
  private:
    unsigned int logPattern[90] = {
      0,0,0,0,0,0,0,0,0,0,
      0,0,0,0,0,0,0,1,1,0,
      0,0,0,0,0,0,0,0,1,0,
      0,0,0,0,1,1,3,0,0,0,
      0,0,0,0,0,0,0,0,0,0,
      0,0,0,0,0,0,0,0,2,0,
      0,0,0,0,0,0,0,0,0,0,
      1,4,0,0,0,0,0,0,0,0,
      0,0,0,0,0,0,0,0,0,0,
    };
    AnalogLog* analogLog;
    DigitalLog* digitalLog;
    AIAnswer *answer;

  public:
    AIRun();
    void init();
    void setNextState();
    virtual ~AIRun();
    virtual bool run();
    LogType shouldLogging();
    void saveLog();
};

#endif