#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Bullet.h"
#include <vector>
using namespace std;

//enum Direction{Up, Down, Left, Right} dir;

Player::Player(float x, float y)
{

    red_ship.loadFromFile("image/red_fighter.png");
    //cout << "Load " << endl;
    playerShape = sf::Sprite(red_ship);
    playerShape.scale(sf::Vector2f(0.5f, 0.5f));
    m_x = x;
    m_y = y;

    playerShape.setPosition(m_x,m_y);
}

void Player::HandleInput(float &time)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        if(m_y > 0)
            m_y = m_y - 1;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        if(m_y < 1350)
            m_y = m_y + 1;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        if(m_x > 0)
            m_x = m_x - 1;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        if(m_x < 825)
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
//		if (snake.at(0).sprite().getGlobalBounds().intersects(fruit.getFruitSprite().getGlobalBounds()))

void Player::Update(vector<Enemy*> &l)
{
    playerShape.setPosition(m_x,m_y);
    for(int i = 0; i < Bullet_List.size(); ++i)
    {
        Bullet_List.at(i)->UpdatePosition();
        for(int j = 0; j < l.size(); ++j)
        {
            if(Bullet_List.at(i)->getSprite().getGlobalBounds().intersects(l.at(j)->getSprite().getGlobalBounds()))
            {
                Bullet_List.at(i)->setAlive(false);
                l.at(j)->setStatus(false);
            }
        }
    }
}

void Player::DrawPlayer(sf::RenderWindow & win)
{
    win.draw(playerShape);

    for(int i = 0; i < Bullet_List.size(); ++i)
    {
        if(!Bullet_List.at(i)->isAlive())
        {
            Bullet_List.erase(Bullet_List.begin() + i);
        }
        else
        {
            Bullet_List.at(i)->DrawBullet(win);
        }

    }

}

void Player::Shoot()
{
    //Bullet b(m_x + 77.5 ,m_y);

    Bullet *temp = new Bullet(m_x + 141.5,m_y-75);
    Bullet_List.push_back(temp);
}



