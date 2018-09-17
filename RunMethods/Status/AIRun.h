#ifndef AIRUN_H 
#define AIRUN_H

#include "RunStatus.h"
#include "AnalogLog.h"
#include "DigitalLog.h"
#include "AIAnswer.h"

#define SPEED 10

enum LogType {
  ANALOG_LOG,
  DIGITAL_LOG,
  END_LOG,
  NONE_LOG,
};

class AIRun : public RunStatus
{
  private:
    unsigned int logPattern[70] = {
      0,0,0,0,0,0,0,0,0,0,
      0,0,1,1,0,0,0,0,0,0,
      0,0,0,1,0,0,0,0,0,1,
      1,0,0,0,0,0,0,2,0,0,
      0,0,0,0,0,0,0,0,2,0,
      0,0,0,0,0,0,3,0,0,0,
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