#pragma once
#include "stdafx.h"
#include "monster.h"
#include "object.h"
#include "enemy.h"

class Monsters
{
private:
	void data(void);
	//std::vector<Object*> vecTarget;
	//std::vector<Monster*> vecMonster;
	std::vector<Enemy*> vecEnemy;
public:
	Monsters(void);
	~Monsters(void);
	void draw(sf::RenderWindow *window);
	void behavior(float time);
	void setTarget(Object* object);
	void setStatus(int status);
};

