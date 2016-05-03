#pragma once
#include "DesignCursor.h"

class Cursor
{
private:
	sf::Image image;
	sf::Texture texture;
	sf::Sprite sprite;

	std::vector<DesignCursor*> vecDesign; // Вектор для 1 дизайна
	int numCur;
	void data(void);
public:
	bool isVisible;
	Cursor(void);
	~Cursor(void);

	void setDesign(sf::String filename); 
	bool setCursor(int number);
	void setPosition(float x, float y);
	void setVisible(bool boolean);

	void draw(sf::RenderWindow* window);
};

