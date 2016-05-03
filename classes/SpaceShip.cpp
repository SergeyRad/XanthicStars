//SpaceShip.cpp

#include "SpaceShip.h"


SpaceShip::SpaceShip(void)
{
	data();
}
SpaceShip::~SpaceShip(void)
{
}
void SpaceShip::data(void)
{
	vecGun1.reserve(1);
	speedUp = speedMax/0.5;
	speedMin = 0;
	num_laser_free = 0;
	preLoad();
}
void SpaceShip::preLoad(void)
{
	int num = 20;
	vecLaser.reserve(num);
  for(int i=0; i<num; i++)
		newLaser();
}
void SpaceShip::spaceShip_behavior(float time)
{
	// передвигаем корабль
	//if(isMove && speed != 0) - автоматическа€ пауза по остановке
	if(isMove)
	{
		spaceShip_move(time);
		for(std::vector<Gun1*>::iterator it = vecGun1.begin(); it != vecGun1.end(); it++)
		{
			(*it)->setCenter(getPositionX(), getPositionY());
			(*it)->setRotation(d_angle(mouseX-getPositionX(), mouseY-getPositionY()));
			(*it)->update();
		}
	}
		for(std::vector<Laser*>::iterator it = vecLaser.begin(); it != vecLaser.end(); it++)
		{  
			(*it)->behaviorLaser(time);
			/*
			if((*it)->behaviorLaser(time) == false)
			{
				//(*it)->deactivation();
				//num_laser_free++;
			}
			*/
		}
}
void SpaceShip::spaceShip_move(float time)
{
	move(speedX*time, speedY*time);
}
void SpaceShip::spaceShip_rotate(float time, bool right)
{
	if(right == true)
		rotate(speedRotation*time);
	else
		rotate(-speedRotation*time);

	spaceShip_update();
}

void SpaceShip::spaceShip_speedUp(float time, bool up)
{
	// ≈сли повышение скорости
	if(up == true)
	{
		// ≈сли скорость меньше максимальной
		if(speed < speedMax)
		{
			// прибавл€ем к скорости ускорение
			speed += speedUp*time;
			// если скорость больше максимально
			if(speed > speedMax)
			{
				// приравниваем скорость к максимальной
				speed = speedMax;
			}
			spaceShip_update();
		}
	}
	// »наче понижение скорости
	else
	{
		// ≈сли скорость больше минимальной
		if(speed > speedMin)
		{
			// «амедл€емс€
			speed -= speedUp*time;
			// ≈сли скорость меньше минимальной
			if(speed < speedMin)
			{
				// ѕриравниваем скорость к минимальной
				speed = speedMin;
			}
			spaceShip_update();
		}
	}
}
void SpaceShip::spaceShip_update()
{
	speedX =      speed * mySin(getRotation());
	speedY = -1 * speed * myCos(getRotation());
}
void SpaceShip::drawSpaceShip(sf::RenderWindow* window)
{
	window->draw(sprite);
	for(std::vector<Gun1*>::iterator it = vecGun1.begin(); it != vecGun1.end(); it++)
		(*it)->draw(window);
	for(std::vector<Laser*>::iterator it = vecLaser.begin(); it != vecLaser.end(); it++)
		(*it)->draw(window);
}

void SpaceShip::addGun1(sf::String filename, float centerX, float centerY, float dx, float dy)
{
	Gun1* gun = new Gun1();
	gun->load(filename);
	gun->setCenter(centerX, centerY);
	gun->setDXY(dx, dy);
	vecGun1.push_back(gun);
}
void SpaceShip::mouse_SetPosition(float x, float y)
{
	mouseX = x;
	mouseY = y;
}

///////////////////////////////////////////////
// LASER
///////////////////////////////////////////////
void SpaceShip::shot(float x, float y)
{
	for(std::vector<Gun1*>::iterator it = vecGun1.begin(); it != vecGun1.end(); it++)
	{
		// «аписываем в x и y координаты оруди€
		float x = (*it)->getPositionX();
		float y = (*it)->getPositionY();
		float a = (*it)->getRotation();
		//
		if(num_laser_free > 0)
		{
			for(std::vector<Laser*>::iterator it = vecLaser.begin(); it != vecLaser.end(); it++)
			{
				if((*it)->getActivism() == false)
				{
					// јктивируем в новых координатах
					(*it)->activation(x+25*mySin(a), y-25*myCos(a), 1000, a, true,	1);
					// ћинус один свободный лазер
					num_laser_free--;
					break;
				}
			}
		}
		else
		{
			newLaser();
		  shot(x, y);
		}
	}
}
void SpaceShip::newLaser()
{
	Laser* laser = new Laser();
	laser->load("laser/laser1.png");
	laser->data_time_life(2, 0);
	laser->deactivation_();
	laser->setRadiusPhysical(2);
	num_laser_free++;
	vecLaser.push_back(laser);
}
std::vector<Laser*>* SpaceShip::getVectorLaser()
{
	return &vecLaser;
}