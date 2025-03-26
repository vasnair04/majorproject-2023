#include <SFML/Graphics.hpp>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include "StaticTarget.h"
#include "MovingTarget.h"

int main(void)
{
    //initialising variables for current circle num targets, gamespeed, difficulty and end conditons
    int currentcircle = 0;
    int currentcirclehid = 0;
    int numTargets = 0;
    int gameSpeed = 0;
    int difficulty = 0;
    int score = 0;
    bool endcondition = 0;
    // intialses text for the end of the game as it insistatiated within the sfml while loop
    sf::Text endText;
    sf::Text scoreText;
    // first clock to handle spawning
    sf::Clock clock;
    //random number generator seeded with current time;
    srand(time(0));
    // bool for input validation established
    bool inputtar = 0 ,inputspe = 0,inputdiff = 0;
    //Initial Condition inputs and validations to prevent malicious input
    // target input
    while (inputtar==0){
        std::cout << "Input number of targets: ";
        std::cin >> numTargets;
        if (numTargets<1){
            std::cout << "INVALID NUMBER OF TARGETS, USE A POSITIVE INTEGER" << std::endl;
            inputtar = 0;
            std::cin.clear();
            std::cin.ignore();
        } else {
            if (std::cin.fail()){
                std::cout << "\n" << "INVALID INPUT TRY AGAIN" << std::endl;
                std::cin.clear();
                std::cin.ignore();
            } else {
                inputtar = 1;
            }
        }
    }
    // speed input
    while (inputspe==0){
        std::cout << "Input speed value: ";
        std::cin >> gameSpeed;
        if (gameSpeed<1){
            std::cout << "INVALID SPEED, USE A POSITIVE INTEGER" << std::endl;
            inputspe = 0;
            std::cin.clear();
            std::cin.ignore();
        } else {
            if (std::cin.fail()){
                std::cout << "\n" << "INVALID INPUT TRY AGAIN" << std::endl;
                std::cin.clear();
                std::cin.ignore();
            } else {
                inputspe = 1;
            }
        }
    }
    // difficulty input
    while (inputdiff==0){
        std::cout << "1)Easy\n2)Medium\n3)Hard\n ";
        std::cin >> difficulty;
        if (difficulty>3||difficulty<1){
            std::cout << "INVALID DIFFICULTY PLEASE PICK A NUMBER BETWEEN 1 AND 3" << std::endl;
            inputdiff = 0;
            std::cin.clear();
            std::cin.ignore();
        } else {
            if (std::cin.fail()){
                std::cout << "\n" << "INVALID INPUT TRY AGAIN" << std::endl;
                std::cin.clear();
                std::cin.ignore();
            } else {
                inputdiff = 1;
            }
        }
    }
    // makes difficulty into a string to be outputted to user
    std::string difficulty2;
    switch (difficulty){
        case 1:
            difficulty2 = "Easy";
            break;
        case 2:
            difficulty2 = "Medium";
            break;
        case 3:
            difficulty2 = "Hard";
            break;
    }
    // player is initialised with given values from the player
    Player p1(gameSpeed,numTargets);
    // variables for the graphics of first run
    bool firstrun = 1;
    sf::Font Font;
    // font loaded to be used in all future texts
    Font.loadFromFile("./Zerafoc.ttf");
    // counter and starting text initialised for initial user interactions before game has started
    sf::Text counter1;
    sf::Text startingText;
    counter1.setFont(Font);
    counter1.setCharacterSize(100);
    counter1.setFillColor(sf::Color::White);
    // code to center counter using text box bounds
    sf::FloatRect counter1bounds = counter1.getLocalBounds();
    counter1.setOrigin(counter1bounds.left + counter1bounds.width / 2.f, counter1bounds.top + counter1bounds.height/2.f);
    counter1.setPosition(800 / 2.f , 800 / 2.f - 100);
    counter1.setString("3");
    startingText.setFont(Font);
    startingText.setCharacterSize(50);
    startingText.setFillColor(sf::Color::White);
    // code to center starting text using text bounds
    sf::FloatRect textbounds = startingText.getLocalBounds();
    startingText.setOrigin(textbounds.left + textbounds.width / 2.f, textbounds.top + textbounds.height / 2.f);
    startingText.setPosition(800 / 2.f - 150, 800 / 2.f - 100);
    startingText.setString("Targets:" + std::to_string(numTargets) + "\n" + "Speed:" + std::to_string(gameSpeed) + "\n" + "Difficulty: " + difficulty2);
    startingText.setStyle(sf::Text::Bold);
    //Calculating time per spawn or game speed calculation
    float basetime = 10; //base time in seconds, if speed was 1
    float spawntime = basetime/gameSpeed;
    //////////////////////////////////SPAWNING LOGIC////////////////////////////
    int targets = p1.get_numTargets();
    int moving = (rand()%((targets-1)+1)+1);

    Target* targetarray[targets];
    
    for (int i = 0; i < (targets-moving); i++){
        targetarray[i] = new StaticTarget(difficulty);
    }
    for (int i = (targets-moving); i < targets; i++){
        targetarray[i] = new MovingTarget();
    }
    ////////////////////////////////////////////////////////////////////////////

    sf::RenderWindow windows(sf::VideoMode(800, 800), "2-D aim trainer");
    windows.setFramerateLimit(60);
    // second clock to handle movement by acting as deltaTime for movement over time
    sf::Clock clock2;
    // clock 3 made to handle starting countdown 
    sf::Clock clock3;
    // handler for closing window 
    while (windows.isOpen())
    {   
        sf::Event event;
        while (windows.pollEvent(event))
        {   

            if (event.type == sf::Event::Closed) {
                windows.close();
            }

        }
        // checks if the run is the first one and executes the starting screen for the user
        if(firstrun){
            clock3.restart();
            // displays the starting text to the user for 1.5 seconds
            while(clock3.getElapsedTime().asSeconds()<=1.5){
                windows.clear();
                windows.draw(startingText);
                windows.display();
            }
            clock3.restart();
            // does a 3, 2, 1 count before game starts
            while(clock3.getElapsedTime().asSeconds()<=3){
                if(clock3.getElapsedTime().asSeconds()<=1){
                    windows.clear();
                    windows.draw(counter1);
                    windows.display();
                } else if(clock3.getElapsedTime().asSeconds()<=2&&clock3.getElapsedTime().asSeconds()>1){
                    counter1.setString("2");
                    windows.clear();
                    windows.draw(counter1);
                    windows.display();
                } else if(clock3.getElapsedTime().asSeconds()>2&&clock3.getElapsedTime().asSeconds()<=3){
                    counter1.setString("1");
                    windows.clear();
                    windows.draw(counter1);
                    windows.display();
                }
            }
            // window is cleared of any residual elements and first run is set to 0 to prevent rerunning code
            windows.clear();
            firstrun=0;
            clock2.restart();
        }

        // logic handles despawning of objects if time as defined by speed is elapsed
        if(clock2.getElapsedTime().asSeconds()>=spawntime){
            clock2.restart();
            targetarray[currentcircle]->despawn();
            // logic to prevent acessing outside of array
            if (currentcircle != (p1.get_numTargets()-1)){
                currentcircle++;
                // currentcirclehid acts as a background count to only be used at the end to prevent acessing elements outside an array
                currentcirclehid++;
            } else {
                currentcircle=(p1.get_numTargets()-1);
                currentcirclehid++;
            }
        }

        // monitors for click event on a circle object and registers a hit when a left mouse button click is done within the bounds of the circle that spawns
        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left && targetarray[currentcircle]->get_circle().getGlobalBounds().contains(event.mouseButton.x,event.mouseButton.y))
        {   
            targetarray[currentcircle]->hit(p1);
            clock2.restart();
            // adds to score when hit is registered
            score++;
            // the score is saved to the players database as a back up
            p1.set_score(score);
            // logic to prevent accessing outside of array
            if (currentcircle != (p1.get_numTargets()-1)){
                currentcircle++;
                currentcirclehid++;
            } else {
                currentcircle=(p1.get_numTargets()-1);
                currentcirclehid++;
            }
        
        }
        // checks for moving status and if the object is a moving target then movement math is done on it
        if (targetarray[currentcircle]->get_movingstatus()==1)
        {
        float deltaTime = clock.restart().asSeconds(); 
            //movement math is done based on difficulty and makes movement more erratic as difficulty increases;
            switch(difficulty){
            case 1:
                targetarray[currentcircle]->move(deltaTime, 800, 800);
                break;
            case 2:
                targetarray[currentcircle]->movemed(deltaTime, 800, 800);
                break;
            case 3:
                targetarray[currentcircle]->movehard(deltaTime, 800, 800);
                break;
        }
        }
        // if all circles specified have been hit then end conditons are triggered
        if(currentcirclehid==p1.get_numTargets()){
            endcondition = 1;
        }

        // since end condtions are triggered ending graphics are initialised
        if (endcondition==1){

            //text for game over
            endText.setFont(Font);
            endText.setString("Game Over!");
            endText.setCharacterSize(100);
            endText.setFillColor(sf::Color::Red);
            endText.setStyle(sf::Text::Bold);

            //text for displaying score
            scoreText.setFont(Font);
            scoreText.setString("         " +std::to_string(score) + " OF " + std::to_string(numTargets) + " Targets Hit!" + "\n" + "-Exit and restart to retry-");
            scoreText.setCharacterSize(48);
            scoreText.setFillColor(sf::Color::White);
            scoreText.setStyle(sf::Text::Bold);

            //positioning of text
            sf::FloatRect endTextBounds = endText.getLocalBounds();
            sf::FloatRect scoreTextBounds = scoreText.getLocalBounds();
            endText.setOrigin(endTextBounds.left + endTextBounds.width/ 2.0f ,
                            endTextBounds.top + endTextBounds.height/ 2.0f);
            scoreText.setOrigin(scoreTextBounds.left + scoreTextBounds.width/ 2.0f ,
                            scoreTextBounds.top + scoreTextBounds.height/ 2.0f);
            endText.setPosition(windows.getSize().x / 2.0f, windows.getSize().y / 2.0f - 50);
            scoreText.setPosition(windows.getSize().x / 2.0f, windows.getSize().y / 2.0f + 50);
            
        }

        //rendering is done where windows are cleared and elements are shown
        windows.clear();
        //drawing circles on each loop
        windows.draw(targetarray[currentcircle]->get_circle());
        //drawing text after end of game is reached
        windows.draw(endText);
        windows.draw(scoreText);
        // window is displayed to user after render
        windows.display();
    }
    return 0;
}
