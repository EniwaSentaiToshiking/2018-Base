#include "Wait.h"

Wait::Wait(){
    patterns.push_back(new RunPattern(BRAKE, 0, GOT_ANSWER, 0));
    setNextState();
}

void Wait::setNextState(){
  nextState = AIBLOCKMOVE;
}