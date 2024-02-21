#include "tuffy.h"
 
Tuffy::Tuffy()
{
    m_Speed = 400; //tuffy's movement speed
 
    m_Texture.loadFromFile("spaceship.png");
    m_Sprite.setTexture(m_Texture);     
 
    m_Position.x = -100; //tuffy's starting position
    m_Position.y = 400;
 
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
 
// Move Tuffy based on the input this frame,
// the time elapsed, and the speed
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
 
    // Now move the sprite to its new position
    m_Sprite.setPosition(m_Position);   
 
}