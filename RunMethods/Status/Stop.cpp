#include "Stop.h"

Stop::Stop(){
    patterns.push_back(new RunPattern(BRAKE, 0, DISTANCE, 30));
}