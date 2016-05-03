//WinItem.h
//version 07.04.2016
//by DSL.legozaur
#ifndef DSL_WINITEM_H
#define DSL_WINITEM_H
#include "stdafx.h"
#include "Item.h"
class WinItem :
	public Item
{
protected:
	// —сылки на координаты и размеры окна
	int* winX;
	int* winY;
	int* winW;
	int* winH;
	// —мещение относительно краЄв окна
	int dx_left;
	int dy_up;
	int dx_right;
	int dy_down;
	bool flag1; // true - прив€зка справа
	bool flag2; // true - прив€зка снизу

	void data();
public:
	WinItem(void);
	~WinItem(void);
	
	void set(sf::String str, int value);
	void update();
	void setWindow(int* xWin, int* yWin, int* wCur, int* hCur);
};

#endif DSL_WINITEM_H
