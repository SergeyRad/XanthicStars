//Button.h
//version 07.04.2016
//by DSL.legozaur
#ifndef DSL_BUTTON_H
#define DSL_BUTTON_H

#include "WinItem.h"

class Button : 
	public WinItem
{
protected:
	//bool isHorizontal; // true - когда tileset горизонтальный
  int numTileMax;
	int numTileCur;
	int wTile;
	int hTile;
	void data();
	virtual ~Button(void);

public:
	bool isHorizontal; // true - когда tileset горизонтальный
	Button(void);
	void setNumTileMax(int num);
	void setTile(int num);
	bool check1(int* x, int* y);

	// √оризонтальный тайлсет (true)
	//void setIsHorizontal(bool boolean);
	//bool getIsHorizontal();
};

#endif DSL_BUTTON_H
