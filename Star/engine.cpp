// engine.cpp
#include "tuffy.h"
#include "engine.h"

Engine::Engine()
{
    // Get the screen resolution and create an SFML window and View
    Vector2f resolution;
    resolution.x = VideoMode::getDesktopMode().width;
    resolution.y = VideoMode::getDesktopMode().height;
 
    m_Window.create(VideoMode(resolution.x, resolution.y),
        "Tuffy Star Shooter",
        Style::Fullscreen);
 
    // Load the background into the texture
    // Be sure to scale this image to your screen size
    m_BackgroundTexture.loadFromFile("starbackground.png");
 
    // Associate the sprite with the texture
    m_BackgroundSprite.setTexture(m_BackgroundTexture);
 
}
 
void Engine::start()
{
    // Timing
    Clock clock;
 
    while (m_Window.isOpen())
    {
        // Restart the clock and save the elapsed time into dt
        Time dt = clock.restart();
 
        // Make a fraction from the delta time
        float dtAsSeconds = dt.asSeconds();
 
        input();
        update(dtAsSeconds);
        draw();
    }
}
void Engine::draw()
{
    // Rub out the last frame
    m_Window.clear(Color::White);

    // Draw the background
    m_Window.draw(m_BackgroundSprite);
    m_Window.draw(m_Tuffy.getSprite());

    // Show everything we have just drawn
    m_Window.display();
}