#ifndef PLAYER_H_
#define PLAYER_H_
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "Bullet.h"
#include "Enemy.h"

using namespace std;
class Player
{
    private:
        sf::Sprite playerShape;
        sf::Texture red_ship;
        float m_x;
        float m_y;
        bool Status;
        bool canShoot;
        vector<Bullet*> Bullet_List;
        int score;
        int life;
        bool canLoseLife;

    public:
        Player(float x, float y);
        void HandleInput(float &time);
        void Update(vector<Enemy*> &l);
        void Shoot();
        void DrawPlayer(sf::RenderWindow & win);
        void Collide(vector<Enemy*> &l, float & timer);
        void updateLife(float & timer);

        
        
};

#endif