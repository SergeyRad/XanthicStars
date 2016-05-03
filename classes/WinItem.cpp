//WinItem.cpp
//version 07.04.2016
//by DSL.legozaur
#include "WinItem.h"


WinItem::WinItem(void)
{
	data();
}
WinItem::~WinItem(void)
{
}
void WinItem::data()
{
	dx_left  = 0;
  dx_right = 0;
  dy_up    = 0;
  dy_down  = 0;
	flag1 = false;
	flag2 = false;
	winX = NULL;
	winY = NULL;
	winW = NULL;
	winH = NULL;
}

void WinItem::set(sf::String str, int value)
{
	if(str == "a") { dx_left  = value; flag1 = false; }
	if(str == "d") { dx_right = value; flag1 = true;  }
	if(str == "w") { dy_up    = value; flag2 = false; }
	if(str == "s") { dy_down  = value; flag2 = true;  }
}

void WinItem::update()
{
	int xNew = 0;
	int yNew = 0;
	if(winX != NULL && winY != NULL)
	{
	  xNew = (*winX);
	  yNew = (*winY);

	if(flag1 == false)
		xNew += dx_left;
	else
		xNew += *winW - dx_right;

	if(flag2 == false)
	  yNew += dy_up;
	else
		yNew += *winH - dy_down;
	}
	sprite.setPosition(xNew, yNew);
}

void WinItem::setWindow(int* xWin, int* yWin, int* wCur, int* hCur)
{
	winX = xWin;
	winY = yWin;
	winW = wCur;
	winH = hCur;
}
