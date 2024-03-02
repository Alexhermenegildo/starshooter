#pragma once
#include <SFML/Graphics.hpp>
#include "tuffy.h"

using namespace sf;

class Engine
{
private:
    RenderWindow m_Window;
    Sprite m_BackgroundSprite;
    Texture m_BackgroundTexture;
    Tuffy m_Tuffy;

public:
    Engine();
    void start();
    void input();
    void update(float dtAsSeconds);
    void draw();
};
