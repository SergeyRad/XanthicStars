
#ifndef DSL_ITEM_H
#define DSL_ITEM_H
#include "stdafx.h"

class Item
{
protected:
	sf::Image image;
	sf::Texture texture;
	sf::Sprite sprite;
	int width;
	int height;
	bool isVisible;
	void data();
public:
	Item(void);
	virtual ~Item(void);


	bool load(sf::String);
	void setVisible(bool visible);
	bool getVisible(void);
	void draw(sf::RenderWindow* window);
	bool check1(int* x, int* y);
	int getW();
	int getH();
	int getX();
	int getY();
};
#endif DSL_ITEM_H

