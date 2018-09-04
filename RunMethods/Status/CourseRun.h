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
    /**
     * run - 走行状態に応じた走行をする
     *
     * @param  {void}      
     * @return {void}
     */
    void run();
    void stop();
    bool isFinish();
    virtual ~CourseRun();
};