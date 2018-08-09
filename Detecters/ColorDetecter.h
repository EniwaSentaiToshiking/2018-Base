#include "Detecter.h"
#include "CourceMonitor.h"

enum ColorNum{
	NONE = -1,
    RED = 0,
    YELLOW = 1,
    GREEN = 2,
    BLUE = 3,
    BLACK = 4,
};

class ColorDetecter : public Detecter {

private:
    CourceMonitor *courceMonitor;

public:
	ColorDetecter();

    ColorNum checkRGB();
    ColorNum color_num;
    bool detect();

    virtual ~ColorDetecter();
};