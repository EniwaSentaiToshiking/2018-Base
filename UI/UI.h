#include "TouchSensorDriver.h"
using namespace ev3api;

class UI {

private:
    TouchSensorDriver *touchSensor;

public:
	UI();

    /**
     * isTouched - タッチセンサ押下検知
     *
     * @param  {void}
     * @return {bool}      true	押された, false	押されていない 
     */
	bool isTouched(void);

virtual ~UI();
};