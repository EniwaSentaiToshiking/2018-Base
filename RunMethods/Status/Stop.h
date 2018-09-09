#include "RunStatus.h"

class Stop : public RunStatus
{
  private:

  public:
    Stop();
    void init(){};
    void setNextState(){};
    virtual ~Stop(){};
};