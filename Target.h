#ifndef TARGET_H
#define TARGET_H
#include "Player.h"
#include <SFML/Graphics.hpp>

class Target{
    protected:
    // basic x and y are included in abstract class of target
    float x;
    float y;
    public:
    Target();
    // functions to be used in future children are inlcuded as pure virtual functions
    virtual void hit(Player p1)=0;
    virtual void despawn()=0;
    virtual sf::CircleShape get_circle()=0;
    virtual bool get_movingstatus()=0;
    virtual void move(float deltaTime,float windowWidth,float windowHeight)=0;
    virtual void movemed(float deltaTime,float windowWidth,float windowHeight)=0;
    virtual void movehard(float deltaTime,float windowWidth,float windowHeight)=0;
};


#endif