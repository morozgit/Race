#include<iostream>
#include"Car.h"
#include"Let.h"
//#include"Map.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1200, 800), "Race");

    sf::Image map_image;
    map_image.loadFromFile("Images/map.png");
    sf::Texture map;
    map.loadFromImage(map_image);
    sf::Sprite s_map;
    sf::Sprite s_map1;
    s_map.setTexture(map);
    s_map1.setTexture(map);
    //s_map.setScale(1.2f, 1.6f);
    //s_map1.setScale(1.2f, 1.6f);

    Let wall(450, 0, 420, 200);
    float let_count = -300;
    float let_psosition_x = 370;
    float randomX = 350 + rand() % 201;



    float currentFrame = 0;
    sf::Clock clock;

    Car car(400, 500);

    double BackgroundY1 = 0;
    double BackgroundY2 = -800;

    while (window.isOpen())
    {
        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time = time / 800;

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        car.moveCar(time);

        window.clear();
        s_map.setPosition(0, BackgroundY1);
        s_map1.setPosition(0, BackgroundY2);

        if (BackgroundY2 > 0)
        {
            BackgroundY1 = 0;
            BackgroundY2 = BackgroundY1 - 800;
        }
        if (let_count >= 800)
        {
            let_count = -300 + rand() % 380;
            let_psosition_x = 370 + rand() % 380;
//            std::cout << let_psosition_x << std::endl;
        }
        wall.let_sprite.setPosition(let_psosition_x, let_count);
        std::cout << " wall "<< static_cast<int>(wall.let_sprite.getPosition().y) << " Car " << static_cast<int>(car.raceSprite.getPosition().y)<< std::endl;
        if(static_cast<int>(wall.let_sprite.getPosition().y) == static_cast<int>(car.raceSprite.getPosition().y))
        {
            std::cout << "aaaaaaa";
        }
        // game speed
        BackgroundY1 += 0.3;
        BackgroundY2 += 0.3;
        let_count += 0.3; // speed let


        window.draw(s_map);
        window.draw(s_map1);
        window.draw(wall.let_sprite);
        window.draw(car.raceSprite);

        window.display();
    }

    return 0;
}
