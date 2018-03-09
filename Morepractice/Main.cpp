#include <SFML/Graphics.hpp>
#include "Bullet.h"
#include "Player.h"
#include "Enemy.h"

vector<Enemy*> Enemy_List;

void SpawnEnemy(int n)
{
	Enemy *e = new Enemy();
	Enemy_List.push_back(e);
}

void drawEnemyList(sf::RenderWindow & win)
{
	for(int i = 0; i < Enemy_List.size(); ++i)
	{
		if(!Enemy_List.at(i)->getStatus())
		{
			Enemy_List.erase(Enemy_List.begin() + i);
		}
		else
		{
			Enemy_List.at(i)->Update();
			Enemy_List.at(i)->DrawEnemy(win);
		}
	}
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(1000, 3000), "Space Shooter!");
	//Bullet bullet(400.f,700.f);
	Player player(200.f,200.f); 
	float bullet_timer = 0;
	float enemy_timer = 0;
	float etime = 0;
	sf::Clock clock;
	//Enemy e;

	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asSeconds();
		clock.restart();
		bullet_timer += time;
		enemy_timer += time;
		//float delay = 0.2;
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		//e.Update();
		player.HandleInput(bullet_timer);
		player.Update(Enemy_List);
		
		if(enemy_timer > 0.5)
		{
			SpawnEnemy(1);
			enemy_timer = 0;
		}
		//bullet.UpdatePosition();
		window.clear();
		//bullet.DrawBullet(window);
		player.DrawPlayer(window);
		drawEnemyList(window);
		//e.DrawEnemy(window);
		window.display();
	}
	return 0;
}
