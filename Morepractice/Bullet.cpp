#include <SFML/Graphics.hpp>
#include <iostream>
#include "Bullet.h"

using namespace std;

Bullet::Bullet(float player_x, float player_y)
{
	shape = sf::CircleShape(30.f);
	shape.setFillColor(sf::Color::Red);
	float m_x = player_x;
	float m_y = player_y;
	this->shape.setPosition(player_x, player_y);
	isAlive = true;
}

void Bullet::setDestroy()
{
	isAlive = false;
}

void Bullet::UpdatePosition()
{
	m_y -= 1;
	cout << m_y << endl;
	if (m_y < 0 || m_x < 0)
	{
		//destroy the object here
		m_y = 700.f;
		m_x = 400.f;
		this->shape.setPosition(m_x, m_y);
	}
	else
	{
		this->shape.setPosition(m_x, m_y);
	}
}

void Bullet::DrawBullet(sf::RenderWindow & win)
{
	win.draw(shape);
}
