#ifndef AIRUN_H 
#define AIRUN_H

#include "RunStatus.h"
#include "AnalogLog.h"
#include "DigitalLog.h"

enum LogType {
  ANALOG_LOG,
  DIGITAL_LOG,
  NONE_LOG
};

class AIRun : public RunStatus
{
  private:
    unsigned int logPattern[15] = {
      0,0,0,0,0,
      0,0,0,0,0,
      0,0,0,0,0
    };
    AnalogLog* analogLog;
    DigitalLog* digitalLog;
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