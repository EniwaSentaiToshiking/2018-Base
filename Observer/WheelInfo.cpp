#include "WheelInfo.h"

WheelInfo::WheelInfo(){
    left = new Motor(PORT_C);
    right = new Motor(PORT_B);
}

WheelInfo::~WheelInfo(){
    reset();
    delete left;
    delete right;
}

void WheelInfo::reset(){
    left->reset();
    right->reset();
}

int32_t *WheelInfo::getCount(){
    count[0] = left->getCount();
    count[1] = right->getCount();
    return count;
}