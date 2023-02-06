#include "Ball.h"
#include <iostream>
#include <typeinfo>

Ball::Ball(sf::Vector2f init_pos)
{
	this->speed = { 100, 100 };
	this->ball_size = 15;
	this->velocity = 0;
	this->position = init_pos;
	sf::CircleShape t(ball_size);
	t.setPosition(init_pos.x - ball_size, init_pos.y - ball_size);
	this->body = t;
}

void Ball::Update(sf::RenderWindow& window) 
{
	window.draw(body);
}

void Ball::Move(float dt)
{
	this->position += speed * dt;
	this->body.setPosition(this->position);
}

void Ball::Collide()
{

}

void Ball::Destroy()
{

}