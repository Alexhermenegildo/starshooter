#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Bullet
{
private:
    sf::Vector2f m_Position;
    sf::RectangleShape m_Shape;
    float m_Speed;

public:
    Bullet(float startX, float startY);
    void update(float elapsedTime);
    sf::FloatRect getGlobalBounds();
    sf::RectangleShape& getShape();
};

class Enemy
{
private:
    sf::Vector2f m_Position;
    sf::Sprite m_Sprite;
    sf::Texture m_Texture;
    float m_Speed;
    bool m_MovingUp; // Flag to track movement direction
    std::vector<Bullet> m_Bullets; // Vector to store enemy bullets

public:
    Enemy();
    sf::Sprite getSprite();
    void update(float elapsedTime);
    void shoot();
    std::vector<Bullet>& getBullets(); // Return reference to bullets vector
    sf::Vector2f getPosition();
    sf::FloatRect getGlobalBounds();
    void reverseDirection();
};
