#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>
#include "Enemy.h"

using namespace std;


Enemy::Enemy()
{
    srand(time(NULL));
    int random = rand() % 2;
    int randompos = rand() % 800;
    if(random == 0)
    {
        a1.loadFromFile("image/astroid1.png");
    }
    else
    {
        a1.loadFromFile("image/astorid2.png");
    }
    astroid = sf::Sprite(a1);
    m_x = randompos;
    m_y = -100;
    astroid.setPosition(sf::Vector2f(m_x, m_y));
}

void Enemy::Update()
{
    m_y += 0.5;
    astroid.setPosition(sf::Vector2f(m_x,m_y));
    if(m_y > 1350)
    {
        Status = false;
    }
}
void Enemy::DrawEnemy(sf::RenderWindow & win)
{
    win.draw(astroid);
}

bool Enemy::getStatus()
{
    return Status;
}

void Enemy::setStatus(bool t)
{
    Status = t;
}

sf::Sprite Enemy::getSprite()
{
    return astroid;
}