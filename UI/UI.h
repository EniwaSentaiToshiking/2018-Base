#include "TouchSensorDriver.h"
using namespace ev3api;

/* LCDフォントサイズ */
#define CALIB_FONT (EV3_FONT_SMALL)
#define CALIB_FONT_WIDTH (6/*TODO: magic number*/)
#define CALIB_FONT_HEIGHT (8/*TODO: magic number*/)

class UI {

private:
    TouchSensorDriver *touchSensor;
    int drawRowCount;

    void initLCD();

public:
	UI();

    /**
     * isTouched - タッチセンサ押下検知
     *
     * @param  {void}
     * @return {bool}      true	押された, false	押されていない 
     */
	bool isTouched(void);

    /**
     * drawStringOnLCD - LCDに文字を描画
     *
     * @param  {const char *string}      *string 表示する文字列
     * @return {bool}      true	押された, false	押されていない 
     */
    void drawStringOnLCD(const char *string);
    virtual ~UI();
};