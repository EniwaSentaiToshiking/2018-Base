#include "Lot.h"

#ifndef DETECTER_H
#define DETECTER_H


enum DetectType {
    POINT, GRAYLINE, DISTANCE,
};

class Detecter {

public:
    virtual bool detect() = 0;
    virtual void init() = 0;
    virtual ~Detecter(){};
};

#endif