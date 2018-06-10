#include "LineTrace.h"

LineTrace::LineTrace(){
    pidController = new PIDController();
    colorSensor = new ColorSensorDriver();
}

LineTrace::~LineTrace(){
    delete pidController;
    delete colorSensor;
}

int LineTrace::getTurnValue(){
    //Todo PID制御で計算された操作量を返す
    return 0;
}

int LineTrace::getTurnValueByOnOFF(){
    
    int turn = 0;
    
    if (colorSensor->getBrightness() >= (LIGHT_WHITE + LIGHT_BLACK)/2)
    {
        turn = 30;
    }
    else
    {
        turn = -30;
    }

    return turn;
}