#ifndef ANALOGLOG_H
#define ANALOGLOG_H

class AnalogLog {
public:
  AnalogLog();
  ~AnalogLog();
  void logging();
  void saveLog(char* filename);
  void finishLogging();
private:
};

#endif