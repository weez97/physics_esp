#include "Ball.h"


Ball::Ball(sf::Vector2f init_pos)
{
	this->velocity = 0;
	this->position = init_pos;
	sf::CircleShape t(15.f);
	this->body = t;
}

void Ball::Move()
{

}

void Ball::Collide()
{

}

void Ball::Destroy()
{

}