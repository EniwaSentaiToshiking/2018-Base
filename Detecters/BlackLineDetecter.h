#include "Detecter.h"
#include "CourceMonitor.h"
#include "ev3api.h"

#ifndef BRACKLINEDETECTER_H
#define BRACKLINEDETECTER_H

#define WHITE 90 //白値判断基準閾値
#define BLACK 25 //黒値判断基準閾値

typedef enum {
    DISCERN_WHITE1,
    DISCERN_BLACK,
    DISCERN_WHITE2
} discernLine_enum;

class BlackLineDetecter : public Detecter
{
  private:
    CourceMonitor *courceMonitor;
    int threshold;
    discernLine_enum discernLine_state = DISCERN_WHITE1;

  public:
    BlackLineDetecter(int threshold);

    void init();
    /**
     * detect - 黒ラインの条件検知
     *
     * @param  {void}
     * @return {bool}         true 検出した, false 検出しなかった
     */
    bool detect();
    virtual ~BlackLineDetecter();
};

#endif
