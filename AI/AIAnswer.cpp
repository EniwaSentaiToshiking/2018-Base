#include "AIAnswer.h"

AIAnswer::AIAnswer() {
}

AIAnswer::~AIAnswer() {
}

int AIAnswer::answerDigital(DigitalLog* digitalLog) {
  bool answers[5];
  for(int i=0; i<5; i++) {
    answers[i] = answerDigitalSegment(digitalLog->getSeries(i));
  }
  return detectDigitalNumber(answers);
}

bool AIAnswer::answerDigitalSegment(int logSegment[]) {
  int dataTmp;
  int count=0;
  for(int i=0; i<POOL_SIZE; i++) {
    dataTmp = logSegment[i];
    if(dataTmp == NULL_NUMBER) break;
    if(dataTmp < THRESH_1) count++;
  }
  return count>THRESH_2;
}

int AIAnswer::detectDigitalNumber(bool a[]) {
  // this->printResult(a);
  if( a[0] &&  a[1] &&  a[2] && !a[3] &&  a[4]) return 0;
  if( a[0] && !a[1] && !a[2] && !a[3] && !a[4]) return 1;
  if( a[0] && !a[1] &&  a[2] &&  a[3] &&  a[4]) return 2;
  if( a[0] && !a[1] && !a[2] &&  a[3] &&  a[4]) return 3;
  if( a[0] &&  a[1] && !a[2] &&  a[3] && !a[4]) return 4;
  if(!a[0] &&  a[1] && !a[2] &&  a[3] &&  a[4]) return 5;
  if(!a[0] &&  a[1] &&  a[2] &&  a[3] &&  a[4]) return 6;
  if( a[0] && !a[1] && !a[2] && !a[3] &&  a[4]) return 7;
  return 8;
}

void AIAnswer::printResult(bool a[]) {
  char result[10];
  sprintf(result, "%d %d %d %d %d",
    a[0],a[1],a[2],a[3],a[4]);
  
  ev3_lcd_set_font(EV3_FONT_MEDIUM);
  ev3_lcd_draw_string(result, 10, 80);
}

int AIAnswer::answerAnalog(AnalogLog* log) {
  return 0;
}