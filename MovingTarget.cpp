#include "MovingTarget.h"


MovingTarget::MovingTarget(){
    // size is initialised between radius of 60 and 25 and is not changed based on difficulty as movment adds enough difficulty 
    this->size = (rand()%((60-25)+1)+25);
    this->circle.setRadius(size);
    // random points are established for spawning
    this->x=(rand()%(800-(size)));
    this->y=(rand()%(800-(size)));
    this->circle.setPosition(x,y);
    // pre-established velocity of 30 is used for calculations based on testing
    this->vel_x = 30;
    this->vel_y = 30;
    // texture of terrorist is loaded to moving texture
    this->texture.loadFromFile("t.png");
    // texture is assigned to given moving circle object
    this->circle.setTexture(&texture);
    // soundfile of headshot is loaded to be used in hit
    this->buffer.loadFromFile("hs.wav");
    this->sound.setBuffer(buffer);
}

void MovingTarget::hit(Player p1){
    // once hit radius is set to 0 to render the circle invisible
    this->circle.setRadius(0);
    // sound is played to user
    sound.play();
}

void MovingTarget::despawn(){
    // if circle is not hit in time then circle is despawned
    this->circle.setRadius(0);
}

// get_ and set_ get and set certain variables
sf::CircleShape MovingTarget::get_circle(){
    return this->circle;
}

bool MovingTarget::get_movingstatus(){
    return 1;
}

void MovingTarget::set_x(float val){
    this->x = val;
}

void MovingTarget::set_y(float val){
    this->y = val;
}

int MovingTarget::get_x(){
    return x;
}

int MovingTarget::get_y(){
    return y;
}

//////////////////////////////////////MOVEMENT-TYPES/////////////////////////////////////////////////

// normal move function makes it so movment happens in one direction left to right
void MovingTarget::move(float deltaTime, float windowWidth, float windowHeight)
    {
        // movment modifier is calculated
        float moveX = 100  * deltaTime;
        float moveY = 100 * deltaTime;

        x += moveX;
        y += moveY;

        // values of x and y are limited to within the window to prevent an un-hittable sphere
        x = std::max(circle.getRadius(), std::min(x, windowWidth - size * 2.f));
        y = std::max(circle.getRadius(), std::min(y, windowHeight - size * 2.f));

        // sets position and initiates movement
        this->circle.setPosition(x, y);
    }
// medium move function makes it so movement happens in two directions
void MovingTarget::movemed(float deltaTime, float windowWidth, float windowHeight)
    {
        float moveX = 1000  * deltaTime;
        float moveY = 1000 * deltaTime;
        int rng = (rand()%((2-1)+1)+1);

        switch (rng){
            case 1:
                x += moveX;
                y += moveY;
                break;
            case 2:
                x -= moveX;
                y -= moveY;
                break; 
        }


        x = std::max(circle.getRadius(), std::min(x, windowWidth - size * 2.f));
        y = std::max(circle.getRadius(), std::min(y, windowHeight - size * 2.f));

        this->circle.setPosition(x, y);
    }

// hard movmement makes it so movement happens in all 4 directions and makes movement erratic
void MovingTarget::movehard(float deltaTime, float windowWidth, float windowHeight)
    {
        float moveX = 10000 * deltaTime;
        float moveY = 10000 * deltaTime;
        int rng = (rand()%((4-1)+1)+1);

        switch (rng){
            case 1:
                x += moveX;
                y += moveY;
                break;
            case 2:
                x -= moveX;
                y -= moveY;
                break; 
            case 3:
                x += moveX;
                y -= moveY;
                break;
            case 4:
                x -= moveX;
                y += moveY;
                break; 
        }


        x = std::max(circle.getRadius(), std::min(x, windowWidth - size * 2.f));
        y = std::max(circle.getRadius(), std::min(y, windowHeight - size * 2.f));

        this->circle.setPosition(x, y);
    }

///////////////////////////////////////////////////////////////////////////////////////////////////////