#ifndef DIGITALLOG_H
#define DIGITALLOG_H

#include "CourceMonitor.h"
#include "Logger.h"
#include <list>
#include <algorithm>

#define NULL_NUMBER -100

using namespace std;

class DigitalLog {
private:
  CourceMonitor* sensor;
  Logger* fileLogger;
public:
  DigitalLog();
  ~DigitalLog();
  void logging();
  void push(int);
  void saveLog(char* filename);
  void finishLogging();
  int i; 
  int j;
  int brightnessLog[5][1024];
};

#endif