#include "RunCommander.h"

RunCommander::RunCommander(){
    leftMotor   = new WheelMotorDriver(PORT_C);
    rightMotor  = new WheelMotorDriver(PORT_B);
    steering = new Steering(*leftMotor->motor, *rightMotor->motor);
    grid = new Grid();
}

RunCommander::~RunCommander(){
    delete leftMotor;
    delete rightMotor;
}

void RunCommander::steer(int power, int turn){
    steering->setPower(power, turn);
}

void RunCommander::steerStop(){
    steering->setPower(0, 0);
}

void RunCommander::run(int pwmL, int pwmR){
    leftMotor->controlMotor(pwmL);
    rightMotor->controlMotor(pwmR);
}

void RunCommander::gridRun(int aX, int aY, int bX, int bY, int pwm){
	grid->grid_distance = grid->getDistance(aX, aY, bX, bY);
	grid->grid_direction = grid->getDirection(aX, aY, bX, bY);
	switch (grid->state){
		case TURN:
			if(grid->grid_direction==0){
				grid->state = MOVE;
			}else if(grid->grid_direction >0){
				leftMotor->controlMotor(pwm * -1);
				rightMotor->controlMotor(pwm);
			}else{
				leftMotor->controlMotor(pwm);
				rightMotor->controlMotor(pwm * -1);
			}
		case MOVE:
			if(grid->grid_direction==0){
				grid->state = END;
			}else if(grid->grid_distance >0){
				leftMotor->controlMotor(pwm);
				rightMotor->controlMotor(pwm);
			}else{
				leftMotor->controlMotor(pwm * -1);
				rightMotor->controlMotor(pwm * -1);
			}
		case END:
			leftMotor->controlMotor(0);
			rightMotor->controlMotor(0);
	}
}
