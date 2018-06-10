#include "Detecter.h"
#include "CourceMonitor.h"
#include "ev3api.h"

#define gray_buffer_max 1000
#define gray_limit 4

class GrayLineDetecter : public Detecter {

private:
    CourceMonitor *courceMonitor;

    int gray_buffer[gray_buffer_max] = {};
    int gray_buffer_num = 0;
    int gray_count = 0;

public:
	GrayLineDetecter();

    /**
     * detect - 灰色検出
     *
     * @param  {void}      
     * @return {bool}         true 検出した, false 検出しなかった 
     */
	bool detect();
    virtual ~GrayLineDetecter();
};