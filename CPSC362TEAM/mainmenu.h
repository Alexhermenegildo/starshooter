#pragma once

#include <SFML/Graphics.hpp>

class MainMenu {
public:
    MainMenu(sf::RenderWindow& window);

    void show();

private:
    sf::RenderWindow& m_Window;
    sf::Texture m_BackgroundTexture;
    sf::Sprite m_BackgroundSprite;
};