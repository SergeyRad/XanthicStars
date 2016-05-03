//DesignWindow.cpp
//version 03.04.2016 17:10
//by DSL.legozaur
#include "stdafx.h"
#include "DesignWindow.h"

DesignWindow::DesignWindow()
{
	//
}
// Конструктор 
DesignWindow::DesignWindow(sf::String filename)
{
	//
}
void DesignWindow::data(void)
{
	for(int i=0; i<9; i++)
	{
		sf::Image image;
		vecImage.push_back(image);
	}
}
bool DesignWindow::load(sf::String filename)
{
	if(loadImage(filename))
	{
		data();
		// Расположение картинок в векторе
		// 0 4 1
		// 5 8 6
		// 2 7 3
		// Режем image и заполняем картинки vecImage[0-8]
				designToImage(&image, &vecImage[0], 0, 0, 32);
		if(!designToImage(&image, &vecImage[1], 2, 0, 32)) { designToImage(&image, &vecImage[1], 0, 0, 32); vecImage[1].flipHorizontally(); }
				designToImage(&image, &vecImage[2], 0, 2, 32);
		if(!designToImage(&image, &vecImage[3], 2, 2, 32)) { designToImage(&image, &vecImage[3], 0, 2, 32); vecImage[3].flipHorizontally(); }
				designToImage(&image, &vecImage[4], 1, 0, 32);
				designToImage(&image, &vecImage[5], 0, 1, 32);
		if(!designToImage(&image, &vecImage[6], 2, 1, 32)) { designToImage(&image, &vecImage[6], 0, 1, 32); vecImage[6].flipHorizontally(); }
				designToImage(&image, &vecImage[7], 1, 2, 32);
				designToImage(&image, &vecImage[8], 1, 1, 32);

		return true;
	}
	return false;
}
// Деструктор
DesignWindow::~DesignWindow(void)
{
	//
}