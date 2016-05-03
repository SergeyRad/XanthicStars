#include "Map.h"


Map::Map(void)
{
	data();
}
Map::~Map(void)
{
}
void Map::data(void)
{
	vecItemMap.reserve(0);
	Generate_Bottom();
	Generate_Middle();
	Generate_Top();
}
void Map::Generate_Bottom()
{
	srand(time(NULL));
	itemMap* item = new itemMap();
	item->setXY(1000,0);
	vecItemMap.push_back(item);

	for(int i = 1; i < 200; i++)
	{
		int newX = 0;
		int newY = 0;
		itemMap* item2 = new itemMap();

		item2->load("itemMap1.png");
		newX = vecItemMap[i-1]->x;
		newY = vecItemMap[i-1]->y;
		int r = rand() % 2;
		if(r == 1) 
			newX -= 1000;

		if(newX == vecItemMap[i-1]->x)
		{
			r = rand() % 2;
			
			if (r == 0)
				newY += 1000; 
			else 
				newY -= 1000;
		}
		item2->setXY(newX, newY);
		vecItemMap.push_back(item2);
	}
}
void Map::Generate_Middle()
{
}
void Map::Generate_Top()
{
}
void Map::drawMap(sf::RenderWindow* window)
{
	for(std::vector<itemMap*>::iterator it = vecItemMap.begin(); it != vecItemMap.end(); it++)
	{
		(*it)->draw(window);
	}
}