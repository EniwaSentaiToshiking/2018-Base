#include "DigitalLog.h"
#include "AnalogLog.h"

#define THRESH_1 50//changed by nagai begore 30
#define THRESH_2 7//changed by nagai before 10


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
