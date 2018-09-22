#include "RunStatus.h"
#include "Course.h"
#include "Answer.h"

class AiBlockMove : public RunStatus
{
  private:
    int ana_ansnum = 0;
    int deg_ansnum = 0;
    const int speed = 20;//18
    const int speed_slow = 12;//12
    const int spped_half = 15;
    const int speed_high = 28;//25
    const int block_spin =30;
    const int arm_spin = 130;
    const int tail_spin = 120;//120
    const int angle_spin = 90;
    const int delay_500 = 100;
    const float strong_pid[3] = {1.2,0.0,0.03};
    const float nomal_pid[3] =  {1.3,0.0,0.02};
    const int linenear_threshold = 20;
    const int linenomal_threshold = 80;
    const int linefar_threshold =100;
    const int brightness = 10;
    const int blackline = 1;

  public:
    AiBlockMove();
    void init();
    void setNextState();
    void aians_Input();
    virtual ~AiBlockMove();
};
