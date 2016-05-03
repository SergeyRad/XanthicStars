#include "Spider.h"


Spider::Spider(void)
{
	load("tileset/monster/spider.png");
	data();
}


Spider::~Spider(void)
{
}


void Spider::data(void)
{
	data_speed(50, 0);
	data_frames(7, 4);
	data_frames_blackboard(4,4);
	setFlag1(false);
	setIsRotate(false);
	setNumFrameHcur(3);
	setRadiusAttack(50);
	setRadiusReview(300);
	setHp(100);
	setMp(0);
}

void Spider::behavior(float time)
{
	switch(getStatus())
	{
	//case 1: behavior_movement_rand(time);
	}
}