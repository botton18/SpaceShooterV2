#include <SFML/Graphics.hpp>
#include "Bullet.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 800), "Space Shooter!");
	Bullet bullet(400.f,700.f); 

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		bullet.UpdatePosition();
		window.clear();
		bullet.DrawBullet(window);
		window.display();
	}
	return 0;
}