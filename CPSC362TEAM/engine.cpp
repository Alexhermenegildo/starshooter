#include "engine.h"

#include "engine.h"

Engine::Engine(sf::RenderWindow& window) : m_Window(window) {
    sf::Vector2f resolution;
    resolution.x = sf::VideoMode::getDesktopMode().width;
    resolution.y = sf::VideoMode::getDesktopMode().height;

    m_BackgroundTexture.loadFromFile("starbackground.png");
    m_BackgroundSprite.setTexture(m_BackgroundTexture);
}
void Engine::start()
{
    Clock clock;

    while (m_Window.isOpen())
    {
        Time dt = clock.restart();
        float dtAsSeconds = dt.asSeconds();

        input();
        update(dtAsSeconds);
        draw();
    }
}

void Engine::draw()
{
    m_Window.clear(Color::White);
    m_Window.draw(m_BackgroundSprite);
    m_Window.draw(m_Tuffy.getSprite());
    m_Window.draw(m_Enemy.getSprite());

    // Draw bullets
    for (const auto& bullet : m_Tuffy.getBullets())
    {
        m_Window.draw(bullet);
    }

    m_Window.display();
}

void Engine::input()
{
    if (Keyboard::isKeyPressed(Keyboard::Escape))
    {
        m_Window.close();
    }

    if (Keyboard::isKeyPressed(Keyboard::W))
    {
        m_Tuffy.moveUp();
    }
    else
    {
        m_Tuffy.stopUp();
    }

    if (Keyboard::isKeyPressed(Keyboard::S))
    {
        m_Tuffy.moveDown();
    }
    else
    {
        m_Tuffy.stopDown();
    }

    if (Keyboard::isKeyPressed(Keyboard::A))
    {
        m_Tuffy.moveLeft();
    }
    else
    {
        m_Tuffy.stopLeft();
    }

    if (Keyboard::isKeyPressed(Keyboard::D))
    {
        m_Tuffy.moveRight();
    }
    else
    {
        m_Tuffy.stopRight();
    }

    if (Keyboard::isKeyPressed(Keyboard::Space))
    {
        m_Tuffy.shoot();
    }
}

void Engine::update(float dtAsSeconds)
{
    m_Tuffy.update(dtAsSeconds);
    m_Enemy.update(dtAsSeconds);

    // Check collision between Tuffy's bullets and Enemy
    for (auto &bullet : m_Tuffy.getBullets())
    {
        if (bullet.getGlobalBounds().intersects(m_Enemy.getGlobalBounds()))
        {
            // Collision detected, handle accordingly
            // For example: remove bullet and reverse enemy's direction
            m_Tuffy.cleanUpBullets();
            m_Enemy.reverseDirection();
            break; // Exit loop after handling collision with one bullet
        }
    }
}
