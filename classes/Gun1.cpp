#include "Gun1.h"

Gun1::Gun1(void)
{
	data();
}

Gun1::~Gun1(void)
{
	//
}

void Gun1::data(void)
{
	centerX = 0;
  centerY = 0;
	dx = 0;
	dy = 0;
}

void Gun1::draw(sf::RenderWindow *window)
{
	window->draw(sprite);
}

void Gun1::setCenter(float x, float y)
{
	centerX = x;
	centerY = y;
	update();
}

void Gun1::setDXY(float dx, float dy)
{
	this->dx = dx;
	this->dy = dy;
	update();
}

void Gun1::update(void)
{
	if(centerX != NULL && centerY != NULL)
	  setPosition(centerX + dx, centerY + dy);
}

