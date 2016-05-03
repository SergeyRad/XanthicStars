//DeignCursor.h
//v1.0 05.04.2016
//by DSL.legozaur
#pragma once
#include "Design.h"

class DesignCursor :
	public Design
{
private:
	void data(void);
public:
	DesignCursor(sf::String filename);
	~DesignCursor(void);
};

