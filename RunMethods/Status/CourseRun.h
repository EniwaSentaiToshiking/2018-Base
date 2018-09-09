#include "RunStatus.h"

enum Course
{
    L,
    R
};

class CourseRun : public RunStatus
{
  private:
    Course course;
    vector<Lot *> lots;

    void createCourseL();
    void createCourseR();

  public:
    CourseRun(Course course);
    void init();
    void setNextState();
    virtual ~CourseRun();
};