#include "RunStyle.h"

RunStyle::RunStyle(){
    this->pidController = new PIDController();
}

RunStyle::~RunStyle(){
    delete pidController;
    delete pid;
}
