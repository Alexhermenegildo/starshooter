#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

using namespace sf;

class Tuffy
{
private:
    Vector2f m_Position;
    Sprite m_Sprite;
    Texture m_Texture;
    bool m_UpPressed;
    bool m_DownPressed;
    bool m_LeftPressed;
    bool m_RightPressed;
    float m_Speed;
    std::vector<CircleShape> bullets; // Vector to store bullets

public:
    Tuffy();
    Sprite getSprite();
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    void stopUp();
    void stopDown();
    void stopLeft();
    void stopRight();
    void update(float elapsedTime);
    void shoot();
    std::vector<CircleShape>& getBullets();
    void cleanUpBullets();
};
