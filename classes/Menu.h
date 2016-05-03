#pragma once
#include "image.h"
#include "button.h"
#include "mwindows.h"
#include "mouse.h"
class Menu :
	public Image
{
private:
	void data(void);
protected:
	std::vector<MWindows*> vecMWindows;
	//std::vector<Button*> vecButton;
public:
	bool isVisible;
	Menu(void);
	~Menu(void);

	int behavior(float time, Mouse* mouse);
	void draw(sf::RenderWindow* window);
	void setFond(sf::String filename);
	void addButton(sf::String filename, float x, float y);
};

