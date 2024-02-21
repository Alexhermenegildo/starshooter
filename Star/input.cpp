#include "engine.h"
 
void Engine::input()
{
    // Handle the player quitting
    if (Keyboard::isKeyPressed(Keyboard::Escape))
    {
        m_Window.close();
    }
 
    // Handle the player moving
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
 
}