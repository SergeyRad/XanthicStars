#pragma once


#include "object.h"


class Laser :
	public Object
{
public:
	Laser(void);
	~Laser(void);
	bool behaviorLaser(float time);
	void draw(sf::RenderWindow* window);
};

