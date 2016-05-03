#include "Cursor.h"
#include "stdafx.h"

Cursor::Cursor(void)
{
	data();
}

Cursor::~Cursor(void)
{
}

void Cursor::data(void)
{
	vecDesign.reserve(1);
	DesignCursor* dc = new DesignCursor("");
	vecDesign.push_back(dc);
	isVisible = false;
	numCur = -1;
}

void Cursor::setDesign(sf::String filename)
{
	DesignCursor* dc = new DesignCursor(filename);
	vecDesign[0] = dc;
}

bool Cursor::setCursor(int number)
{
	if(number != numCur)
	{
		numCur = number;
		image = vecDesign[0]->getImage(number);
		texture.loadFromImage(image);
		sprite.setTexture(texture);
		sprite.setTextureRect(sf::IntRect(0,0,image.getSize().x, image.getSize().y));
		if(number != 0)
		{
			sprite.setOrigin(image.getSize().x/2, image.getSize().y/2);
		} else {
			sprite.setOrigin(0,0);
		}
	}
	return true;
}

void Cursor::setPosition(float x, float y)
{
	sprite.setPosition(x, y);
}
void Cursor::setVisible(bool boolean)
{
	isVisible = boolean;
}
void Cursor::draw(sf::RenderWindow* window)
{
	if(isVisible)
		window->draw(sprite);
}