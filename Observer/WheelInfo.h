#pragma once
#include "Motor.h"
using namespace ev3api;

class WheelInfo {

private:

public:
    Motor *left;
    Motor *right;
    int32_t currentCount[2] = {0, 0};
    int32_t initCount[2] = {0, 0};

    WheelInfo();

    /**
     * reset - モータリセット モータ停止および角位置の0リセット、オフセット初期化を行う  
     *
     * @param  {void}
     * @return {void}
     */
    void reset();

    int32_t *getInitCount();

    /**
     * getCount - オフセット付き角位置取得 
     *
     * @param  {void}
     * @return {int32_t} モータ角位置 [deg] 
     */
    int32_t *getCount();

    virtual ~WheelInfo();

};