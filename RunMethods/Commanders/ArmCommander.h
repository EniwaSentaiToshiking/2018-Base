#include "ArmMotorDriver.h"

#ifndef ARMCOMMANDER_H
#define ARMCOMMANDER_H

class ArmCommander {

private:
    ArmMotorDriver *motor;

public:
    ArmCommander();
    
    /**
     * rotate - 腕を動かす
     *
     * @param  {int32_t}     angle	角度 [deg] 
     * @return {void} 
     */
    void rotate(int32_t angle);

    /**
     * rotateDefault - デフォルトの角度(ライントレースする角度)にする
     *
     * @param  {void}
     * @return {void} 
     */
    void rotateDefault();

    /**
     * reset - モータリセット  
     *
     * @param  {void}
     * @return {void}
     */
    void reset();
    virtual ~ArmCommander();
};

#endif