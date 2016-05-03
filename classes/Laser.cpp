#include "Laser.h"

Laser::Laser(void){}
Laser::~Laser(void){}

bool Laser::behaviorLaser(float time)
{
	// Выполняет передвижение
  moveObject(time);
	// И если кончилось время, возвращает false
  return time_life(time);
}

void Laser::draw(sf::RenderWindow* window)
{
	window->draw(sprite);
}

//