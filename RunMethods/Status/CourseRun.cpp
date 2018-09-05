#include "CourseRun.h"

CourseRun::CourseRun(Course course){
    this->course = course;

    if(this->course == L) {
        createCourseL();
    }else if(this->course == R){
        createCourseR();
    }
}

CourseRun::~CourseRun(){
    for_each(lots.begin(), lots.end(), DeleteObject());
    lots.clear();
}

void CourseRun::init(){
}

void CourseRun::createCourseL(){
    lots.push_back(new Lot(0, 0, 0, 0));
    lots.push_back(new Lot(0, 0, 0, 0));
    lots.push_back(new Lot(0, 0, 0, 0));
    lots.push_back(new Lot(0, 0, 0, 0));
    lots.push_back(new Lot(0, 0, 0, 0));

    patterns.push_back(new RunPattern(LINE_TRACE, 20, lots[0]));
    patterns.push_back(new RunPattern(LINE_TRACE, 20, lots[1]));
    patterns.push_back(new RunPattern(LINE_TRACE, 20, lots[2]));
    patterns.push_back(new RunPattern(LINE_TRACE, 20, lots[3]));
    patterns.push_back(new RunPattern(LINE_TRACE, 0, lots[4]));
}

void CourseRun::createCourseR(){

}