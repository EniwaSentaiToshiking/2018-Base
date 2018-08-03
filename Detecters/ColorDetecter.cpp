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
	if (red > 0){
		return 1;//赤
	}else if(green > 0){
		return 2;//青
	}else if(blue > 0){
		return 3;//緑
	}else if(blue > 1){
		return 4;//黄色
	}

	return 0;
}