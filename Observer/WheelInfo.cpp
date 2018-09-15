#include "WheelInfo.h"

WheelInfo::WheelInfo(){
    left = new Motor(PORT_C);
    right = new Motor(PORT_B);
}

WheelInfo::~WheelInfo(){
    delete left;
    delete right;
}

void WheelInfo::reset(){
    left->reset();
    right->reset();
}

int32_t *WheelInfo::getInitCount(){
    initCount[0] = left->getCount();
    initCount[1] = right->getCount();
    return initCount;
}

int32_t *WheelInfo::getCount(){
    currentCount[0] = left->getCount();
    currentCount[1] = right->getCount();
    return currentCount;
}