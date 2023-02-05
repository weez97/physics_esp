#include <SFML/Graphics.hpp>
#include <iostream>
#include <list>
#include "Ball.h"

using namespace std;

list<Ball*> ball_list;

#pragma region ENTITIES
Ball* createBall(sf::Vector2f init_pos) 
{
    Ball* ball = new Ball(init_pos);
    ball_list.push_back(ball);
    return ball;
}
#pragma endregion

#pragma region DRAWING
void drawBalls() 
{
    for (Ball* b : ball_list)
    {

    }
}
#pragma endregion

int main()
{
    sf::Vector2f mouse_click_pos;
    sf::Vector2f mouse_release_pos;


    sf::RenderWindow window(sf::VideoMode(1000, 1000), "Physics thingy");


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    mouse_click_pos = {(float)event.mouseButton.x, (float)event.mouseButton.y };
                    std::cout << "mouse pos: " << mouse_click_pos.x << "," << mouse_click_pos.y << endl;
                }
            }

            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Space)
                {
                    std::cout << "shootBall" << std::endl;
                }
            }
        }

        window.clear();
        //window.draw(shape);
        window.display();
    }

    return 0;
}