#ifndef BULLET_H_
#define BULLET_H_
#include <SFML/Graphics.hpp>

class Bullet
{
private:
	float m_x;
	float m_y;
	sf::CircleShape shape;
	bool Status;

public:
	Bullet(float player_x, float player_y);
	void setDestroy();
	void UpdatePosition();
	void DrawBullet(sf::RenderWindow &win);
	bool isAlive();
	float getX();
	float getY();
};

#endif