#pragma once
#include "tilemovi.h"
class BlastEffect :
	public Tilemovi
{
public:
	BlastEffect(void);
	~BlastEffect(void);
	void data(void);
	bool behavior(float time);
	void drawBlastEffect(sf::RenderWindow* window);
};

