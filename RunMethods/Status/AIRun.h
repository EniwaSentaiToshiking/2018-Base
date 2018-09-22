#ifndef AIRUN_H
#define AIRUN_H

#include "RunStatus.h"
#include "AnalogLog.h"
#include "DigitalLog.h"
#include "AIAnswer.h"
#include "Localization.h"
#include "Answer.h"

#define SLOW 10
#define NORMAL 17
#define HIGH 20
#define AI_GREEN_WHITE  70//changed by nagai before 80
#define AI_GREEN_WHITER 85
#define AI_WHITE 95
#define AI_GREEN 45//changed by nagai begore 30
#define EDGE1 40//changed by nagai before 35
#define EDGE2 40


enum LogType {
  ANALOG_LOG,
  DIGITAL_LOG,
  DIGITAL_ANSWER,
  ANALOG_ANSWER,
  LOCALIZATION_RESET,
  NONE_LOG,
};

class AIRun : public RunStatus
{
  private:
    unsigned int logPattern[100] = {
      0,0,0,0,0,0,0,0,0,0,
      0,0,0,0,0,0,0,1,1,0,
      0,0,0,0,0,0,0,0,1,0,
      0,0,0,0,1,1,3,0,0,0,
      0,0,0,0,0,0,0,0,0,0,
      5,0,0,0,2,0,0,0,0,0,
      0,0,0,0,2,0,0,0,0,0,
      0,0,0,2,4,0,0,0,0,0,
      0,0,0,0,0,0,0,0,0,0,
      0,0,0,0,0,0,0,0,0,0,
    };
    AnalogLog* analogLog;
    DigitalLog* digitalLog;
    AIAnswer *answer;
    Localization *localization;
    const float nomal_pid[3] =  {1.3,0.0,0.02};


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
