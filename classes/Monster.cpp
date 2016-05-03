#include "Monster.h"

Monster::Monster(void)
{
	data();
}
Monster::Monster(sf::String filename)
{
	data();
	load(filename);
}
Monster::~Monster(void)
{
}
void Monster::data(void)
{
	setIsMove(true);
	setStatus(1);
}

