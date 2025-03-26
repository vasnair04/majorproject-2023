#ifndef GUI_H
#define GUI_H
#include <SFML/Graphics.hpp>
//GUI class includes basis for text boxes presented to the user at the start of the game
//Could use with further templates to be used to shorten complexity of main code

class GUI{
    private:
    // sf text objects for 3 counters and starting text 
    sf::Text counter1;
    sf::Text counter2;
    sf::Text counter3;
    sf::Text startingText;
    int Targets;
    int Speed;
    public:
    // gui initialises to given font, window dimensions and target and speed values
    GUI(int windowwidth,int windowheight,sf::Font font,int targets,int speed);
    //get_ functions to recieve certain values;
    sf::Text get_startingtext();
    sf::Text get_counter1();
    sf::Text get_counter2();
    sf::Text get_counter3();
};









#endif

