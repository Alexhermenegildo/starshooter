#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

class Player
{
private:
    sf::Sprite sprite;
    sf::Texture texture;


    float movementSpeed;

    float attackCooldown;
    float attackCooldownMax;

    int hp;
    int hpMax;

    //gui

    //Private functions
    void initVariables();
    void initTexture();
    void initSprite();

public:
    Player();
    virtual ~Player();

    //Accessor
    const sf::Vector2f& getPos() const;
    const sf::FloatRect getBounds() const;
    const int& getHp() const;
    const int& getHpMax() const;

    //modifiers

    void setPosition(const sf::Vector2f pos);
    void setPosition(float x, float y);
    void setHp(const int hp);
    void loseHp(const int value);

    //Functions
    void move(const float dirX, const float dirY);
    const bool canAttack();


    void updateAttack();
    void update();
    void render(sf::RenderTarget& target);

};