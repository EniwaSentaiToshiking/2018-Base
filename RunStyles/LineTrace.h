#include "RunStyle.h"
#include "CourceMonitor.h"

class LineTrace : public RunStyle {

private:
    CourceMonitor *courceMonitor;
    PID *pid;
    int targetBrightness = 20;
    int absMaxSpeed = 30;

public:
    LineTrace();

    /**
     * updateParams - パラメータ設定
     *
     * @param  {PID, int, int} pid PID係数, absMaxSpeed 絶対値（最大PWM）, targetBrightness 目標輝度
     * @return {void}
     */
    void updateParams(PID *pid, int absMaxSpeed, int targetBrightness = 10);

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