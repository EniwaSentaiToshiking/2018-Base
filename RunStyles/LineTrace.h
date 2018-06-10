#include "RunStyle.h"
#include "CourceMonitor.h"

#define LIGHT_WHITE          40  /* 白色の光センサ値 */
#define LIGHT_BLACK           0  /* 黒色の光センサ値 */

class LineTrace : public RunStyle {

private:
    CourceMonitor *courceMonitor;
    int targetBrightness = 0;

public:
    LineTrace();
    int getTurnValue();
    int getTurnValueByOnOFF();
    void setTargetBrightness();
    virtual ~LineTrace();

};