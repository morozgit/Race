#include <SFML/Graphics.hpp>

class Car
{
public:
    Car(float x, float y);
    ~Car() = default;
    sf::Sprite raceSprite;
    void moveCar(float);

private:

    float m_x = 0, m_y = 0;
    sf::Image raceImage;
    sf::Texture raceTexture;

};
