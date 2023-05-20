#ifndef TARGET_H
#define TARGET_H
#include "Player.h"

class Target{
    protected:
    double* x;
    double* y;
    public:
    Target();
    virtual void hit(Player p1)=0;
    virtual void despawn()=0;
};


#endif