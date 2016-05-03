#include "Item.h"
Item::Item(void)
{
	data();
}
Item::~Item(void)
{
}
void Item::data()
{
	width = 0;
	height = 0;
}
bool Item::load(sf::String filename)
{
	if(image.loadFromFile(filename))
	{
		texture.loadFromImage(image);
		sprite.setTexture(texture);
		width = image.getSize().x;
		height = image.getSize().y;
		sprite.setTextureRect(sf::IntRect(0,0,width,height));
		return true;
	}
	return false;
}
void Item::draw(sf::RenderWindow* window)
{
	if(isVisible)
	  window->draw(sprite);
}
void Item::setVisible(bool visible)
{
	isVisible = visible;
}
bool Item::getVisible()
{
	return isVisible;
}
int Item::getW()
{
	return width;
}
int Item::getH()
{
	return height;
}
int Item::getX()
{
	return sprite.getPosition().x;
}
int Item::getY()
{
	return sprite.getPosition().y;
}
bool Item::check1(int* x, int* y)
{
	if((sprite.getPosition().x <= *x) && (*x <= sprite.getPosition().x + width)
	&& (sprite.getPosition().y <= *y) && (*y <= sprite.getPosition().y + height)) 
	  return true;
	return false;
}