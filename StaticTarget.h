#ifndef STATICTARGET_H
#define STATICTARGET_H
#include "Target.h"
#include <SFML/Graphics.hpp>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include "Player.h"

class StaticTarget: public Target {
    private:
        int size;
        sf::CircleShape circle;
    public:
        StaticTarget();
        void hit(Player p1);
        void despawn();
        sf::CircleShape get_circle();
};



#endif