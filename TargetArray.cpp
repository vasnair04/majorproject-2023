#include "TargetArray.h"

TargetArray::TargetArray(Player p1){
    int number = p1.get_numTargets();
    targetarray = new Target*[number];
}