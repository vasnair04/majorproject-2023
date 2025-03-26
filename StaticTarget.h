#ifndef STATICTARGET_H
#define STATICTARGET_H
#include "Target.h"
#include <SFML/Graphics.hpp>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include "Player.h"
#include <SFML/Audio.hpp>


// static target class represents a target that does not move with time
class StaticTarget: public Target {
    private:
        // variables present represent size of circle object, the circle spawned, texture and sound of circle
        int size;
        sf::CircleShape circle;
        sf::Texture texture;
        sf::SoundBuffer buffer;
        sf::Sound sound;
    public:
        // iniliaiser change based on difficulty
        StaticTarget(int difficulty);
        // hit and despawn make radius 0, hit adds to score despawn does not;
        void hit(Player p1);
        void despawn();
        // get_ functions return circle if requested and the moving status of the static target which == 0
        sf::CircleShape get_circle();
        bool get_movingstatus();
        // empty move functions exist if move function is called for this type of object to not cause error
        void move(float deltaTime, float windowWidth, float windowHeight);
        void movemed(float deltaTime, float windowWidth, float windowHeight);
        void movehard(float deltaTime, float windowWidth, float windowHeight);
};



#endif