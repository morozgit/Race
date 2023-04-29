#include<iostream>
#include "Car.h"

Car::Car(float x, float y):m_x(x),m_y(y)
{
    raceImage.loadFromFile("Images/Race.png");
    raceTexture.loadFromImage(raceImage);
    raceSprite.setTexture(raceTexture);
    raceSprite.setTextureRect(sf::IntRect(55, 10, 159, 359));
    raceSprite.setPosition(m_x, m_y);
    raceSprite.setScale(0.4, 0.4);
}

void Car::moveCar(float time)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        if (raceSprite.getPosition().x < 300)
        {
            raceSprite.setPosition(300, raceSprite.getPosition().y);
        }
        raceSprite.move(-0.2 * time, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        if (raceSprite.getPosition().x > 805)
        {
            raceSprite.setPosition(805, raceSprite.getPosition().y);
        }
        raceSprite.move(0.2 * time, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        if (raceSprite.getPosition().y < 4)
        {
            raceSprite.setPosition(raceSprite.getPosition().x, 4);
        }
        raceSprite.move(0, -0.9*time);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        if (raceSprite.getPosition().y > 640)
        {
            raceSprite.setPosition(raceSprite.getPosition().x, 640);
        }
        raceSprite.move(0, 0.3 * time);
    }
}

void Car::checkCrash(Let &let)
{
    if(this->raceSprite.getGlobalBounds().intersects(let.let_sprite.getGlobalBounds()))
    {
        health = health - 1;
    }
}


int Car::getHealth()
{
    return health;
}






