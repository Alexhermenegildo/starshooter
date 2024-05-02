#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

#include "Game.h"
#include<time.h>
using namespace sf;

int main()
{
  
  srand(time(static_cast<unsigned>(0)));

  Game game;
  
  game.run();

  return 0;
}

