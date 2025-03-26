#include "GUI.h"

GUI::GUI(int windowwidth,int windowheigth,sf::Font font,int Targets, int Speed){
    // initialised the text for the start of the game
    startingText.setFont(font);
    startingText.setCharacterSize(0);
    startingText.setFillColor(sf::Color::Magenta);
    sf::FloatRect textbounds = startingText.getLocalBounds();
    startingText.setOrigin(textbounds.left + textbounds.width / 2.0f, textbounds.top+textbounds.height/2.0f);
    startingText.setPosition(windowwidth/2.0f,windowheigth/2.0f);
    startingText.setString("Targets:" + std::to_string(Targets) + "\n" + "Speed:" + std::to_string(Speed));
    startingText.setStyle(sf::Text::Bold);
    // initiliases one counter
    counter1.setFont(font);
    counter1.setCharacterSize(0);
    counter1.setFillColor(sf::Color::Magenta);
    sf::FloatRect counter1bounds = counter1.getLocalBounds();
    counter1.setOrigin(counter1bounds.left + counter1bounds.width / 2.0f, counter1bounds.top+counter1bounds.height/2.0f);
    counter1.setPosition(windowwidth/2.0f,windowheigth/2.0f);
    counter1.setString("1");    
    // initiliases two counter
    counter2.setFont(font);
    counter2.setCharacterSize(0);
    counter2.setFillColor(sf::Color::Magenta);
    sf::FloatRect counter2bounds = counter2.getLocalBounds();
    counter2.setOrigin(counter2bounds.left + counter2bounds.width / 2.0f, counter2bounds.top+counter2bounds.height/2.0f);
    counter2.setPosition(windowwidth/2.0f,windowheigth/2.f);
    counter2.setString("2");   
    // initiliases three counter
    counter3.setFont(font);
    counter3.setCharacterSize(0);
    counter3.setFillColor(sf::Color::Magenta);
    sf::FloatRect counter3bounds = counter3.getLocalBounds();
    counter3.setOrigin(counter3bounds.left + counter3bounds.width / 2.0f, counter3bounds.top+counter3bounds.height/2.0f);
    counter3.setPosition(windowwidth/2.f,windowheigth/2.0f);
    counter3.setString("3");
}



// returns the text templates to be used within the main function
sf::Text GUI::get_startingtext(){
    return startingText;
}

sf::Text GUI::get_counter1(){
    return counter1;
}

sf::Text GUI::get_counter2(){
    return counter2;
}

sf::Text GUI::get_counter3(){
    return counter3;
}