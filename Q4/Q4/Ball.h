#pragma once
#include <SFML/Graphics.hpp>

class Ball
{
private:
    sf::Vector2f position;
    sf::CircleShape body;
    float velocity;
public:
    Ball(sf::Vector2f init_pos);
    void Move();
    void Collide();
    void Destroy();
};

