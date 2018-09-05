#include "TailMotorDriver.h"

#ifndef TAILCOMMANDER_H
#define TAILCOMMANDER_H

class TailCommander {

private:
    TailMotorDriver *motor;

public:
    TailCommander();
    
    /**
     * rotate - 腕を動かす
     *
     * @param  {int32_t}     angle	角度 [deg] 
     * @return {void} 
     */
    void rotate(int32_t angle);

    /**
     * rotateDefault - デフォルトの角度(コース走行する角度)にする
     *
     * @param  {void}
     * @return {void} 
     */
    void rotateDefault();

    /**
     * rotateExtend - 尻尾を伸ばす
     *
     * @param  {void}
     * @return {void} 
     */    
    void rotateExtend();

    /**
     * reset - モータリセット  
     *
     * @param  {void}
     * @return {void}
     */
    void reset();
    virtual ~TailCommander();
};

#endif