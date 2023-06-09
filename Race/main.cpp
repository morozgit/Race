#include<iostream>
#include"Car.h"
//#include"Map.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1200, 800), "Race");

    sf::Image map_image;//������ ����������� ��� �����
    map_image.loadFromFile("Images/map.png");//��������� ���� ��� �����
    sf::Texture map;//�������� �����
    map.loadFromImage(map_image);//�������� �������� ���������
    sf::Sprite s_map;//������ ������ ��� �����
    sf::Sprite s_map1;
    s_map.setTexture(map);//�������� �������� ��������
    s_map1.setTexture(map);//�������� �������� ��������
    //s_map.setScale(1.2f, 1.6f);
    //s_map1.setScale(1.2f, 1.6f);

    float currentFrame = 0; // ������� ����
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
        ///////////////////////////////������ �����/////////////////////
        //for (int i = 0; i < HEIGHT_MAP; i++)
        //    for (int j = 0; j < WIDTH_MAP; j++)
        //    {
        //        if (TileMap[i][j] == ' ')  s_map.setTextureRect(sf::IntRect(0, 0, 32, 32)); //���� ��������� ������ ������, �� ������ 1� ���������
        //        if (TileMap[i][j] == 's')  s_map.setTextureRect(sf::IntRect(32, 0, 32, 32));//���� ��������� ������ s, �� ������ 2� ���������
        //        if ((TileMap[i][j] == '0')) s_map.setTextureRect(sf::IntRect(64, 0, 32, 32));//���� ��������� ������ 0, �� ������ 3� ���������
        //        if ((TileMap[i][j] == 'f')) s_map.setTextureRect(sf::IntRect(96, 0, 32, 32));//�������� ������
        //        if ((TileMap[i][j] == 'h')) s_map.setTextureRect(sf::IntRect(128, 0, 32, 32));//� ��������

        //        s_map.setPosition(j * 32, i * 32);//�� ���� ����������� ����������, ��������� � �����. �� ���� ������ ������� �� ��� �������. ���� ������, �� ��� ����� ���������� � ����� �������� 32*32 � �� ������ ���� �������
        //       
        //        window.draw(s_map);//������ ���������� �� �����
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