#include "AnalogLog.h"

AnalogLog::AnalogLog() {
  sensor = new CourceMonitor();
  fill(brightnessLog[0], brightnessLog[2], NULL_NUMBER);
}

AnalogLog::~AnalogLog() {
  delete sensor;
}

void AnalogLog::logging() {
  brightnessLog[i][j] = sensor->getCurrentBrightness();
  j++;
}

void AnalogLog::finishLogging() {
  i++;
  j=0;
}

int* AnalogLog::getSeries(int i) {
  return this->brightnessLog[i];
}

void AnalogLog::saveLog(char* filename) {
  int writableLog;
  fileLogger = new Logger(filename);
  for(int x=0; x<2; x++) {
    for(int y=0; y<POOL_SIZE; y++) {
      writableLog = brightnessLog[x][y];
      if(writableLog == NULL_NUMBER) break;
      this->fileLogger->logging(writableLog);
    }
    fileLogger->logging(1111);
  }
  delete fileLogger;
}

void AnalogLog::sendToServer() {
  int writableLog;
  FILE* bt = ev3_serial_open_file(EV3_SERIAL_BT);
  assert(bt != NULL);
  for(int x=0; x<2; x++) {
    for(int y=0; y<POOL_SIZE; y++) {
      writableLog = brightnessLog[x][y];
      if(writableLog == NULL_NUMBER) break;
      fprintf(bt, "%d\n", writableLog);
    }
  }
  fprintf(bt, "%c\n", '.');
  fclose(bt);
}
