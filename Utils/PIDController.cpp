#include "PIDController.h"

PIDController::PIDController()
{
}

PIDController::~PIDController()
{
}

int PIDController::getTurn(PID *pid, unsigned int sensor_val, unsigned int target_val, int min, int max)
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

  return math_limit(p + i + d, min, max);
}

int PIDController::math_limit(int pid_value, int min, int max)
{
  if (pid_value > max)
    pid_value = max;
  else if (pid_value < min)
    pid_value = min;
  return pid_value;
}