#ifndef AIANSWER_H
#define AIANSWER_H

#include "AnalogLog.h"
#include "DigitalLog.h"

class AIAnswer {
public:
  AIAnswer();
  ~AIAnswer();
  int answerAnalog(AnalogLog*);
  int answerDigital(DigitalLog*);
};

#endif