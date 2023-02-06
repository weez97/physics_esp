#include <SFML/Graphics.hpp>
#include <iostream>
#include <list>
#include "Ball.h"

using namespace std;

list<Ball*> ball_list;      //our list of balls

sf::Vertex line[] = { sf::Vertex(sf::Vector2f(-1,-1)), sf::Vertex(sf::Vector2f(-1,-1)) };   //this helps us draw our aim indicator

#pragma region ENTITIES
//actually create a ball and add it to our list of entities
Ball* createBall(sf::Vector2f init_pos)     
{
    Ball* ball = new Ball(init_pos);
    ball_list.push_back(ball);
    return ball;
}
#pragma endregion

#pragma region DRAWING
//draw our aim line
void traceLine(sf::RenderWindow& window)    
{
    if (line[0].position == sf::Vector2f(-1, -1))
        return;
    window.draw(line, 2, sf::Lines);
}

//update every ball in the list
void updateBalls(sf::RenderWindow& window, float dt)
{
    for (Ball* b : ball_list)
        b->Update(window);
}
#pragma endregion

int main()
{
    sf::Clock clock;    // to get our deltaTime

    float dt;

    sf::RenderWindow window(sf::VideoMode(1000, 1000), "Physics thingy");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            //when a mouse button is pressed
            if (event.type == sf::Event::MouseButtonPressed)
            {
                //if it's the left button
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    //keep track of the mouse click position
                    sf::Vector2f mouse_click_pos = {(float)event.mouseButton.x, (float)event.mouseButton.y };
                    line[0] = mouse_click_pos;
                    
                    //create a new ball
                    createBall(mouse_click_pos);
                }
            }

            //while the left mouse button is pressed
            if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
            {
                //update the end of our aim line
                line[1].position = (sf::Vector2f)sf::Mouse::getPosition(window);
            }

            //when a mouse button is released
            if (event.type == sf::Event::MouseButtonReleased)
            {
                //if it's the left button
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    //keep track of the release position to keep drawing our aim line until a new ball is created
                    sf::Vector2f mouse_release_pos = { (float)event.mouseButton.x, (float)event.mouseButton.y };
                    line[1] = mouse_release_pos;
                }
            }

            //if a kwy is pressed
            if (event.type == sf::Event::KeyPressed)
            {
                //and it's the spacebar
                if (event.key.code == sf::Keyboard::Space)
                {
                    //shoot the ball
                    std::cout << "shootBall" << std::endl;
                }
            }
        }

        window.clear();
        
        //update our delta time
        dt = clock.restart().asSeconds();

        //draw the aim line
        traceLine(window);

        //update the balls
        updateBalls(window, dt);
        window.display();
    }

    return 0;
}