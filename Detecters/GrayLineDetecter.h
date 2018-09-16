#include "Detecter.h"
#include "CourceMonitor.h"
#include "ev3api.h"

#define gray_buffer_max 40

#ifndef GRAYLINEDETECTER_H
#define GRAYLINEDETECTER_H

class GrayLineDetecter : public Detecter {

private:
    CourceMonitor *courceMonitor;

    int gray_buffer[gray_buffer_max] = {};
    int gray_buffer_num = 0;
    int gray_count = 0;
    int threshold = 4;

public:
	GrayLineDetecter(int threshold = 4);

    /**
     * detect - 灰色検出
     *
     * @param  {void}      
     * @return {bool}         true 検出した, false 検出しなかった 
     */
	bool detect();
    void init();
    virtual ~GrayLineDetecter();
};

#endif