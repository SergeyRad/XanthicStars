//DesignWindow.cpp
//version 07.04.2016
//by DSL.legozaur
#ifndef DSL_DESIGNBUTTON_H
#define DSL_DESIGNBUTTON_H

#include "design.h"
class DesignButton :
	public Design
{
public:
	DesignButton(void);
	~DesignButton(void);
	void data(void);
	bool load(sf::String filename, int orientation, int numCell);
};

#endif DSL_DESIGNBUTTON_H