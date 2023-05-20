#ifndef TARGETARRAY_H
#define TARGETARRAY_H
#include "Target.h"
#include "MovingTarget.h"
#include "StaticTarget.h"
#include "Player.h"

class TargetArray { 
    private:
        Target** targetarray;
    public:
        TargetArray(Player p1);
};


#endif