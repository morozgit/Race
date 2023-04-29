#include <SFML/Graphics.hpp>
#include"Let.h"
class Car
{
public:
    Car(float x, float y);
    ~Car() = default;
    sf::Sprite raceSprite;
    void moveCar(float);
    int getHealth();
    void checkCrash(Let&);

private:

    float m_x = 0, m_y = 0;
    int health = 100;
    sf::Image raceImage;
    sf::Texture raceTexture;


};
