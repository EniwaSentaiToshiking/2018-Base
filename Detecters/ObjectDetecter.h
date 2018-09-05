#include "Detecter.h"
#include "SonarSensorDriver.h"
using namespace ev3api;

#define SONAR_ALERT_DISTANCE 30  /* 超音波センサによる障害物検知距離[cm] */

#ifndef OBJECTDETECTER_H
#define OBJECTDETECTER_H

class ObjectDetecter : public Detecter {

private:
    SonarSensorDriver *sonarSensor;


public:
	ObjectDetecter();

    void init();

    /**
     * detect - 障害物を検出
     *
     * @param  {void}      
     * @return {bool}         true 障害物を検出した, false 超音波信号を検出しなかった 
     */
	bool detect();

virtual ~ObjectDetecter();
};

#endif