#include "GotAnswerDetecter.h"

GotAnswerDetecter::GotAnswerDetecter(){

}

bool GotAnswerDetecter::detect()
{
    return answer.hasAnswer;
}