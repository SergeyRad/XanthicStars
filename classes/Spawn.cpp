#include "Spawn.h"


Spawn::Spawn(void)
{
	data();
}
Spawn::~Spawn(void)
{
	//
}
void Spawn::data(void)
{
	x = 0;
	y = 0;
	radius = 0;
	num_blast_free = 0;
	num_blast_max  = 0;
	vecEnemy.reserve(0);
	preLoad();
}
void Spawn::data2(int tip, int number, float radius)
{
	this->radius = radius;

	for(int i=0; i<number; i++)
	{
		switch(tip)
		{
		case 1: newEnemy("2/3.png"); break;
		case 2: newEnemy("2/4.png"); break;
		}
	}
	circle.setPosition(x, y);
	circle.setOrigin(radius, radius);
	circle.setRadius(radius);
	circle.setOutlineThickness(2);
	circle.setFillColor(sf::Color(0,0,0,0));
	//
}
void Spawn::newEnemy(sf::String filename)
{
	Enemy* enemy = new Enemy();
	enemy->load(filename);
	enemy->setRadiusPhysical(40);
	int newX = myRand1(x-radius, x+radius);
	int newY = myRand1(y-radius, y+radius);
	if(distance(x,y,newX,newY) <= radius)
	{
	  enemy->setPosition(newX, newY);
	  enemy->setScale(0.25, 0.25);
	  vecEnemy.push_back(enemy);
	}
	else
	{
		newEnemy(filename);
	}
}
void Spawn::setXY(float x, float y)
{
	this->x = x;
	this->y = y;
}
float Spawn::getX()
{
	return x;
}
float Spawn::getY()
{
	return y;
}

void Spawn::drawSpawn(sf::RenderWindow* window)
{
	window->draw(circle);
	for(std::vector<Enemy*>::iterator it = vecEnemy.begin(); it != vecEnemy.end(); it++)
		(*it)->drawEnemy(window);
	
	for(int i=0; i<num_blast_max; i++)
	{
		if(vecIntBlast[i] == 1)
			vecBlastEffect[i]->draw(window);
	}
}
int  Spawn::behaviorSpawn(float time_)
{
	for(std::vector<Enemy*>::iterator it = vecEnemy.begin(); it != vecEnemy.end(); it++)
	{
		(*it)->behaviorEnemy(time_);
		srand(time(NULL));
		(*it)->move(myRand1(-35,45)*time_, myRand1(-35,70)*time_);
	}
	for(int i=0; i<num_blast_max; i++)
	{
		if(vecIntBlast[i] == 1)
		{
			if(!vecBlastEffect[i]->behavior(time_))
			{
				vecIntBlast[i] = 0;
				num_blast_free++;
			}
		}
	}
	return 0;
}
void Spawn::setTarget(Object* target)
{
	for(std::vector<Enemy*>::iterator it = vecEnemy.begin(); it != vecEnemy.end(); it++)
		(*it)->setTarget(target);
}
bool Spawn::preLoad()
{
	vecBlastEffect.reserve(5);
	vecIntBlast.reserve(5);
	for(int i=0; i<15; i++)
	{
		BlastEffect* b = new BlastEffect();
		vecBlastEffect.push_back(b);
		num_blast_free++;
		num_blast_max++;
		vecIntBlast.push_back(0);
	}
	return true;
}
bool Spawn::hitTestPoint(std::vector<Laser*>* vec)
{
	bool flag = false;
	std::vector<Laser*> vecLaser = *vec;
	// Проходим по врагам
	for(std::vector<Enemy*>::iterator it = vecEnemy.begin(); it != vecEnemy.end(); it++)
	{
		if((*it)->getActivism() == true)
		{
			for(std::vector<Laser*>::iterator it2 = vecLaser.begin(); it2 != vecLaser.end(); it2++)
			{
				if((*it2)->getActivism() == true)
				{
					if(HitTestPointCircle((*it)->getPositionX(),
															  (*it)->getPositionY(),
															  (*it)->getRadiusPhysical(),
															  (*it2)->getPositionX(),
															  (*it2)->getPositionY(),
															  (*it2)->getRadiusPhysical()
															  )
						)
					{
						(*it)->deactivation();
						(*it2)->deactivation();
						addBlastEffect((*it)->getPositionX(), (*it)->getPositionY());
						flag = true;
						break;
					}

				}
			}
		}
	}
	return flag;
}

void Spawn::addBlastEffect(float x, float y)
{
	cout << "1";
	// Если есть свободные взрывы
	if(num_blast_free > 0)
	{
		// Проходим по всевозможным вариантам
		for(int i=0; i<num_blast_max; i++)
		{
			// Если бласт свободен
			if(vecIntBlast[i] == 0)
			{
			  vecIntBlast[i] = 1;
				vecBlastEffect[i]->setPosition(x, y);
				break;
			}
		}
	}
	// Иначе нету свободных взрывов
	else
	{
		// НА БУДУЩЕЕ (добавление взрыва, если все заняты)
		/*
		cout << "6";
		BlastEffect* b = new BlastEffect();
		vecBlastEffect.push_back(b);
		num_blast_free++;
		num_blast_max++;
		vecIntBlast.push_back(0);
		addBlastEffect(x, y);
		*/
	}
}

void Spawn::deleteSpawn()
{
	for(std::vector<Enemy*>::iterator it = vecEnemy.begin(); it != vecEnemy.end(); it++)
	{
		if((*it)->getActivism() == true)
		{
			(*it)->deactivation();
			addBlastEffect((*it)->getPositionX(), (*it)->getPositionY());
		}
	}

}