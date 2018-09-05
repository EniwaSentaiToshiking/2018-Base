#include "CourseRun.h"

//走行状態
enum RunState {
    COURSE_RUN,
    STOP,
};

class RunManager {

private:
    Course course = R;
    RunState state = COURSE_RUN;
    CourseRun *courseRun;

public:
    RunManager();

    /**
     * init - 走行前の初期設定
     *
     * @param  {void}
     * @return {void}
     */
    void init();

    /**
     * run - 走行する
     *
     * @param  {void}
     * @return {void}
     */
    void run();
    virtual ~RunManager();
};