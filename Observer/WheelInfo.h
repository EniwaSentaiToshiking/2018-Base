#pragma once
#include "Motor.h"
using namespace ev3api;

class WheelInfo {

private:

public:
    Motor *left;
    Motor *right;
    int32_t count[2] = {0, 0};

    WheelInfo();

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
    int32_t *getCount();

    virtual ~WheelInfo();

};