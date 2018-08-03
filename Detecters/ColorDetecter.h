#include "Detecter.h"
#include "CourceMonitor.h"

class ColorDetecter : public Detecter {

private:
    CourceMonitor *courceMonitor;

public:
	ColorDetecter();

    int checkRGB();

    virtual ~ColorDetecter();
};