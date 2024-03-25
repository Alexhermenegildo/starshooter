#pragma once
#include <SFML/Graphics.hpp>
#include "tuffy.h"
#include "enemy.h"

using namespace sf;

class Engine
{
private:
    RenderWindow m_Window;
    Sprite m_BackgroundSprite;
    Texture m_BackgroundTexture;
    Tuffy m_Tuffy;
    Enemy m_Enemy;

public:
    Engine();
    void start();
    void input();
    void update(float dtAsSeconds);
    void draw();
};
