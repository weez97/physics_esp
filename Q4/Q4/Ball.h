#pragma once
#include <SFML/Graphics.hpp>

class Ball
{
private:
    float velocity;
    float ball_size;
    float angle;
    sf::Vector2f init_pos;
    sf::Vector2f position;
    sf::CircleShape body;
public:
    Ball(sf::Vector2f init_pos);
    void Update(sf::RenderWindow& window, float t);
    void Move(float dt);
    void Preview(sf::RenderWindow& window);
    void SetSpeed(float v, float ang);
};

