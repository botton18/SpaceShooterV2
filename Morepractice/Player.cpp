#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Bullet.h"
#include <vector>
using namespace std;

//enum Direction{Up, Down, Left, Right} dir;

Player::Player(float x, float y)
{
    playerShape = sf::RectangleShape(sf::Vector2f(100.f,100.f));
    playerShape.setFillColor(sf::Color::Green);

    m_x = x;
    m_y = y;

    playerShape.setPosition(m_x,m_y);
}

void Player::HandleInput(float &time)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        m_y = m_y - 1;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        m_y = m_y + 1;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        m_x = m_x - 1;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        m_x = m_x + 1;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        if(!canShoot)
        {
            if(time > 0.2)
            {
                time = 0;
                canShoot = true;
            }
        }
        else
        {
            Shoot();
            canShoot = false;
        }
        
    }
}

void Player::Update()
{
    playerShape.setPosition(m_x,m_y);
    for(int i = 0; i < Bullet_List.size(); ++i)
    {
        Bullet_List.at(i).UpdatePosition();
    }
}

void Player::DrawPlayer(sf::RenderWindow & win)
{
    win.draw(playerShape);

    for(int i = 0; i < Bullet_List.size(); ++i)
    {
        if(!Bullet_List.at(i).isAlive())
        {
            Bullet_List.erase(Bullet_List.begin() + i);
        }
        else
        {
            Bullet_List.at(i).DrawBullet(win);
        }

    }

}

void Player::Shoot()
{
    Bullet b(m_x,m_y);

    Bullet_List.push_back(b);
}



