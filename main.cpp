#include <SFML/Graphics.hpp>
#include "TargetArray.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
#include "StaticTarget.h"


int main(void)
{
    sf::RenderWindow windows(sf::VideoMode(800, 800), "2-D aim trainer");
    
    srand(time(0));

    int currentcircle = 0;

    StaticTarget targets[5];
    Player p1(10,10);


    while (windows.isOpen())
    {
        
        sf::Event event;
        while (windows.pollEvent(event))
        {

            if (event.type == sf::Event::Closed) {
                windows.close();
            }

        }

        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left && targets[currentcircle].get_circle().getGlobalBounds().contains(event.mouseButton.x,event.mouseButton.y)){
            targets[currentcircle].hit(p1);
            if (currentcircle != 4){
                currentcircle++;
            } else{
                currentcircle = 4;
            }
        }


        windows.display();
        windows.clear();
        windows.draw(targets[currentcircle].get_circle());


    }





    return 0;
}
