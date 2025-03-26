#include "StaticTarget.h"
#include <SFML/Graphics.hpp>
#include <ctime>
#include <cstdlib>
#include <iostream>

// constructor takes in arguement of difficulty
StaticTarget::StaticTarget(int difficulty){
    // size is determined by difficulty and as difficulty increases, size variation decreases.
    // minimum size is consistently 25 however easy can go as big as 60, medium can go as big as 30,
    // and hard can only go as big as 26 which adds difficulty as needed;
    switch(difficulty){
        case 1:
            this->size = (rand()%((60-25)+1)+25); 
            break;  
        case 2:
            this->size = (rand()%((30-25)+1)+25);
            break;
        case 3:
            this->size = (rand()%((26-25)+1)+25);
            break;
    }
    // sets radius of circle based on specified size
    this->circle.setRadius(size);
    // sets position based on randomised x and y
    this->circle.setPosition(rand()%(800-(size)),(rand()%(800-(size))));
    // loads textures of counter-terrorist from files
    this->texture.loadFromFile("ct.png");
    this->circle.setTexture(&texture);
    // loads headshot sound from files to be played when hit() is called
    this->buffer.loadFromFile("hs.wav");
    this->sound.setBuffer(buffer);
}

// hit function adds to score of player, sets radius to 0 and plays headshot sound
void StaticTarget::hit(Player p1){
    this->circle.setRadius(0);
    sound.play();

}

// despawn function gets rid of circle and does not add to score;
void StaticTarget::despawn(){
    this->circle.setRadius(0);
}

// get funcitons get circle and moving status, staticTarget == 0
sf::CircleShape StaticTarget::get_circle(){
    return this->circle;
}

bool StaticTarget::get_movingstatus(){
    return 0;
}

// empty functions to prevent errors if function call is done
void StaticTarget::move(float deltaTime, float windowWidth, float windowHeight){

};

void StaticTarget::movemed(float deltaTime, float windowWidth, float windowHeight){

};

void StaticTarget::movehard(float deltaTime, float windowWidth, float windowHeight){

};
