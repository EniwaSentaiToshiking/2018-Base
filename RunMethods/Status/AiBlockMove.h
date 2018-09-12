#include "RunStatus.h"
#include "Course.h"

class AiBlockMove : public RunStatus
{
  private:
    Course course;

    void createCourseL();
    void createCourseR();
    int ana_ansnum = 1;
    int deg_ansnum = 1;

  public:
    AiBlockMove(Course course);
    void init();
    void setNextState();
    void aians_Input(int Predict_Ana_Num , int Predict_Deg_Num);
    virtual ~AiBlockMove();
};
