#include "ColorDetecter.h"

ColorDetecter::ColorDetecter(){
    courceMonitor = new CourceMonitor();
}

ColorDetecter::~ColorDetecter(){    
	delete courceMonitor;
}

ColorNum ColorDetecter::checkRGB(){
	courceMonitor->getRawColor();
	int red = courceMonitor -> getColorRed();
	int green = courceMonitor -> getColorGreen();
	int blue = courceMonitor -> getColorBlue();
	int H = 0;
  int S = 0;
	int max = 0;
	int min = 0;
	ColorNum max_rgb = NONE;

	//rgbの最小値計算
	if(red <= green && red <= blue){
		min = red;
	}

	if(green <= red && green <= blue){
		min = green;
	}

	if(blue <= red && blue <= green){
		min = blue;
	}

	//rgbの最大値計算
	if(red >= green && red >= blue){
		max = red;
		max_rgb = RED;
	}

	if(green >= red && green >= blue){
		max = green;
		max_rgb = GREEN;
	}

	if(blue >= green && blue >= red){
		max = blue;
		max_rgb = BLUE;
	}

	if(red == green && green == blue){
		max_rgb = NONE;
	}


	//色相を計算
	switch(max_rgb) {
        case RED:
        	H = ((int)(60 * ((green-blue)/(double)(max-min)))+360)%360;
        	break;
        case GREEN:
        	H = ((int)(60 * ((blue-red)/(double)(max-min)))+120)%360;
        	break;
        case BLUE:
        	H = ((int)(60 * ((red-green)/(double)(max-min)))+240)%360;
        	break;
        case NONE:
        	H = 0;
        default:
        	break;
    }

	// 彩度を計算
	S = max - min;

	//閾値で色判定
  if(S < 20) {
    return BLACK;
  } else if (H >= 0 && H < 30){
		return RED;
	}else if(H >= 60 && H < 76){
		return YELLOW;
	}else if(H >= 100 && H < 117){
		return GREEN;
	}else if(H >= 155 && H < 197 ){
		return BLUE;
	}

	return NONE;
}

bool ColorDetecter::detect(){
	if(color_num == checkRGB()){
		return true;
	}
	return false;
}
