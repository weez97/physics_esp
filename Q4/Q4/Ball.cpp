#include "Ball.h"
#include <iostream>
#include <cmath>

Ball::Ball(sf::Vector2f init_pos)
{
	this->velocity = 0;
	this->ball_size = 15;
	this->angle = 0;
	this->position.x = init_pos.x - ball_size;
	this->position.y = init_pos.y - ball_size;
	this->init_pos = position;
	sf::CircleShape t(ball_size);
	t.setPosition(position);
	this->body = t;
}

void Ball::Update(sf::RenderWindow& window, float t) 
{
	Move(t);
	window.draw(body);
}

void Ball::Move(float dt)
{
	float vx = velocity * cos(angle);
	float vy = velocity * sin(angle);

	this->position.x += vx * dt;
	this->position.y += vy * dt - (0.5 * 9.8 * pow(dt, 2));

	this->body.setPosition(position);
	std::cout << position.x << "-" << position.y << std::endl;
}

void Ball::Preview(sf::RenderWindow& window) 
{
	window.draw(body);
}

void Ball::SetSpeed(float v, float ang) 
{
	this->velocity = v;
	this->angle = ang;
}
