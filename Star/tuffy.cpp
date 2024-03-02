#include "tuffy.h"

Tuffy::Tuffy()
{
    m_Speed = 400;
    m_Texture.loadFromFile("tuffyship.png");
    m_Sprite.setTexture(m_Texture);
    m_Position.x = 400;
    m_Position.y = 500;
}

Sprite Tuffy::getSprite()
{
    return m_Sprite;
}

void Tuffy::moveUp()
{
    m_UpPressed = true;
}

void Tuffy::moveDown()
{
    m_DownPressed = true;
}

void Tuffy::stopUp()
{
    m_UpPressed = false;
}

void Tuffy::stopDown()
{
    m_DownPressed = false;
}

void Tuffy::moveLeft()
{
    m_LeftPressed = true;
}

void Tuffy::moveRight()
{
    m_RightPressed = true;
}

void Tuffy::stopLeft()
{
    m_LeftPressed = false;
}

void Tuffy::stopRight()
{
    m_RightPressed = false;
}

void Tuffy::update(float elapsedTime)
{
    if (m_DownPressed)
    {
        m_Position.y += m_Speed * elapsedTime;
    }

    if (m_UpPressed)
    {
        m_Position.y -= m_Speed * elapsedTime;
    }

    if (m_RightPressed)
    {
        m_Position.x += m_Speed * elapsedTime;
    }

    if (m_LeftPressed)
    {
        m_Position.x -= m_Speed * elapsedTime;
    }

    m_Sprite.setPosition(m_Position);

    // Update bullets
    for (auto& bullet : bullets)
    {
        bullet.move(m_Speed * elapsedTime, 0); // Adjust bullet speed as needed
    }

    // Remove bullets that are out of bounds
    bullets.erase(std::remove_if(bullets.begin(), bullets.end(),
                    [](const CircleShape& bullet) {
                        return bullet.getPosition().y > 1000; // Adjust the limit based on your window width
                    }),
                    bullets.end());
}

void Tuffy::shoot()
{
    // Create a new bullet
    CircleShape bullet(5.f);
    bullet.setFillColor(Color::Yellow);
    bullet.setPosition(m_Position.x + m_Sprite.getGlobalBounds().width / 1.1, m_Position.y + m_Sprite.getGlobalBounds().height / 2);


    // Add the bullet to the vector
    bullets.push_back(bullet);
}

std::vector<CircleShape>& Tuffy::getBullets()
{
    return bullets;
}

void Tuffy::cleanUpBullets()
{
    // Remove bullets that are out of bounds
    bullets.erase(std::remove_if(bullets.begin(), bullets.end(),
                    [&](const CircleShape& bullet) {
                        return bullet.getPosition().x > (m_Position.x + 800); 
                    }),
                    bullets.end());
}


