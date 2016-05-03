#include "Monsters.h"
#include "Spider.h"
#include "Bug.h"


Monsters::Monsters(void)
{
	data();
}

Monsters::~Monsters(void)
{
	//for(std::vector<Object*>::iterator it = vecTarget.begin(); it != vecTarget.end(); it++)
	//  delete(*it);
	//for(std::vector<Monster*>::iterator it = vecMonster.begin(); it != vecMonster.end(); it++)
	//  delete(*it);
}

void Monsters::data(void)
{
	for(int i = 0; i<0; i++)
	{
		Enemy* ship = new Enemy();                               //
		ship->load("2/spaceship0.png");                          //
		ship->setPosition(myRand1(100, 600), myRand1(100, 600)); // Устанавливаем в случайные координаты
		ship->setStatus(2);                                      // Устанавливаем статус 2
		ship->setIsMove(true);                                   // Разрешаем двигатся
		vecEnemy.push_back(ship);                                //
	}
	/*
  for(int i = 0; i<0; i++)
	{
		Spider* spider = new Spider();
		spider->setPosition(myRand1(100, 600), myRand1(100, 600));
		spider->setStatus(2);
		spider->setIsMove(true);
		vecMonster.push_back(spider);
	}
	for(int i = 0; i<1; i++)
	{
		Bug* bug = new Bug();
		bug->setPosition(myRand1(100, 600), myRand1(100, 600));
		bug->setStatus(2);
		bug->setIsRotate(true);
		bug->setIsMove(true);
		vecMonster.push_back(bug);
	}
	*/
}
void Monsters::draw(sf::RenderWindow *window)
{

	//for(std::vector<Monster*>::iterator it = vecMonster.begin(); it != vecMonster.end(); it++)
	//	(*it)->draw(window);
}

void Monsters::behavior(float time)
{
	//for(std::vector<Monster*>::iterator it = vecMonster.begin(); it != vecMonster.end(); it++)
	//{
	//	(*it)->behaviorObject(time);
		//cout << (*it)->getStatus();
	//}
	//cout << ";" << endl;
}
//////////////////////////////////
void Monsters::setTarget(Object* object)
{
	for(std::vector<Enemy*>::iterator it = vecEnemy.begin(); it != vecEnemy.end(); it++)
	  (*it)->setTarget(object);
}
///////////////////////////////////
void Monsters::setStatus(int status)
{
	//for(std::vector<Monster*>::iterator it = vecMonster.begin(); it != vecMonster.end(); it++)
	//{
	//	(*it)->setStatus(status);
	//	(*it)->setPosition(200, 200);
	//}
}