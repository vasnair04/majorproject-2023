#include "acutest.h"
#include "Player.h"

Player player(1,2);

void test_playerinitialise1(void){
    TEST_CHECK_(player.get_numTargets()==(2),"get_numTargets()==%d",2);
}

void test_playerinitialise2(void){
    TEST_CHECK_(player.get_speed()==(1),"get_speed()==%d",1);
}

void test_playerinitialise3(void){
    TEST_CHECK_(player.get_score()==(0),"get_score()==%d",0);
}

TEST_LIST = {
    {"int get_numTargets()==2", test_playerinitialise1},
    {"int get_speed()==1",test_playerinitialise2},
    {"int get_score()==0",test_playerinitialise3},
    {0}
};