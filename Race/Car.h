#pragma once
#include <SFML/Graphics.hpp>

class Car
{
public:
	Car(float x, float y):m_x(x),m_y(y)
	{
		raceImage.loadFromFile("Images/Race.png");
		raceTexture.loadFromImage(raceImage);
		raceSprite.setTexture(raceTexture);
		raceSprite.setPosition(m_x, m_y);
		raceSprite.setScale(0.4, 0.4);
	}
	~Car() = default;
	sf::Sprite raceSprite;

private:

	float m_x = 0, m_y = 0;
	sf::Image raceImage;
	sf::Texture raceTexture;
	
};


