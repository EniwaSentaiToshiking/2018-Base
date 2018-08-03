#include "RunCommander.h"
#include "ArmCommander.h"
#include "TailCommander.h"
#include "LineTrace.h"
#include "Localization.h"
#include "LotManager.h"
#include "CourceMonitor.h"

//#include "Logger.h"

class RunManager {

private:
    RunCommander *runCommander;
    ArmCommander *armCommander;
    TailCommander *tailCommander;
    LineTrace *lineTrace;
    Localization *localization;
    LotManager *lotManager;
    CourceMonitor *courceMonitor;

    //Logger *logger1;
    //Logger *logger2;

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