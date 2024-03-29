#include "Bullet.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>

using namespace sf;


void Bullet::update(float dt, RenderWindow & w)
{
	curr_lifetime += dt;
	if (curr_lifetime > lifetime) {
		is_dead = true;
	}
	Vector2f pos = circle.getPosition();
	pos.x += cos(angle)*speed*dt;
	pos.y += sin(angle)*speed*dt;
	if (pos.x > sw)	pos.x = 0;
	if (pos.x < 0) pos.x = sw;
	if (pos.y > sh)	pos.y = 0;
	if (pos.y < 0) pos.y = sh;
	circle.setPosition(pos);
}

void Bullet::hit()
{
	is_dead = true;
}

Bullet::Bullet(float a, Vector2f pos, int sw, int sh)
{
	circle.setRadius(radius);
	circle.setFillColor(Color::Green);
	circle.setPosition(pos);
	angle = a;
	this->sw = sw;
	this->sh = sh;
}


Bullet::~Bullet()
{
}
