#include "Parking.h"

Parking::Parking(Course course){
    this->course = course;

    if(this->course == L) {
        createCourseL();
    }else if(this->course == R){
        createCourseR();
    }

    setNextState();
}

Parking::~Parking(){
}

void Parking::init(){
}

void Parking::setNextState(){
    nextState = STOP;
}

void Parking::createCourseL(){
    /*斜め駐車*/
    patterns.push_back(new RunPattern(LINE_TRACE, 20, GRAYLINE, 4, 0.9, 0.01));
    patterns.push_back(new RunPattern(LINE_TRACE, 15, DISTANCE, 10, 0.9, 0.01, 0.0, 70));
    patterns.push_back(new RunPattern(SPIN, 50, DIRECTION, 30));
    patterns.push_back(new RunPattern(STRAIGHT, 20, DISTANCE, 55));
    patterns.push_back(new RunPattern(SPIN, 50, DIRECTION, 90));
}

void Parking::createCourseR(){
    /*直角駐車*/
}