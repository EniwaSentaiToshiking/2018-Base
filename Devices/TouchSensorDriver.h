#include "TouchSensor.h"
using namespace ev3api;

#ifndef TOUCHSENSORDRIVER_H
#define TOUCHSENSORDRIVER_H

class TouchSensorDriver {

private:
    TouchSensor *touchSensor;

public:
	TouchSensorDriver();

    /**
     * isPressed - タッチセンサ状態取得 
     *
     * @param  {void}
     * @return {bool}      true	押されている状態, false	押されていない状態 
     */
	bool isPressed();

virtual ~TouchSensorDriver();
};

#endif