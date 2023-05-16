#include "Player.h"

Player::Player(){
    speed = 0;
    numTargets = 0;
    score = 0;
}

Player::Player(int sped, int numTar){
    speed = sped;
    numTargets = numTar;
    score = 0;
}

void Player::set_speed(int speedSet){
    speed = speedSet;
}

void Player::set_numTargets(int targetSet){
    numTargets = targetSet;
}

int Player::get_speed(){
    return speed;
}

int Player::get_numTargets(){
    return numTargets;
}

int Player::get_score(){
    return score;
}