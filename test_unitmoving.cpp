#include "acutest.h"
#include "Player.h"
#include "MovingTarget.h"

MovingTarget s1;
MovingTarget s2;
Player p1;

void test_movinghit(void){
    s1.hit(p1);
    s1.get_circle();
    TEST_CHECK_(s1.get_circle().getRadius()==(0),"hit(),s1.get_circle().getRadius()==%d",0);
}

void test_movingdespawn(void){
    s2.despawn();
    s2.get_circle();
    TEST_CHECK_(s2.get_circle().getRadius()==(0),"despawn(),s1.get_circle().getRadius()==%d",0);
}


TEST_LIST = {
    {"void hit()==true", test_movinghit},
    {"void despawn()==true",test_movingdespawn},
    {0}
};
