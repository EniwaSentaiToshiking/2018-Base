#include "Detecter.h"
#include "CourceMonitor.h"

class ColorDetecter : public Detecter {

private:
    CourceMonitor *courceMonitor;

public:
	ColorDetecter();

    int checkRGB();
    int color_num;
    bool detect();

    virtual ~ColorDetecter();
};