#include <SFML/Graphics.hpp>
#include <iostream>
#include "Bullet.h"

using namespace std;

Bullet::Bullet(float player_x, float player_y)
{
	shape = sf::CircleShape(10.f);
	shape.setFillColor(sf::Color::Red);
	m_x = player_x;
	m_y = player_y;
	shape.setPosition(m_x, m_y);
	Status = true;
}

void Bullet::setDestroy()
{
	Status = false;
}

bool Bullet::isAlive()
{
	return Status;
}

void Bullet::UpdatePosition()
{
	m_y -= 2.5;
	if (m_y < 0)
	{
		//destroy the object here
		Status = false;
	}
	else
	{
		this->shape.setPosition(m_x, m_y);
	}
	shape.setPosition(m_x,m_y);
}

void Bullet::DrawBullet(sf::RenderWindow & win)
{
	win.draw(shape);
}

float Bullet::getX()
{
	return m_x;
}

float Bullet::getY()
{
	return m_y;
}
