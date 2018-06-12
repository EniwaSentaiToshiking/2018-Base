#include "Filter.h"

Filter::Filter(){

}

Filter::~Filter(){

}

int Filter::lowpass(int value)
{
  buffer[bufferSubscript] = value;

  int lowpassfilteringValue = 0;
  int sum = 0;
  for(int i = 0; i < BUFFER_SIZE; i++)
  {
    sum += buffer[i];
  }
  lowpassfilteringValue = sum/BUFFER_SIZE;
  buffer[bufferSubscript] = lowpassfilteringValue;
  bufferSubscript++;

  if(bufferSubscript > BUFFER_SIZE)
  {
    bufferSubscript = 0;
  }

  return lowpassfilteringValue;
}

int Filter::band(int value, int white, int black)
{
  int bandfilteringValue = BAND_MAX - (BAND_MAX - BAND_MIN)*(float)(value - white) / (black - white);
  return bandfilteringValue;
}
