#include "ColorDetecter.h"

ColorDetecter::ColorDetecter(int threshold)
{
    courceMonitor = new CourceMonitor();
    this->threshold = threshold;
}

ColorDetecter::~ColorDetecter()
{
    delete courceMonitor;
}

void ColorDetecter::init(){
}

bool ColorDetecter::detect()
{
    int currentColor = courceMonitor->getColorNumber();

    color_buffer[color_buffer_num] = currentColor;

    if (color_buffer_num == color_buffer_max - 1)
    {
        color_buffer_num = 0;
    }
    else
    {
        color_buffer_num++;
    }

    color_count++;

    if (color_count > color_buffer_max)
    {
        int count = 0;

        for (int i = 0; i < color_buffer_max; i++)
        {
            if (currentColor == threshold) count++;
        }

    if (count == color_buffer_max)
    {
        return true;
    }
	}

    return false;
}
