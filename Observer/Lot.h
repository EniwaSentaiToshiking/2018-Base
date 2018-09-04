#ifndef LOT_H
#define LOT_H

#include "PID.h"

class Lot
{
public:
  float x0, y0;
  float x1, y1;

  Lot(float x0, float x1, float y0, float y1);
  virtual ~Lot();
};

#endif