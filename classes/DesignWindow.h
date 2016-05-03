//DesignWindow.h
//v1.0 05.04.2016
//by DSL.legozaur

#ifndef DSL_DESIGNWINDOW_H
#define DSL_DESIGNWINDOW_H

#include "Design.h"

class DesignWindow :
	public Design
{
public:
	DesignWindow(void);
	DesignWindow(sf::String filename);
	void data(void);
	bool load(sf::String filename);
	~DesignWindow(void);
};

#endif DSL_DESIGNWINDOW_H

