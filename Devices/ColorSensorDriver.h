#include "ColorSensor.h"
using namespace ev3api;

class ColorSensorDriver {

private:
    ColorSensor *colorSensor;

public:
	ColorSensorDriver();

    /**
     * getBrightness - 反射光の強さを測定する 
     *
     * @param  {void}
     * @return {int8_t}      反射光の強さ (0-100) 
     */
	int8_t getBrightness();

    /**
     * getAmbient - 環境光の強さを測定する 
     *
     * @param  {void}
     * @return {uint8_t}      環境光の強さ (0-100) 
     */
    uint8_t getAmbient();

    /**
     * getColorNumber - RGBを測定する 
     *
     * @param  {void}
     * @return {colorid_t}      
     */
    colorid_t getColorNumber(); 

virtual ~ColorSensorDriver();
};