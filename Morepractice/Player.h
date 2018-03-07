#ifndef PLAYER_H_
#define PLAYER_H_
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "Bullet.h"

using namespace std;
class Player
{
    private:
        sf::RectangleShape playerShape;
        float m_x;
        float m_y;
        bool Status;
        bool canShoot;
        vector<Bullet> Bullet_List;

    public:
        Player(float x, float y);
        void HandleInput(float &time);
        void Update();
        void Shoot();
        void DrawPlayer(sf::RenderWindow & win);
        
};

#endif