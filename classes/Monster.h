#pragma once
#include "stdafx.h"
#include "object.h"

class Monster :
	public Object
{
public:
	Monster(void);
	Monster(sf::String filename);
	~Monster(void);

	virtual void data(void) = 0;
	virtual void behavior(float time) = 0;
};

