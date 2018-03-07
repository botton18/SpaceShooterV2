#include <SFML/Graphics.hpp>
#include "Bullet.h"
#include "Player.h"
int main()
{
	sf::RenderWindow window(sf::VideoMode(1000, 3000), "Space Shooter!");
	//Bullet bullet(400.f,700.f);
	Player player(200.f,200.f); 
	float timer = 0;
	float etime = 0;
	sf::Clock clock;

	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asSeconds();
		clock.restart();
		timer += time;
		//float delay = 0.2;
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		player.HandleInput(timer);
		player.Update();
		//bullet.UpdatePosition();
		window.clear();
		//bullet.DrawBullet(window);
		player.DrawPlayer(window);
		window.display();
	}
	return 0;
}