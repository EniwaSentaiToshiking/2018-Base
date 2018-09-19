#include "CourseRun.h"

CourseRun::CourseRun(Course course){
    this->course = course;

    if(this->course == L) {
        createCourseL();
    }else if(this->course == R){
        createCourseR();
    }

    setNextState();
}

CourseRun::~CourseRun(){
    for_each(lots.begin(), lots.end(), DeleteObject());
    lots.clear();
}

void CourseRun::init(){
}

void CourseRun::setNextState(){
    if(this->course == L) {
        nextState = AI_RUN;
    }else if(this->course == R){
        nextState = GAME;
    }
}

void CourseRun::createCourseL(){
    patterns.push_back(new RunPattern(LINE_TRACE, 30, DISTANCE, 20, 0.7, 0.0, 0.03, 40));//30
    patterns.push_back(new RunPattern(LINE_TRACE, 50, DISTANCE, 560, 0.25, 0.01, 0.03, 60));
    patterns.push_back(new RunPattern(LINE_TRACE, 50, DISTANCE, 120, 0.55, 0.01, 0.03, 60));
    patterns.push_back(new RunPattern(LINE_TRACE, 50, DISTANCE, 80,  0.6, 0.01, 0.03, 60));//ここ変える３０0.55
    patterns.push_back(new RunPattern(LINE_TRACE, 50, DISTANCE, 250, 0.7, 0.01, 0.03, 60));
    patterns.push_back(new RunPattern(LINE_TRACE, 30, DISTANCE, 90, 0.6, 0.0, 0.03, 80));//30
}

void CourseRun::createCourseR(){
  patterns.push_back(new RunPattern(LINE_TRACE, 30, DISTANCE, 20, 0.7, 0.0, 0.03, 40));
    patterns.push_back(new RunPattern(LINE_TRACE, 80, DISTANCE, 200, 0.25, 0.01, 0.03, 60));
    patterns.push_back(new RunPattern(LINE_TRACE, 70, DISTANCE, 180, 0.25, 0.01, 0.05, 60));
    patterns.push_back(new RunPattern(LINE_TRACE, 60, DISTANCE, 220, 0.50, 0.01, 0.04, 60));
    patterns.push_back(new RunPattern(LINE_TRACE, 70, DISTANCE, 140, 0.35, 0.01, 0.05, 60));
    patterns.push_back(new RunPattern(LINE_TRACE, 80, DISTANCE, 260, 0.25, 0.01, 0.03, 60));
    patterns.push_back(new RunPattern(LINE_TRACE, 40, DISTANCE, 100, 0.7, 0.0, 0.03, 70));}
