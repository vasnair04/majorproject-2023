#include "Player.h"


// default constructor handles case in which no speed and target num is specified 
Player::Player(){
    this->speed = 0;
    this->numTargets = 0;
    this->score = 0;
}

// constructor gives player a 0 score and initalises the speed and targets
Player::Player(int sped, int numTar){
    this->speed = sped;
    this->numTargets = numTar;
    this->score = 0;
}

// get and set functions below can change and return all the variables within the player class
void Player::set_speed(int speedSet){
    this->speed = speedSet;
}

void Player::set_numTargets(int targetSet){
    this->numTargets = targetSet;
}

void Player::set_score(int scor){
    this->score = scor;
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
