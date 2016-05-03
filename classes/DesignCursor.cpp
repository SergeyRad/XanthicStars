//DeignCursor.cpp
//v1.0 05.04.2016
//by DSL.legozaur
#include "DesignCursor.h"
#include "stdafx.h"

DesignCursor::DesignCursor(sf::String filename)
{
	data();
	if(loadImage(filename) == true)
	{
		designToImage(&image, &vecImage[0], 0, 0, 32); // Курсор
		designToImage(&image, &vecImage[1], 1, 0, 32); // Перемещение
		designToImage(&image, &vecImage[2], 2, 0, 32); // Вертикальные
		designToImage(&image, &vecImage[3], 3, 0, 32); // Горизонтальные
		designToImage(&image, &vecImage[4], 4, 0, 32); // Лево-верх <-> Право-низ
		designToImage(&image, &vecImage[5], 5, 0, 32); // Лево-низ  <-> Право-верх
	}
}

DesignCursor::~DesignCursor(void)
{
	//
}

void DesignCursor::data(void)
{
	vecImage.reserve(6);
	for(int i=0; i<6; i++)
	{
		sf::Image img;
		vecImage.push_back(img); 
	}
}
