
main: GUI.o main.o MovingTarget.o Player.o StaticTarget.o Target.o
	g++ GUI.o main.o MovingTarget.o Player.o StaticTarget.o Target.o -o main -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

GUI.o: GUI.cpp GUI.h
	g++ -c GUI.cpp

main.o: main.cpp
	g++ -c main.cpp

MovingTarget.o: MovingTarget.cpp MovingTarget.h
	g++ -c MovingTarget.cpp

Player.o: Player.cpp Player.h
	g++ -c Player.cpp

StaticTarget.o: StaticTarget.cpp StaticTarget.h
	g++ -c StaticTarget.cpp

Target.o: Target.cpp Target.h
	g++ -c Target.cpp

test_unitplayer.o: test_unitplayer.cpp 
	g++ -c test_unitplayer.cpp

test_unitplayer: test_unitplayer.o Player.o
	g++ Player.cpp test_unitplayer.cpp -o test_unitplayer -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

test_unitstatic.o: test_unitstatic.cpp 
	g++ -c test_unitstatic.cpp

test_unitstatic: test_unitplayer.o StaticTarget.o Player.o Target.o
	g++ StaticTarget.o test_unitstatic.o Player.o Target.o -o test_unitstatic -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

test_unitmoving.o: test_unitmoving.cpp 
	g++ -c test_unitmoving.cpp

test_unitmoving: test_unitmoving.o MovingTarget.o Player.o Target.o
	g++ MovingTarget.cpp test_unitmoving.cpp Player.cpp Target.cpp -o test_unitmoving -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

clean: 
	rm *.o main test_unitplayer test_unitstatic test_unitmoving

cleannotmain:
	rm *.o

