#include "RunStatus.h"

class Wait : public RunStatus
{
  private:

  public:
    Wait();
    void init(){};
    void setNextState();
    virtual ~Wait(){};
};