#include "DigitalLog.h"
#include "AnalogLog.h"

#define THRESH_1 40
#define THRESH_2 10


class AIAnswer {
private:
  bool answerDigitalSegment(int[]);
  int detectDigitalNumber(bool[]);
  void printResult(bool []);
public:
  int answerDigital(DigitalLog*);
  int answerAnalog(AnalogLog*);
  AIAnswer();
  virtual ~AIAnswer();
};