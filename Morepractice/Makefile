All: main
	./a.out
	
main: Bullet 
	g++ Main.cpp Player.o Bullet.o Enemy.o -lsfml-graphics -lsfml-window -lsfml-system

Bullet: Player Bullet.cpp Bullet.h
	g++ -c Bullet.cpp

Player: Enemy Player.cpp Player.h
	g++ -c Player.cpp

Enemy: Enemy.cpp Enemy.h
	g++ -c Enemy.cpp