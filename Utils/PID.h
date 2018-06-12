#ifndef PID_H
#define PID_H

class PID
{
  public:
    float p, i, d;

    PID(float p, float i, float d);
    virtual ~PID();
};

#endif