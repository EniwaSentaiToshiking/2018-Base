#include "CourceMonitor.h"

CourceMonitor::CourceMonitor()
{
    colorSensor = new ColorSensorDriver();
}

CourceMonitor::~CourceMonitor()
{
    delete colorSensor;
}

int CourceMonitor::getCurrentBrightness()
{
    getRawColor();
    int red = getColorRed();
    int green = getColorGreen();
    int blue = getColorBlue();
    return (0.299 * red) + (0.587 * green) + (0.114 * blue);
}

void CourceMonitor::getRawColor(){
	colorSensor->getRawColor();
}

int CourceMonitor::getColorRed(){
	return colorSensor->getColorRed();
}

int CourceMonitor::getColorGreen(){
	return colorSensor->getColorGreen();
}

int CourceMonitor::getColorBlue(){
	return colorSensor->getColorBlue();
}

colorid_t CourceMonitor::getColorNumber()
{
    getRawColor();
    int red = getColorRed();
    int green = getColorGreen();
    int blue = getColorBlue();
    int H = 0;
    int S = 0;
    int max = 0;
    int min = 0;
    colorid_t max_rgb = COLOR_NONE;

    //rgbの最小値計算
    if (red <= green && red <= blue)
    {
        min = red;
    }

    if (green <= red && green <= blue)
    {
        min = green;
    }

    if (blue <= red && blue <= green)
    {
        min = blue;
    }

    //rgbの最大値計算
    if (red >= green && red >= blue)
    {
        max = red;
        max_rgb = COLOR_RED;
    }

    if (green >= red && green >= blue)
    {
        max = green;
        max_rgb = COLOR_GREEN;
    }

    if (blue >= green && blue >= red)
    {
        max = blue;
        max_rgb = COLOR_BLUE;
    }

    if (red == green && green == blue)
    {
        max_rgb = COLOR_NONE;
    }

    //色相を計算
    switch (max_rgb)
    {
    case COLOR_RED:
        H = ((int)(60 * ((green - blue) / (double)(max - min))) + 360) % 360;
        break;
    case COLOR_GREEN:
        H = ((int)(60 * ((blue - red) / (double)(max - min))) + 120) % 360;
        break;
    case COLOR_BLUE:
        H = ((int)(60 * ((red - green) / (double)(max - min))) + 240) % 360;
        break;
    case COLOR_NONE:
        H = 0;
    default:
        break;
    }

    // 彩度を計算
    S = max - min;

    //閾値で色判定
    if (S < 18)
    {
        return COLOR_BLACK;
    }
    else if (H >= 0 && H < 30)
    {
        return COLOR_RED;
    }
    else if (H >= 60 && H < 76)
    {
        return COLOR_YELLOW;
    }
    else if (H >= 100 && H < 130)
    {
        return COLOR_GREEN;
    }
    else if (H >= 155 && H < 210)
    {
        return COLOR_BLUE;
    }
    else if (H)

    return COLOR_NONE;
}