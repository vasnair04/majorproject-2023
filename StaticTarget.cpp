#include "StaticTarget.h"
#include <SFML/Graphics.hpp>
#include <ctime>
#include <cstdlib>
#include <iostream>


StaticTarget::StaticTarget(){
    this->size = (rand()%((60-25)+1)+25);
    this->circle.setRadius(size);
    this->circle.setPosition(rand()%(800-(size)),(rand()%(800-(size))));
}

void StaticTarget::hit(Player p1){
    this->circle.setRadius(0);
    int newScore = p1.get_score() + 1;
    p1.set_score(newScore);
}

void StaticTarget::despawn(){

}

sf::CircleShape StaticTarget::get_circle(){
    return this->circle;
}

