#include "Player.h"


Player::Player()
{
	data();
}



Player::Player(sf::String filename)
{
	data();
	load(filename);
}


Player::~Player()
{
}


void Player::data()
{
	setRadiusAttack(100);
	setRadiusReview(300);
	setHp(500);
	setMp(300);
}


void Player::draw(sf::RenderWindow* window)
{
	drawImage(window);
	window->draw(sprite);
}



