#include "SonarSensor.h"
using namespace ev3api;

class SonarSensorDriver {

private:
    SonarSensor *sonarSensor;

public:
	SonarSensorDriver();

    /**
     * getDistance - 超音波センサで障害物の距離を測定
     *
     * @param  {void}
     * @return {int16_t}      障害物との距離
     */
	int16_t getDistance();
    
    /**
     * getListen - 超音波信号を検出する 
     *
     * @param  {void}
     * @return {bool}         true 超音波信号を検出した, false 超音波信号を検出しなかった 
     */
    bool getListen();

virtual ~SonarSensorDriver();
};