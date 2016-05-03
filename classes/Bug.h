#pragma once
#include "stdafx.h"
#include "monster.h"
class Bug :
	public Monster
{
public:
	Bug(void);
	~Bug(void);
	void data(void);

	void behavior(float time);
};

