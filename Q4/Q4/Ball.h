#pragma once
#include <SFML/Graphics.hpp>

class Ball
{
private:
    sf::Vector2f speed;
    float ball_size;
    sf::Vector2f position;
    sf::CircleShape body;
    float velocity;
public:
    Ball(sf::Vector2f init_pos);
    void Update(sf::RenderWindow& window);
    void Move(float dt);
    void Collide();
    void Destroy();
};

