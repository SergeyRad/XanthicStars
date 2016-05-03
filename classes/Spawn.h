#pragma once
#include "stdafx.h"
#include "Enemy.h"
#include "Laser.h"
#include "blasteffect.h"
class Spawn
{
private:
	/////////////////////////////////////////////
	std::vector<BlastEffect*> vecBlastEffect;  //
	std::vector<int>          vecIntBlast;     // 0 - бласт свободен
	int num_blast_free;
	int num_blast_max;
	/////////////////////////////////////////////
	sf::CircleShape circle;
 	std::vector<Enemy*> vecEnemy;
	float x;
	float y;
	float radius;
	void data(void);
public:
	Spawn(void);
	~Spawn(void);

	bool preLoad();

	void data2(int tip, int number, float radius);
	void setXY(float x, float y);
	float getX();
	float getY();

	void newEnemy(sf::String filename);
	void drawSpawn(sf::RenderWindow* window);
	int  behaviorSpawn(float time);
  void setTarget(Object* target);

	bool hitTestPoint(std::vector<Laser*>* vec);
	void addBlastEffect(float x, float y);

	void deleteSpawn();
};

