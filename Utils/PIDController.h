#ifndef PIDController_H
#define PIDController_H

#define DELTA_T 0.004

#include "PID.h"

class PIDController
{
  private:
	int diff[2];
	float integral;

  public:
	PIDController();
	int getTurn(PID *pid, unsigned int sensor_val, unsigned int target_val, int min, int max);
	int math_limit(int pid_value, int min, int max);

	virtual ~PIDController();
};
#endif