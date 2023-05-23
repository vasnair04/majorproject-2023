#ifndef MOVINGTARGET_H
#define MOVINGTARGET_H
#include "Target.h"
#include "Player.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

// moving target class represents a moving target and creates a moving sphere in the game
class MovingTarget: public Target {
    private:
    // variables represent velocity in x and y, the circle to be spawned, its size. textures and sounds
    float vel_x;
    float vel_y;
    sf::CircleShape circle;
    int size;
    sf::Texture texture;
    sf::SoundBuffer buffer;
    sf::Sound sound;
    public:
    MovingTarget();
    // hit makes a circle dissapear and adds to score
    void hit(Player p1);
    // despawn makes a circle dissapear and does not add to score, done after certain time
    void despawn();
    // returns circle if requested
    sf::CircleShape get_circle();
    // gets the moving status of circle, movingTarget == 1
    bool get_movingstatus();
    // get and set's for x and y values for positioning of the circle
    void set_x(float val);
    void set_y(float val);
    int get_x();
    int get_y();
    // 3 move algorithms for 3 difficulties move the target in a specified path
    void move(float deltaTime, float windowWidth, float windowHeight);
    void movemed(float deltaTime, float windowWidth, float windowHeight);
    void movehard(float deltaTime, float windowWidth, float windowHeight);
};


#endif