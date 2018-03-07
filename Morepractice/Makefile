All: main
	./a.out
main: Bullet 
	g++ Main.cpp Player.o Bullet.o -lsfml-graphics -lsfml-window -lsfml-system

Bullet: Player Bullet.cpp Bullet.h
	g++ -c Bullet.cpp

Player: Player.cpp Player.h
	g++ -c Player.cpp