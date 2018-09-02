#include "Lot.h"

#ifndef DETECTER_H
#define DETECTER_H


enum DetectType {
    POINT, GRAYLINE,
};

class Detecter {

public:
    virtual bool detect() = 0;
    virtual ~Detecter(){};
};

#endif