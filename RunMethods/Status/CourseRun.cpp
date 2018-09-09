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
    nextState = STOP;
}

void CourseRun::createCourseL(){
    lots.push_back(new Lot(30, 45, -100, 100));
    lots.push_back(new Lot(60, 75, -100, 100));
    lots.push_back(new Lot(90, 105, -100, 100));

    patterns.push_back(new RunPattern(LINE_TRACE, 20, lots[0]));
    patterns.push_back(new RunPattern(LINE_TRACE, 20, lots[1]));
    patterns.push_back(new RunPattern(LINE_TRACE, 20, lots[2]));
}

void CourseRun::createCourseR(){

}