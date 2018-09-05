#include "CourseRun.h"

CourseRun::CourseRun(Course course){
    this->course = course;
    patterns.push_back(new RunPattern(STRAIGHT, 20, DISTANCE, 30));
    patterns.push_back(new RunPattern(STRAIGHT, -20, DISTANCE, 30));
    patterns.push_back(new RunPattern(STRAIGHT, 20, DISTANCE, 30));
    patterns.push_back(new RunPattern(STRAIGHT, -20, DISTANCE, 30));
}

CourseRun::~CourseRun(){

}

void CourseRun::init(){
}
