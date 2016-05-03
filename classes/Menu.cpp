#include "Menu.h"


Menu::Menu(void)
{
	data();
}
Menu::~Menu(void)
{
	//
}
void Menu::data(void)
{
	// Создаём систему окон
	vecMWindows.reserve(1);
	//setScale(0.5, 0.5);
	isVisible = true;
	MWindows* w0 = new MWindows();
	// Создаём окно
	Window* w = new Window(500, 700, true, true, true);
	w->setPosition(50,50);
	//w->setDesign("images/Design/Window/flyff/flyff.png"); 
	w->isVisible = false;
	//w->addButtonClose("images/Design/Button/butCloseWin8.1.png", 0, 0, 1, 3);
	
	w->addButton("images/Menu/1.png", 50,  0, 1, 3);
	w->addButton("images/Menu/2.png", 50, 110, 1, 3);
	w->addButton("images/Menu/3.png", 50, 220, 1, 3);
	w->addButton("images/Menu/4.png", 50, 330, 1, 3);
	w->addButton("images/Menu/5.png", 50, 440, 1, 3);
	w->addButton("images/Menu/6.png", 50, 550, 1, 3);

	w0->add(w);
	// Заносим в вектор систему окон
	vecMWindows.push_back(w0);
	/*
	addButton("Menu/button.png", 50, 50);
	addButton("Menu/button.png", 50, 150);
	addButton("Menu/button.png", 50, 250);
	addButton("Menu/button.png", 50, 350);
	addButton("Menu/button.png", 50, 450);
	addButton("Menu/button.png", 50, 550);
	*/
}
void Menu::draw(sf::RenderWindow* window)
{
	if(isVisible == true)
	{
		window->draw(sprite);
		for(std::vector<MWindows*>::iterator it = vecMWindows.begin(); it != vecMWindows.end(); it++)
		{
			//cout << "DRAWWWW" << endl;
			(*it)->draw(window);
		}
	}
}
void Menu::setFond(sf::String filename)
{
	load(filename);
	setOriginNum(1);
}
int  Menu::behavior(float time, Mouse* mouse)
{
	if(isVisible == true)
	{
	  if(vecMWindows[0]->behavior(mouse) == false)
		{
			isVisible = false;
			return 1;
		}
	}
	return 0;
}
void Menu::addButton(sf::String filename, float x, float y)
{
	Button* button = new Button();
	button->load(filename);
}