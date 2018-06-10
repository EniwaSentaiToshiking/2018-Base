#include "GrayLineDetecter.h"

GrayLineDetecter::GrayLineDetecter(){

}

GrayLineDetecter::~GrayLineDetecter(){
    
}

bool GrayLineDetecter::detect(){
   
   //Todo 現在の輝度値を取得する
    int current_color = 0;

    gray_buffer[gray_buffer_num] = current_color;

    if (gray_buffer_num == gray_buffer_max-1)
    {
        gray_buffer_num = 0;
    }
    else
    {
        gray_buffer_num++;
    }

    gray_count++;

    if (gray_count == gray_buffer_max)
    {
        ev3_speaker_play_tone(480, 100);
    }

    if(gray_count > 1400){
      int sum = 0;

      for (int i = 0; i < gray_buffer_max; i++){
        sum = sum + gray_buffer[i];
      }

      float average = ((float)sum / (float)(gray_buffer_max + 1));

      if (-((float)current_color - average) > gray_limit){  //取得した輝度値（黒）-平均値（灰色）>閾値,color<灰色,count>灰色をとる時間
        return true;
      }
    }
    return false;
}