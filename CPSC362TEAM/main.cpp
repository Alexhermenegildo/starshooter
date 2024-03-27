#include "engine.h"
#include "mainmenu.h"

int main() {
     sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Tuffy Star Shooter", sf::Style::Fullscreen);
    // Show main menu
    MainMenu mainMenu(window);
    mainMenu.show();

    // Start the game
    Engine engine(window);
    engine.start();

    return 0;
}