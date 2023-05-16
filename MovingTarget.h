#ifndef MOVINGTARGET_H
#define MOVINGTARGET_H
#include "Target.h"

class MovingTarget: public Target {
    private:
    double* end_x;
    double* end_y;
    public:
    MovingTarget();
    void hit();
    void despawn();
};


#endif