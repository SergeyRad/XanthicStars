//SpaceShip.h

#include "stdafx.h"

#ifndef DSL_SPACESHIP_H
#define DSL_SPACESHIP_H

#include "object.h"
#include "Gun1.h"

class SpaceShip :
	public Object
{
private:
	//////////////////////////////////
	// Перенесли из класса Gun1
	int num_laser_free;
	std::vector<Laser*> vecLaser;
	//////////////////////////////////
	std::vector<Gun1*> vecGun1;
	float mouseX;
	float mouseY;

  int laser_tip;

	void data(void);
public:
	SpaceShip(void);
	~SpaceShip(void);
	void preLoad();

  void drawSpaceShip(sf::RenderWindow* window);
	//=================================
	void spaceShip_behavior(float time);
	void spaceShip_move(float time);
	void spaceShip_rotate(float time, bool right);
	void spaceShip_speedUp(float time, bool up);
	void spaceShip_update();
	//=================================
	void addGun1(sf::String filename, float centerX, float centerY, float dx, float dy);
	void mouse_SetPosition(float x, float y);
	//=================================
	void shot(float x, float y);
  void newLaser();
	std::vector<Laser*>* getVectorLaser();
};

#endif DSL_SPACESHIP_H

