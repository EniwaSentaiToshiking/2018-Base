#include "PIDController.h"

PIDController::PIDController()
{
}

PIDController::~PIDController()
{
}

int PIDController::getTurn(PID *pid, unsigned int sensor_val, unsigned int target_val, int absMax)
{
  int p, i, d;
  float KP, KI, KD;

  KP = pid->p;
  KI = pid->i;
  KD = pid->d;

  diff[0] = diff[1];
  diff[1] = sensor_val - target_val;
  integral += (diff[1] + diff[0]) / 2.0 * DELTA_T;

  p = KP * diff[1];
  i = KI * integral;
  d = KD * (diff[1] - diff[0]) / DELTA_T;

  return math_limit(p + i + d, absMax);
}

int PIDController::math_limit(int pid_value, int absMax)
{
  if (pid_value > absMax)
    pid_value = absMax;
  else if (pid_value < absMax * -1)
    pid_value = absMax * - 1;
  return pid_value;
}