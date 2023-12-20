#include"Let.h"


Let::Let(float x, float y) : m_x(x),m_y(y)
{

    let_image.loadFromFile("Images/let.png");

    let_texture.loadFromImage(let_image);

    let_sprite.setTexture(let_texture);
    let_sprite.setTextureRect(sf::IntRect(m_x, m_y, 100, 120));
    let_sprite.setScale(1.2f, 1);
}
std::pair<float,float>Let::getCoordinates()
{
    return std::pair<float,float>(m_x, m_y);
}
 void Let::setLetPsositionX(float x)
 {
     m_x = x;
 }
