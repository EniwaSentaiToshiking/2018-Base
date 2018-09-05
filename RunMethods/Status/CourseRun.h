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

  public:
    CourseRun(Course course);
    void init();
    virtual ~CourseRun();
};