# majorproject-2023
c++ coding major project files

COMPILATION NOTES:
All Compilation can be done through provided makefile, use command make to make the main file and the below for unit tests:

Unit test:          Make command
Player.h            make test_unitplayer
StaticTarget.h      make test_unitstatic
MovingTarget.h      make test_unitmoving

unit testing was done using the acutest.h library, all compiled files can also additonally be cleared using: make clear.

GAME NOTES:
To play the 2-D aim Trainer is simple, once compiled and run:

1. enter into the terminal your desired, targets, speed(this value is used to divide by 10 to give actual speed in seconds: [10/speed]) and difficulty which includes easy, medium and hard, each of which make the game slightly harder. 

2. Once user generated inputs are put in, click the circles using the left mouse button as they appear on the screen

try to be as fast as possible as they only exist on the screen for a short period of time, over repeated play and increase in difficulty this will improve hand eye coordination of the user and greatly translate to other games where similar movement is required (FPS's). 





