#include "enemy.h"

Bullet::Bullet(float startX, float startY)
{
    m_Position.x = startX;
    m_Position.y = startY;
    m_Speed = 1000.0f; // Adjust speed as needed
    m_Shape.setSize(sf::Vector2f(10, 5)); // Adjust size as needed
    m_Shape.setFillColor(sf::Color::Red);
    m_Shape.setPosition(m_Position);
}

void Bullet::update(float elapsedTime)
{
    m_Position.x -= m_Speed * elapsedTime;
    m_Shape.setPosition(m_Position);
}

sf::FloatRect Bullet::getGlobalBounds()
{
    return m_Shape.getGlobalBounds();
}

sf::RectangleShape& Bullet::getShape()
{
    return m_Shape;
}

Enemy::Enemy()
{
    m_Speed = 100.0f; // Adjust speed as needed
    m_Texture.loadFromFile("enemy.png"); // Load enemy texture from file
    m_Sprite.setTexture(m_Texture); // Set texture to sprite

    // Set initial position of enemy (on the right side of the screen)
    m_Position.x = 1500.0f; // Adjust as needed
    m_Position.y = 500.0f; // Adjust as needed
    m_Sprite.setPosition(m_Position);

    m_MovingUp = true; // Initially moving upwards
}

sf::Sprite Enemy::getSprite()
{
    return m_Sprite;
}

void Enemy::update(float elapsedTime)
{
    // Update enemy's position (move up or down based on direction, and advance to the left)
    float movement = m_Speed * elapsedTime;
    if (m_MovingUp)
    {
        m_Position.y -= movement;
        if (m_Position.y <= 0) // If reached top of the screen
        {
            m_MovingUp = false;
        }
    }
    else
    {
        m_Position.y += movement;
        if (m_Position.y + m_Sprite.getGlobalBounds().height >= 1000) // Adjust limit based on window height
        {
            m_MovingUp = true;
        }
    }
    m_Position.x -= movement; // Advance to the left
    m_Sprite.setPosition(m_Position);

    // Update enemy's bullets
    for (auto& bullet : m_Bullets)
    {
        bullet.update(elapsedTime);
    }
}

void Enemy::shoot()
{
    // Create a new bullet
    Bullet bullet(m_Position.x, m_Position.y + m_Sprite.getGlobalBounds().height / 2);

    // Add the bullet to the vector
    m_Bullets.push_back(bullet);
}

std::vector<Bullet>& Enemy::getBullets()
{
    return m_Bullets;
}

sf::Vector2f Enemy::getPosition()
{
    return m_Position;
}

sf::FloatRect Enemy::getGlobalBounds()
{
    return m_Sprite.getGlobalBounds();
}

void Enemy::reverseDirection()
{
    m_MovingUp = !m_MovingUp; // Reverse movement direction
}
