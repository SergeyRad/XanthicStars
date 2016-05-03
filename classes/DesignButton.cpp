#include "stdafx.h"
#include "DesignButton.h"

//DesignWindow.cpp
//version 07.04.2016
//by DSL.legozaur
DesignButton::DesignButton(void)
{
	data();
}

DesignButton::~DesignButton(void)
{
}

void DesignButton::data(void)
{
	for(int i=0; i<4; i++)
	{
		sf::Image image;
		vecImage.push_back(image);
	}
}

bool DesignButton::load(sf::String filename, int orientation, int numCell)
{
	if(loadImage(filename))
	{
		if(orientation == 0)
		{
			// Горизонтальная
			int w = image.getSize().x;
			if(w % numCell == 0)
			{
				//
				w = image.getSize().x / numCell;
				for(int i=0; i<numCell; i++)
				{
			    designToImage(&image, &vecImage[0], i, 0, w);
				}
				return true;
			}
		} 
		else if(orientation ==1)
		{
			// Вертикальная
			int h = image.getSize().y;
			if(h % numCell == 0)
			{
				//
				h = image.getSize().x / numCell;
				for(int i=0; i<numCell; i++)
				{
			    designToImage(&image, &vecImage[0], 0, i, h);
				}
				return true;
			}
		}
	}
	return false;
}