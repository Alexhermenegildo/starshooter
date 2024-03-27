// engine.h
#pragma once
#include <SFML/Graphics.hpp>
#include "tuffy.h"
#include "enemy.h"

class Engine
{
private:
    sf::RenderWindow& m_Window; // Reference to the game window
    sf::Sprite m_BackgroundSprite;
    sf::Texture m_BackgroundTexture;
    Tuffy m_Tuffy;
    Enemy m_Enemy;

public:
    Engine(sf::RenderWindow& window); // Constructor accepting a window parameter
    void start();
    void input();
    void update(float dtAsSeconds);
    void draw();
};
