#include "RunStatus.h"
#include "Course.h"

class AiBlockMove : public RunStatus
{
  private:
    int ana_ansnum = 0;
    int deg_ansnum = 0;
    const int speed = 20;
    const int speed_slow = 10;
    const int block_spin = 30;
    const int angle_spin = 90;
    const float strong_pid[3] = {3.0,0.0,0.05};
    const float nomal_pid[3] =  {2.0,0.0,0.05};
    const int linenear_threshold = 30;
    const int linenomal_threshold = 70;
    const int linefar_threshold =100;
    const int brightness = 10;
    const int blackline = 1;

  public:
    AiBlockMove();
    void init();
    void setNextState();
    void aians_Input(int Predict_Ana_Num , int Predict_Deg_Num);
    virtual ~AiBlockMove();
};
