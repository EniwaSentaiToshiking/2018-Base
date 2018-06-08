#include "UI.h"

UI::UI(){
    touchSensor = new TouchSensorDriver();
}

UI::~UI(){
    delete touchSensor;
}

bool UI::isTouched(){
    return touchSensor->isPressed();
}