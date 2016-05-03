//Button.cpp
//version 07.04.2016
//by DSL.legozaur
#include "stdafx.h"
#include "Button.h"


Button::Button(void)
{
	data();
}
Button::~Button(void)
{
	//
}
void Button::data()
{
	isHorizontal = true;
	numTileMax = 0;
	numTileCur = -1;
	wTile = 0;
	hTile = 0;
}
void Button::setNumTileMax(int num)
{
	numTileMax = num;
		
	if(isHorizontal)
	{
		// Горизонтальный тайлсет
		wTile = width/numTileMax;
		hTile = height;
	} 
	else 
	{
		// Вертикальный тайлсет
		wTile = width;            
		hTile = height/numTileMax;
	}
}
void Button::setTile(int num)
{
	if(numTileCur != num)
	{
		numTileCur = num;
		if(isHorizontal)
      sprite.setTextureRect(sf::IntRect(numTileCur*wTile, 0, wTile, hTile));
		else
			sprite.setTextureRect(sf::IntRect(0, numTileCur*hTile, wTile, hTile));
	}
}
bool Button::check1(int* x, int* y)
{
	if((sprite.getPosition().x <= *x) && (*x <= sprite.getPosition().x + wTile)
	&& (sprite.getPosition().y <= *y) && (*y <= sprite.getPosition().y + hTile)) 
	  return true;
	return false;
}
/*
void Button::setIsHorizontal(bool boolean)
{
	isHorizontal = boolean;
}
bool Button::getIsHorizontal()
{
	return isHorizontal;
}
*/
//