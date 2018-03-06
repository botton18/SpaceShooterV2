#include <SFML/Graphics.hpp>

class Bullet
{
private:
	float m_x;
	float m_y;
	sf::CircleShape shape;
	bool isAlive;

public:
	Bullet(float player_x, float player_y);
	void setDestroy();
	void UpdatePosition();
	void DrawBullet(sf::RenderWindow &win);
};