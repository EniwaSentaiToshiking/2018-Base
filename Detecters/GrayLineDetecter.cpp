#include "GrayLineDetecter.h"

GrayLineDetecter::GrayLineDetecter(int threshold)
{
    courceMonitor = new CourceMonitor();
    this->threshold = threshold;
}

GrayLineDetecter::~GrayLineDetecter()
{
}

void GrayLineDetecter::init() {}

bool GrayLineDetecter::detect()
{

    int current_color = courceMonitor->getCurrentBrightness();
    gray_buffer[gray_buffer_num] = current_color;

    if (gray_buffer_num == gray_buffer_max - 1)
    {
        gray_buffer_num = 0;
    }
    else
    {
        gray_buffer_num++;
    }

    gray_count++;

    if (gray_count > gray_buffer_max)
    {
        int count = 0;

        for (int i = 0; i < gray_buffer_max; i++)
        {
            if (gray_buffer[i] >= this->threshold && gray_buffer[i] < 75) count++;
        }

    if (count == gray_buffer_max)
    { //取得した輝度値（黒）-平均値（灰色）>閾値,color<灰色,count>灰色をとる時間
        ev3_speaker_play_tone(480, 100);
        return true;
    }
}
return false;
}