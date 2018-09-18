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
        nextState = STOP;
    }else if(this->course == R){
        nextState = GAME;
    }
}

void CourseRun::createCourseL(){
    lots.push_back(new Lot(20, 40, 10000, 10003));
    //lots.push_back(new Lot(-32000, 36000, 240, 300));
    //lots.push_back(new Lot(47000, 50000, 240, 300));
    //lots.push_back(new Lot(320, 360, 1000005, 100000));

    patterns.push_back(new RunPattern(LINE_TRACE, 30, lots[0], 0.7, 0.0, 0.03, 40));
    //patterns.push_back(new RunPattern(LINE_TRACE, 80, lots[1], 0.25, 0.0, 0.03, 60));
    //patterns.push_back(new RunPattern(LINE_TRACE, 80, lots[2], 0.4, 0.0, 0.05, 60));
    //patterns.push_back(new RunPattern(LINE_TRACE, 80, lots[3], 0.25, 0.0, 0.03, 60));
}

void CourseRun::createCourseR(){
    lots.push_back(new Lot(50, 100, 20, 40));
    lots.push_back(new Lot(250, 300, 0, 40));
    patterns.push_back(new RunPattern(LINE_TRACE, 30, lots[0], 0.7, 0.0, 0.03, 40));
    patterns.push_back(new RunPattern(LINE_TRACE, 30, lots[1], 0.7, 0.0, 0.03, 40));
}