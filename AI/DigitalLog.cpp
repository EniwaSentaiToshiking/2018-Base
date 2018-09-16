#include "DigitalLog.h"
#include "Clock.h"

DigitalLog::DigitalLog() {
  sensor = new CourceMonitor();
  fill(brightnessLog[0], brightnessLog[5], NULL_NUMBER);
}

DigitalLog::~DigitalLog() {
  delete sensor;
}

void DigitalLog::logging() {
  push(sensor->getCurrentBrightness());
}

void DigitalLog::saveLog(char* filename) {
  int writableLog;
  fileLogger = new Logger(filename);
  for(int x=0; x<5; x++) {
    for(int y=0; y<1024; y++) {
      writableLog = brightnessLog[x][y];
      if(writableLog == NULL_NUMBER) break;
      this->fileLogger->logging(writableLog);
    }
    fileLogger->logging(1111);
  }
  delete fileLogger;
}

void DigitalLog::finishLogging() {
  i++;
  j=0;
}

void DigitalLog::push(int x) {
  this->brightnessLog[i][j] = x;
  j++;
}