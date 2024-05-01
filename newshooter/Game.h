#pragma once
#include<map>
#include<string>
#include<sstream>

#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"

class Game
{
private:
    //window
    sf::RenderWindow* window;

    //resources
    std::map<std::string, sf::Texture*> textures;
    std::vector<Bullet*> bullets;

    //GUI
    sf::Font font;
    sf::Text pointText;

    sf::Text gameOverText;
    sf::Text highestScoreText; // Declare highest score text
    sf::Text restartText;

    //world
    sf::Texture worldBackgroundTex;
    sf::Sprite worldBackground;

    //menu
    sf::Texture menuTexture;
    sf::Sprite menuSprite;

    //systems
    unsigned points;
    unsigned highestScore;


    //PLayer
    Player* player;

    //PlayerGUI
    sf::RectangleShape playerHpBar;
    sf::RectangleShape playerHpBarBack;
    //Enemies
    float spawnTimer;
    float spawnTimerMax;
    std::vector<Enemy*> enemies;



    //private fucntions
    void initWindow();
    void initTextures();
    void initGUI();
    void initWorld();
    void initSystems();
    void initPlayer();
    void initEnemies();
    void initMenu();

public:
    Game();
    virtual ~Game();

    //Functions

    void run();

    void updatePollEvent();
    void updateInput();
    void updateGUI();
    void updateWorld();
    void updateCollision();
    void updateBullets();
    void updateEnemies();
    void updateCombat();
    void update();
    void renderGUI();
    void renderWorld();
    void render();
    void restart();

};