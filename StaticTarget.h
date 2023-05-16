#ifndef STATICTARGET_H
#define STATICTARGET_H
#include "Target.h"

class StaticTarget: public Target {
    private:
        double size;
    public:
        StaticTarget();
        void hit();
        void despawn();
};



#endif