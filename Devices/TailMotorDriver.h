#include "Motor.h"
using namespace ev3api;

#ifndef TAILMOTORDRIVER_H
#define TAILMOTORDRIVER_H

class TailMotorDriver {

private:
    Motor *motor;
    const int DEFAULT_ANGLE = 0;
    const int EXTEND_ANGLE = 4800;

    const int KP = 2.5F;
    const int PWM_ABS_MAX = 60;

public:
    TailMotorDriver();

    /**
     * reset - モータリセット モータ停止および角位置の0リセット、オフセット初期化を行う  
     *
     * @param  {void}
     * @return {void}
     */
    void reset();

    /**
     * getCount - オフセット付き角位置取得 
     *
     * @param  {void}
     * @return {int32_t} モータ角位置 [deg] 
     */
    int32_t getCount();

    /**
     * rotate - 尻尾を動かす
     *
     * @param  {int32_t}     angle	角度 [deg] 
     * @return {void} 
     */
    void rotate(int32_t angle);

    /**
     * rotateDefault - 尻尾を動かす
     *
     * @param  {void}
     * @return {void} 
     */
    void rotateDefault();

    /**
     * rotateExtend - 尻尾を動かす
     *
     * @param  {void}
     * @return {void} 
     */    
    void rotateExtend();

    virtual ~TailMotorDriver();

};

#endif