#include "AdaptiveDirectionDetecter.h"

AdaptiveDirectionDetecter::AdaptiveDirectionDetecter(int direction)
{
    local = new Localization();
    this->direction= direction;
}

AdaptiveDirectionDetecter::~AdaptiveDirectionDetecter()
{
    delete local;
}

void AdaptiveDirectionDetecter::init(){
    local->update();
}

bool AdaptiveDirectionDetecter::detect()
{
    local->update();
    int direction = absDirection(local->getCurrentDirection()*45.0/44.0);
    return (direction-1 <= this->direction) && (this->direction <= direction+1);
}

int AdaptiveDirectionDetecter::absDirection(int x) {
    if(x>=0) {
        x = x%360;
        if(x>=180) {
           x = x-360; 
        }
    } else {
        x  = -(-x)%360;
        if(x<=180) {
           x = x+360; 
        }
    }
    return x;
}