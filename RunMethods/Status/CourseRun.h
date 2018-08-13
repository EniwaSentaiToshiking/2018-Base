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
    void init();

  public:
    CourseRun(Course course);

    /**
     * run - 走行状態に応じた走行をする
     *
     * @param  {void}      
     * @return {void}
     */
    void run();
    bool isFinish();
    virtual ~CourseRun();
};