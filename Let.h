#include <SFML/Graphics.hpp>
#include <Python.h>

class Let
{
public:
    Let(float x, float y);
    ~Let() = default;
    sf::Sprite let_sprite;
    std::pair<float, float> getCoordinates();
    void setLetPsositionX(float);
private:
    float m_x = 0;
    float m_y = 0;
    sf::Image let_image;
    sf::Texture let_texture;

};

