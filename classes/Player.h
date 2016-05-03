//#pragma once
#include "stdafx.h"
#include "Object.h"
#include "spaceship.h"

#ifndef DSL_PLAYER_H
#define DSL_PLAYER_H

class Player : 
	public SpaceShip
{
public:
	Player();
	Player(sf::String filename);
	~Player();

	void data();
	void draw(sf::RenderWindow* window);
};

#endif  DSL_PLAYER_H

