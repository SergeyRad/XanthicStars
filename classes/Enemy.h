#pragma once

#include "spaceship.h"


class Enemy :
	public Object
{
private:
	void data(void);
public:
	///////////////////////////////////
	// ������������ � �����������
	///////////////////////////////////
	Enemy(void);
	~Enemy(void);
	///////////////////////////////////
	int behaviorEnemy(float time);
	void drawEnemy(sf::RenderWindow* window);
};

