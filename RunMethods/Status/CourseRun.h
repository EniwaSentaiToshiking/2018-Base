#include "RunStatus.h"

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
    bool isFinish();
    virtual ~CourseRun();
};