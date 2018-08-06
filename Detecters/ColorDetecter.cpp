#include "ColorDetecter.h"

ColorDetecter::ColorDetecter(){
    courceMonitor = new CourceMonitor();
}

ColorDetecter::~ColorDetecter(){    
	delete courceMonitor;
}

int ColorDetecter::checkRGB(){
	courceMonitor->getRawColor();
	int red = courceMonitor -> getColorRed();
	int green = courceMonitor -> getColorGreen();
	int blue = courceMonitor -> getColorBlue();
	int H = 0;
	int max = 0;
	int min = 0;
	int max_flag = 0; //赤1,緑2,青3

	if(red >= green && red >= blue){
		max = red;
		max_flag = 1;
	}

	if(green >= red && green >= blue){
		max = green;
		max_flag = 2;
	}

	if(blue >= green && blue >= green){
		max = blue;
		max_flag = 3;
	}

	if(red <= green && red <= blue){
		min = red;
	}

	if(green <= red && green <= blue){
		min = green;
	}

	if(blue <= green && blue <= green){
		min = blue;
	}

	//色合いを計算

	if(max_flag == 1){
		H = 60 * ((green - blue)/(max - min));
	}

	if(max_flag == 1){
		H = 60 * ((blue - red)/(max - min)) + 120;
	}

	if(max_flag == 1){
		H = 60 * ((red - green)/(max - min)) + 240;
	}

	if (red == green && green == blue){
		 H = 0;
	}

	//閾値で色判定
	if (H >= 0 && H <= 10){
		return 1;//赤
	}else if(H >= 50 && H <= 75){
		return 2;//黄色
	}else if(H >= 100 && H <= 120){
		return 3;//緑
	}else if(H >= 180 && H <= 210){
		return 4;//青
	}

	return 0;
}

bool ColorDetecter::detect(){
	if(color_num == checkRGB()){
		return true;
	}
	return false;
}