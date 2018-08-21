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
    delete grid;
}

void RunCommander::steer(int power, int turn){
    steering->setPower(power, turn);
}

void RunCommander::steerStop(){
    leftMotor->controlMotor(0);
    rightMotor->controlMotor(0);
}

void RunCommander::run(int pwmL, int pwmR){
    leftMotor->controlMotor(pwmL);
    rightMotor->controlMotor(pwmR);
}

void RunCommander::gridRun(int aX, int aY, int bX, int bY, int pwm , float direction, float distance){
	if (grid_flag == 0){
		grid_direction = grid->getDirection(aX, aY, bX, bY);
		grid_distance = grid->getDistance(aX, aY, bX, bY);
		grid_flag = 1;
	}
	switch (grid->state){
		case TURN:
			if(grid_direction - direction < -0.1){
				leftMotor->controlMotor(20);
				rightMotor->controlMotor(20 * -1);
			}else if(grid_direction - direction > 0.1){
				leftMotor->controlMotor(20 * -1);
				rightMotor->controlMotor(20);
			}else{
				grid->state = MOVE;
			}
			break;
		case MOVE:
			grid_direction = 0;
			if(grid_distance - distance < -1.0){
				leftMotor->controlMotor(pwm * -1);
				rightMotor->controlMotor(pwm * -1);
			}else if(grid_distance - distance > 1.0){
				leftMotor->controlMotor(pwm);
				rightMotor->controlMotor(pwm);
			}else{
				grid->state = END;
			}
			break;
		case END:
			leftMotor->controlMotor(0);
			rightMotor->controlMotor(0);
			grid_flag = 0;
			break;
	}
}
