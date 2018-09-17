#include "DigitalLog.h"
#include "AnalogLog.h"

#define THRESH_1 70
#define THRESH_2 7


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