#pragma once
#include "stdafx.h"
#include "monster.h"

class Spider :
	public Monster
{
public:
	Spider(void);
	~Spider(void);
	void data(void);
	void behavior(float time);
};

