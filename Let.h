#include <SFML/Graphics.hpp>

class Let
{
public:
    Let(float x, float y, float hight,float widht);
    ~Let() = default;
    sf::Sprite let_sprite;
private:
    float m_x = 0;
    float m_y = 0;
    float m_hight = 0;
    float m_widht = 0;
    sf::Image let_image;
    sf::Texture let_texture;

};
