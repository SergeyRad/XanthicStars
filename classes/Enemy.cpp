#include "Enemy.h"


Enemy::Enemy(void)
{
	//
}
Enemy::~Enemy(void)
{
	//
}
void Enemy::data(void)
{
	setIsMove(true);
	//data_speed(50, 0);
	//setIsRotate(true);
	//setRadiusAttack(50);
	//setRadiusReview(300);
	//setHp(100);
	//setMp(0);

	setStatus(0); // ÍÈ×ÅÃÎ ÍÅ ÄÅËÀÅÌ

	//newTarget1(0,0);
}
//////////////////////////////////////////
int Enemy::behaviorEnemy(float time)
{
	behaviorObject(time);
	return 0;
}
void Enemy::drawEnemy(sf::RenderWindow* window)
{
	window->draw(sprite);
}