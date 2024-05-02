#include "Game.h"
#include <SFML/Audio.hpp>
//Private Functions
void Game::initWindow()
{
        this->window = new sf::RenderWindow(sf::VideoMode::getDesktopMode(), "Tuffy Star Shooter", sf::Style::Default | sf::Style::Titlebar | sf::Style::Close | sf::Style::Resize | sf::Style::Fullscreen);
        this->window->setFramerateLimit(60);
        this->window->setVerticalSyncEnabled(false);
}

void Game::initTextures()
{
    this->textures["BULLET"]  = new sf::Texture();
    this->textures["BULLET"]->loadFromFile("bullet.png");
  // Load sound effect
    if (!this->shootBuffer.loadFromFile("laserSound.ogg")) {
        std::cout << "Failed to load shoot sound effect!" << std::endl;
    }

}

void Game::initMenu()
{
    // Load the menu image
    if (!this->menuTexture.loadFromFile("mainmenubackground.png"))
    {
        std::cout << "ERROR::GAME::COULD NOT LOAD MENU TEXTURE" << "\n";
    }

    // Set the texture to the sprite
    this->menuSprite.setTexture(this->menuTexture);
}

void Game::initGUI()
{
    //load fonts
    if(!this->font.loadFromFile("PlayfulTime-BLBB8.ttf"));
        std::cout << "ERROR::GAME::Failed to load font" <<"\n";

    //init point text
    this->pointText.setPosition(700.f,25.f);
    this->pointText.setFont(this->font);
    this->pointText.setCharacterSize(20);
    this->pointText.setFillColor(sf::Color::White);
    this->pointText.setString("test");

    this->highestScoreText.setPosition(500.f, 25.f); // Adjust position as needed
    this->highestScoreText.setFont(this->font); // Set font
    this->highestScoreText.setCharacterSize(20); // Set character size
    this->highestScoreText.setFillColor(sf::Color::White); // Set color
    this->highestScoreText.setString("Highest Score: 0"); // Initialize with default value


    this->gameOverText.setFont(this->font);
    this->gameOverText.setCharacterSize(60);
    this->gameOverText.setFillColor(sf::Color::Red);
    this->gameOverText.setString("     Game Over\n Press R to Restart");
    this->gameOverText.setPosition(
        this->window->getSize().x / 2.f - this->gameOverText.getGlobalBounds().width / 2.f,  //centering the game over
        this->window->getSize().y / 2.f - this->gameOverText.getGlobalBounds().height / 2.f);


    //init player gui
    this->playerHpBar.setSize(sf::Vector2f(300.f,25.f));
    this->playerHpBar.setFillColor(sf::Color::Red);
    this->playerHpBar.setPosition(sf::Vector2f(20.f,20.f));



    this->playerHpBarBack = this ->playerHpBar;
    this->playerHpBarBack.setFillColor(sf::Color(25,25,25,200));
}

void Game::initWorld()
{
    if (this->worldBackgroundTex.loadFromFile("background.jpg"))
    {
        std::cout << "ERROR::GAME::COULD NOT LOAD BACKGROUND TEXTURE" << "\n";
    }

    this->worldBackground.setTexture(this->worldBackgroundTex);
}

void Game::initSystems()
{
    this->points = 0;
    
    // Load background music
    if (!backgroundMusic.openFromFile("music.ogg")) {
        std::cout << "Failed to load background music!" << std::endl;
    }
}

void Game::initPlayer()
{
    this->player = new Player();


}

void Game::initEnemies()
{
    this->spawnTimerMax = 50.f;
    this->spawnTimer = this->spawnTimerMax;
}

// Con/Destructors
Game::Game() : highestScore(0) //
{
    this->initMenu();
    this->initWindow();
    this->initTextures();
    
    this->initGUI();
    this->initWorld();
    this->initSystems();
    this->initPlayer();
    this->initEnemies();

    // Initialize shoot sound
    this->shootSound.setBuffer(this->shootBuffer);
}

Game::~Game()
{
    delete this->window;
    delete this->player;

    //delete texture
    for(auto &i : this->textures)
    {
        delete i.second;
    
    }
    //delete bullets
    for (auto *i : this->bullets)
    {
        delete i;
    }

    //delete enemies
    for (auto *i : this->enemies)
    {
        delete i;
    }
}

//Functions

void Game::run()
{
    this->window->draw(this->menuSprite);
    this->window->display();
    backgroundMusic.play();
    // Wait for the user to press Enter
    while (true)
    {
        sf::Event event;
        while (this->window->pollEvent(event))
        {
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter)
            {
            while(this->window->isOpen())
        {
                this->updatePollEvent();
                if(this->player->getHp() > 0)
                    this->update();
                this->update();
                this->render();
        }
}
        }
        }
        }

void Game::updatePollEvent() {
    sf::Event e;
    while(this->window->pollEvent(e)) {
        if(e.type == sf::Event::Closed)
            this->window->close();
        if(e.type == sf::Event::KeyPressed) {
            if (e.key.code == sf::Keyboard::Escape)
                this->window->close();
            // Restart game when 'R' key is pressed after game over
            if (e.key.code == sf::Keyboard::R && this->player->getHp() <= 0)
                this->restart();
        }
    }
}

