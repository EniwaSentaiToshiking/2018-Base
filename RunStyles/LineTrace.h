#include "RunStyle.h"
#include "CourceMonitor.h"

class LineTrace : public RunStyle {

private:
    CourceMonitor *courceMonitor;
    PID *pid;
    int targetBrightness = 20;
    int speed = 0;

public:
    LineTrace(PID *pid, int targetBrightness);

    /**
     * getTurnValue - ライントレース時(PID制御)の操作量を取得
     *
     * @param  {void} 
     * @return {int} 操作量
     */
    int getTurnValue();

    /**
     * getTurnValue - ライントレース時(OnOff制御)の操作量を取得
     *
     * @param  {void}
     * @return {int} 操作量
     */
    int getTurnValueByOnOFF();
    virtual ~LineTrace();

};