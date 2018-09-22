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
     patterns.push_back(new RunPattern(LINE_TRACE, 15, GRAYLINE, 55, 1.5, 0.0, 0.03, 40, LEFT));
    patterns.push_back(new RunPattern(LINE_TRACE, 10, DISTANCE, 5, 1.5, 0.0, 0.05, 80, RIGHT));
    patterns.push_back(new RunPattern(SPIN, 40, DIRECTION, 40, DIRECTION_LEFT));
    patterns.push_back(new RunPattern(BRAKE, 0, CLOCK, 500));
    patterns.push_back(new RunPattern(STRAIGHT, 30, DISTANCE, 55));
    patterns.push_back(new RunPattern(TURNING, 50, DIRECTION, -57, DIRECTION_RIGHT));
    
}

void Parking::createCourseR(){
    /*直角駐車*/
    patterns.push_back(new RunPattern(STRAIGHT, 10, BLACKLINE, 1));
    patterns.push_back(new RunPattern(STRAIGHT, 10, DISTANCE, 3));
    patterns.push_back(new RunPattern(SPIN, 10, BLACKLINE, 0));
    patterns.push_back(new RunPattern(LINE_TRACE, 15, GRAYLINE, 50, 1.5, 0.0, 0.00, 40, RIGHT));
    patterns.push_back(new RunPattern(LINE_TRACE, 10, DISTANCE, 10, 1.5, 0.0, 0.05, 70, LEFT));
    patterns.push_back(new RunPattern(STRAIGHT, 20, DISTANCE, 30));
}