void Game::updateInput()
{
    //move player
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        this->player->move(-1.f,0.f);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        this->player->move(1.f,0.f);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        this->player->move(0.f,-1.f);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        this->player->move(0.f,1.f);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && this-> player->canAttack())
    {   
        // Play shoot sound effect
        this->shootSound.play();

        this->bullets.push_back(
        new Bullet(
        this->textures["BULLET"],
        this->player->getPos().x + this->player->getBounds().width/ 3.5f,
        this->player->getPos().y,
        0.f, 
        -1.f, 
        5.f));
    }
}

void Game::updateGUI()
{
    std::stringstream ss;
    ss << "Points: " << this->points;

    this->pointText.setString(ss.str());

    std::stringstream hs;
    hs << "Highest Score: " << this->highestScore;
    this->highestScoreText.setString(hs.str());

    //update player GUI

    float hpPercent =static_cast<float>(this->player->getHp()) / this->player->getHpMax();
    this->playerHpBar.setSize(sf::Vector2f(300.f * hpPercent , this->playerHpBar.getSize().y));
    
}

void Game::updateWorld()
{
}

void Game::updateCollision()
{
    //left world collision
    if(this->player->getBounds().left < -1.f)
    {
        this->player->setPosition(0.f,this->player->getBounds().top);
    }

    //right world collision
    else if(this->player->getBounds().left + this->player->getBounds().width >= this->window->getSize().x)
    {
        this->player->setPosition(this->window->getSize().x - this->player->getBounds().width, this->player->getBounds().top);
    }


    //top world collision
    if(this->player->getBounds().top < 0.f)
    {
        this->player->setPosition(this->player->getBounds().left , 0.f);
    }

    //bottom world collision (needs fixing)
    else if(this->player->getBounds().top + this->player->getBounds().height >= this->window->getSize().y)
    {
        this->player->setPosition(this->player->getBounds().left , this->window->getSize().y - this->player->getBounds().height);
    }
}

void Game::updateBullets()
{
    unsigned counter = 0;
    for (auto *bullet : this->bullets)
    {
        bullet->update();

        //bullet culling(top of the screen)
        if(bullet->getBounds().top + bullet->getBounds().height <= 0.f)
        {
            //delete bullet
            delete this->bullets.at(counter);
            this->bullets.erase(this->bullets.begin() + counter);

        }
        ++counter;
    }
}

void Game::updateEnemies()
{
    //Spawning
    this-> spawnTimer += 0.75f;
    if(this->spawnTimer >= this->spawnTimerMax)
    {
        this->enemies.push_back(new Enemy(rand() % this-> window->getSize().x-20.f, -100.f));
        this->spawnTimer = 0.f;
    }

    //update
    unsigned counter = 0;
    for (auto *enemy : this->enemies)
    {
        enemy->update();

        //bullet culling(top of the screen)
        if(enemy->getBounds().top > this->window->getSize().y)
        {
            //delete enemy
            delete this->enemies.at(counter);
            this->enemies.erase(this->enemies.begin() + counter);

        }

        //enemy player collison

        else if(enemy->getBounds().intersects(this->player->getBounds())) //if object touches player it deletes
        {
            this->player->loseHp(this->enemies.at(counter)->getDamage());
            delete this->enemies.at(counter);
            this->enemies.erase(this->enemies.begin() + counter);
            --counter;
            
        }

        ++counter;
    }
            
    
}

void Game::updateCombat() {
    for (int i = 0; i < this->enemies.size(); ++i) {
        bool enemy_deleted = false;
        for (size_t k = 0; k < this->bullets.size() && enemy_deleted == false; k++) {
            if(this->enemies[i]->getBounds().intersects(this->bullets[k]->getBounds())) {
                this->points += this->enemies[i]->getPoints(); //updates the points for the enemy

                delete this->enemies[i];
                this->enemies.erase(this->enemies.begin() + i);

                delete this->bullets[k];
                this->bullets.erase(this->bullets.begin() + k);

                enemy_deleted = true;
            }
        }
    }

    // Update highest score
    if (this->points > this->highestScore) {
        this->highestScore = this->points;
    }
}

void Game::update()
{

    this->updateInput();

    
    this-> player -> update();

    this->updateCollision();

    this->updateBullets();

    this->updateEnemies();

    this->updateCombat();

    this->updateGUI();

    this->updateWorld();
}

void Game::renderGUI()
{
    this->window->draw(this->pointText);
    this->window->draw(this->highestScoreText);
    this->window->draw(this->playerHpBarBack);  //renders transparent bar 
    this->window->draw(this->playerHpBar);      //renders red bar
}

void Game::renderWorld()
{
    this->window->draw(this->worldBackground);
}

void Game::render()
{
    this->window->clear();

    //draw World
    this->renderWorld();

    //draw all the stuff
    this->player->render(*this->window);

    for (auto *bullet : this->bullets)
    {
        bullet->render(this->window);
    }

        for (auto *enemy : this->enemies)
    {
        enemy->render(this->window);
    }

    this->renderGUI();

    //game over screen
    if(this->player->getHp() <= 0)
        this->window->draw(this->gameOverText);
        
    this->window->display();


}

void Game::restart() {
    // Reset player's health
    this->player->setHp(this->player->getHpMax());
    
    // Reset score
    this->points = 0;

    // Clear bullets and enemies
    for (auto *bullet : this->bullets) {
        delete bullet;
    }
    this->bullets.clear();

    for (auto *enemy : this->enemies) {
        delete enemy;
    }
    this->enemies.clear();

    // Reset spawn timer
    this->spawnTimer = this->spawnTimerMax;
}