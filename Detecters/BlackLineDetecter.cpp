#include "BlackLineDetecter.h"

BlackLineDetecter::BlackLineDetecter(int threshold)
{
    courceMonitor = new CourceMonitor();
    this->threshold = threshold;
}

BlackLineDetecter::~BlackLineDetecter()
{
    delete courceMonitor;
}

void BlackLineDetecter::init(){
}

bool BlackLineDetecter::detect() {
    int color_sensor_reflect = courceMonitor->getCurrentBrightness();

    switch (discernLine_state) {
    case DISCERN_WHITE1: // 白を検知
        if(color_sensor_reflect >= WHITE) {
            discernLine_state = DISCERN_BLACK;
        }
        break;
    case DISCERN_BLACK: // 黒を検知
        if(color_sensor_reflect <= BLACK ) {
            discernLine_state = DISCERN_WHITE2;
            if(threshold == 0){
                return true;
            }
        }
        break;
    case DISCERN_WHITE2: // 白を検知
        if(color_sensor_reflect >= WHITE) {
            discernLine_state = DISCERN_WHITE1;
            return true;
        }
        break;
    default:
        break;
    }

    return false;
}