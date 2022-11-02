#include<iostream>
#include"Car.h"
//#include"Map.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1200, 800), "Race");

    sf::Image map_image;//объект изображения для карты
    map_image.loadFromFile("Images/map.png");//загружаем файл для карты
    sf::Texture map;//текстура карты
    map.loadFromImage(map_image);//заряжаем текстуру картинкой
    sf::Sprite s_map;//создаём спрайт для карты
    sf::Sprite s_map1;
    s_map.setTexture(map);//заливаем текстуру спрайтом
    s_map1.setTexture(map);//заливаем текстуру спрайтом
    //s_map.setScale(1.2f, 1.6f);
    //s_map1.setScale(1.2f, 1.6f);

    float currentFrame = 0; // текущий кадр
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

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            car.raceSprite.move(-0.3*time, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            car.raceSprite.move(0.3 * time, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            car.raceSprite.move(0, -0.3*time);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            car.raceSprite.move(0, 0.3 * time);
        }
        window.clear();
        ///////////////////////////////Рисуем карту/////////////////////
        //for (int i = 0; i < HEIGHT_MAP; i++)
        //    for (int j = 0; j < WIDTH_MAP; j++)
        //    {
        //        if (TileMap[i][j] == ' ')  s_map.setTextureRect(sf::IntRect(0, 0, 32, 32)); //если встретили символ пробел, то рисуем 1й квадратик
        //        if (TileMap[i][j] == 's')  s_map.setTextureRect(sf::IntRect(32, 0, 32, 32));//если встретили символ s, то рисуем 2й квадратик
        //        if ((TileMap[i][j] == '0')) s_map.setTextureRect(sf::IntRect(64, 0, 32, 32));//если встретили символ 0, то рисуем 3й квадратик
        //        if ((TileMap[i][j] == 'f')) s_map.setTextureRect(sf::IntRect(96, 0, 32, 32));//добавили цветок
        //        if ((TileMap[i][j] == 'h')) s_map.setTextureRect(sf::IntRect(128, 0, 32, 32));//и сердечко

        //        s_map.setPosition(j * 32, i * 32);//по сути раскидывает квадратики, превращая в карту. то есть задает каждому из них позицию. если убрать, то вся карта нарисуется в одном квадрате 32*32 и мы увидим один квадрат
        //       
        //        window.draw(s_map);//рисуем квадратики на экран
        //    }
        //Creat scrolling background
        s_map.setPosition(0, BackgroundY1);
        s_map1.setPosition(0, BackgroundY2);
        if (BackgroundY2 > 0)
        {
            BackgroundY1 = 0;
            BackgroundY2 = BackgroundY1 - 800;
        }
        BackgroundY1 += 0.1;
        BackgroundY2 += 0.1;
        std::cout << s_map.getPosition().y << std::endl;
        /*count += 0.01;
        if (count > 0.6)
        {
            count = 0;
        }
        s_map.move(0, count);*/
        window.draw(s_map);
        window.draw(s_map1);
        window.draw(car.raceSprite);
        window.display();
    }

    return 0;
}