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
    patterns.push_back(new RunPattern(LINE_TRACE, 20, GRAYLINE, 55, 1.0, 0.01, 0.0, 40));
    patterns.push_back(new RunPattern(SPIN, 40, DIRECTION, 17));
    patterns.push_back(new RunPattern(STRAIGHT, 30, DISTANCE, 62));
    patterns.push_back(new RunPattern(SPIN, 50, DIRECTION, -57));
}

void Parking::createCourseR(){
    /*直角駐車*/
    patterns.push_back(new RunPattern(STRAIGHT, 20, DISTANCE, 53));
    patterns.push_back(new RunPattern(SPIN, 50, DIRECTION, 90));
    patterns.push_back(new RunPattern(LINE_TRACE, 50, GRAYLINE, 5, 0.9, 0.01));
    patterns.push_back(new RunPattern(STRAIGHT, 30, DISTANCE, 43));
}