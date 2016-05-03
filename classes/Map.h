#pragma once
#include "Image.h"

struct itemMap
{
	std::vector<Image*> vecImage;
	int x;
	int y;
	itemMap():x(0),y(0)
	{
		data();
	}
	void data(void)
	{
		vecImage.reserve(1);
		Image* img = new Image;
		vecImage.push_back(img);
	}
	void load(sf::String filename)
	{
		Image* img = new Image;
		img->load(filename);
		img->setScale(10,10);
		vecImage[0] = img;
	}
	void setXY(float newx, float newy)
	{
		x = newx;
		y = newy;
		vecImage[0]->setPosition(x,y);
	}
	void draw(sf::RenderWindow* window)
	{
		for(std::vector<Image*>::iterator it = vecImage.begin(); it != vecImage.end(); it++)
			(*it)->draw(window);
	}
};

class Map
{
protected:
	std::vector<itemMap*> vecItemMap;
public:
	void data(void);
	Map(void);
	~Map(void);
	void Generate_Bottom();
	void Generate_Middle();
	void Generate_Top();
	void drawMap(sf::RenderWindow* window);

};

