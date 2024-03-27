#include "mainmenu.h"

MainMenu::MainMenu(sf::RenderWindow& window) : m_Window(window) {
    sf::Vector2f resolution;
    resolution.x = sf::VideoMode::getDesktopMode().width;
    resolution.y = sf::VideoMode::getDesktopMode().height;
    m_BackgroundTexture.loadFromFile("mainmenubackground.png");
    m_BackgroundSprite.setTexture(m_BackgroundTexture);
}

void MainMenu::show() {
    
    while (m_Window.isOpen()) {
        sf::Event event;
        while (m_Window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                m_Window.close();

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter)
                return; 
        }

       
        m_Window.clear();
        m_Window.draw(m_BackgroundSprite);
        m_Window.display();
    }
}
