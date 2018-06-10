#include "RunStyle.h"
#include "ColorSensorDriver.h"

#define LIGHT_WHITE          40  /* 白色の光センサ値 */
#define LIGHT_BLACK           0  /* 黒色の光センサ値 */

class LineTrace : public RunStyle {

private:
    ColorSensorDriver *colorSensor;

public:
    LineTrace();
    int getTurnValue();
    int getTurnValueByOnOFF();
    virtual ~LineTrace();

};