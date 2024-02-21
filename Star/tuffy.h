#pragma once
#include <SFML/Graphics.hpp>
 
using namespace sf;
 
class Tuffy
{
private:
 
    // Where is Tuffy
    Vector2f m_Position;
    // Of course we will need a sprite
    Sprite m_Sprite;
 
    // And a texture
    // Tuffy has been working out and he is now a bit more muscular than before
    // Furthermore, he fancies himself in lumberjack attire
    Texture m_Texture;
 
    // Which direction(s) is the player currently moving in
    bool m_UpPressed;
    bool m_DownPressed;
    bool m_LeftPressed;
    bool m_RightPressed;
 
    // Tuffy's speed in pixels per second
    float m_Speed;
 
    // Public functions
public:
 
    // We will set Tuffy up in the constructor
    Tuffy();
 
    // Send a copy of the sprite to main
    Sprite getSprite();
 
    // Move Tuffy in a specific direction
    void moveUp();
 
    void moveDown();

    void moveLeft();

    void moveRight();
 
    // Stop Tuffy moving in a specific direction
    void stopUp();
 
    void stopDown();
 
    void stopLeft();
 
    void stopRight();
    // We will call this function once every frame
    void update(float elapsedTime);
 
};