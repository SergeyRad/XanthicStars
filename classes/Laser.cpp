#include "Laser.h"

Laser::Laser(void){}
Laser::~Laser(void){}

bool Laser::behaviorLaser(float time)
{
	// ��������� ������������
  moveObject(time);
	// � ���� ��������� �����, ���������� false
  return time_life(time);
}

void Laser::draw(sf::RenderWindow* window)
{
	window->draw(sprite);
}

//