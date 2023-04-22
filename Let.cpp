#include"Let.h"

Let::Let(float x, float y, float hight,float widht) : m_x(x),m_y(y),m_hight(hight),m_widht(widht)
{

    let_image.loadFromFile("Images/let.png");

    let_texture.loadFromImage(let_image);

    let_sprite.setTexture(let_texture);
    let_sprite.setTextureRect(sf::IntRect(m_x, m_y, m_hight, m_widht));
    let_sprite.setScale(1.2f, 1);
}
