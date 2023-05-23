#include "acutest.h"
#include "Player.h"
#include "StaticTarget.h"

StaticTarget s1(1);
StaticTarget s2(1);
Player p1;

void test_statichit(void){
    s1.hit(p1);
    s1.get_circle();
    TEST_CHECK_(s1.get_circle().getRadius()==(0),"hit(),s1.get_circle().getRadius()==%d",0);
}

void test_staticdespawn(void){
    s2.despawn();
    s2.get_circle();
    TEST_CHECK_(s2.get_circle().getRadius()==(0),"despawn(),s1.get_circle().getRadius()==%d",0);
}


TEST_LIST = {
    {"void hit()==true", test_statichit},
    {"void despawn()==true",test_staticdespawn},
    {0}
};