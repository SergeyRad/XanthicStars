#pragma once
#include "image.h"
#include "laser.h"

class Gun1 :
	public Image
{
private:
	//int num_laser_free;
	//std::vector<Laser*> vecLaser;

	float centerX;
  float centerY;
  float dx;
  float dy;

	void data();
public:
	Gun1(void);
	~Gun1(void);
	void draw(sf::RenderWindow *window);

	void setCenter(float x, float y);
	void setDXY(float dx, float dy);
	void update(void);
};

