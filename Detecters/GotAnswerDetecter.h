#include "Detecter.h"
#include "Answer.h"

#ifndef GOTANSWERDETECTER_H
#define GOTANSWERDETECTER_H

class GotAnswerDetecter : public Detecter
{
  private:
    Answer &answer = Answer::singleton();

  public:
    GotAnswerDetecter();

    void init(){};
    /**
     * detect - 時間の条件検知
     *
     * @param  {void}      
     * @return {bool}         true 検出した, false 検出しなかった 
     */
    bool detect();
    virtual ~GotAnswerDetecter(){};
};

#endif