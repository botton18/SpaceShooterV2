#ifndef ENEMY_H_
#define ENEMY_H_
#include <SFML/Graphics.hpp>

class Enemy
{
    private:
        sf::Sprite astroid;
        sf::Texture a1;

        float m_x;
        float m_y;
        bool Status;
    public:
        Enemy();
        void Update();
        void DrawEnemy(sf::RenderWindow &win);
        bool getStatus();
        void setStatus(bool t);
        sf::Sprite getSprite();
};

#endif