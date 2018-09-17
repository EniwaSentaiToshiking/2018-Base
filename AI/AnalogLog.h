#ifndef ANALOGLOG_H
#define ANALOGLOG_H

#include "CourceMonitor.h"
#include "Logger.h"
#include <vector>

#define NULL_NUMBER -100
#define POOL_SIZE 1024 

using namespace std;

class AnalogLog {
private:
  CourceMonitor* sensor;
  Logger* fileLogger;
public:
  AnalogLog();
  ~AnalogLog();
  void logging();
  void saveLog(char* filename);
  void finishLogging();
  int* getSeries(int x);
  int i = 0;
  int j = 0;
  int brightnessLog[2][POOL_SIZE];
};

#endif