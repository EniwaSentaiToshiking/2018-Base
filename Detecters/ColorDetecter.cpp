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
		max_rgb = BLUE;
	}

	if(blue >= green && blue >= green){
		max = blue;
		max_rgb = GREEN;
	}

	if(red == green && green == blue){
		max_rgb = NONE;
	}


	//色相を計算
	switch(max_rgb) {
        case RED:
        	H = 60 * ((green - blue)/(max - min));
        	break;
        case GREEN:
        	H = 60 * ((blue - red)/(max - min)) + 120;
        	break;
        case BLUE:
        	H = 60 * ((red - green)/(max - min)) + 240;
        	break;
        case NONE:
        	H = 0;
        default:
        	break;
    }

	//閾値で色判定
	if (H > 0 && H <= 10){
		return RED;
	}else if(H >= 50 && H <= 75){
		return YELLOW;
	}else if(H >= 100 && H <= 120){
		return GREEN;
	}else if(H >= 180 && H <= 210){
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