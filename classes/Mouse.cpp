//Mouse.cpp
#include "Mouse.h"

// Created by Kildushov Oleg
// ��������� - ��������� ����
// vk.com/legozaur
// kychka-pc.ru - nikname: legozaur 
// 10:07 16.12.2015

Mouse::Mouse()
{
	data();
}
Mouse::~Mouse(){}
void Mouse::data()
{
	vecCursor.reserve(1);
	Cursor* cur = new Cursor();
	vecCursor.push_back(cur);

	posX = 0;
	posY = 0;
	for(int i = 0; i<5; i++)
		mass[i] = false; 
}

bool Mouse::setWindow(sf::RenderWindow *RenderWindow)
{
	try
	{
	  window = RenderWindow;
	}
	catch(...)
	{
		cout << "Error Mouse::setWindow";
		return false;
	}
	return true;
}

void Mouse::behavior()
{
	sf::Vector2i pixelPos = sf::Mouse::getPosition(*window);
	sf::Vector2f pos = (*window).mapPixelToCoords(pixelPos);
	posX = pos.x;
	posY = pos.y;
	vecCursor[0]->setPosition(posX, posY);
}
int Mouse::getX()
{
	return posX;
}
int Mouse::getY()
{
	return posY;
}

int Mouse::getEventButton(sf::Mouse::Button button)
{
	bool isPressed = sf::Mouse::isButtonPressed(button); // ������ �� ����������� �������?
	bool isPressed2 = mass[button]; // ���� �� �� ����� ������ ������ �������?

	if(isPressed2 != isPressed)
	{ // ���� ��������� ������� ��������
		if(isPressed2 == true)
		{ // ������ ���� ������, ������ �� ������
			mass[button] = false;
			return 3; // 3 ���� ���� ��������
		}
		else
		{ // ������ ���� �� ������, ������ ������
			mass[button] = true;
			return 1; // 1 ���� ���� ������
		}
	}
	else
	{ // ��������� �� ��������
		if(isPressed2 == true) // ���� ������ ���� ������
			return 2; // 2 ���� ������ ������
		else
			return 0; // 0 ���� ������ �� ������
	}
}

// =====
void Mouse::setDesign(sf::String filename)
{
	vecCursor[0]->setDesign(filename);
}
void Mouse::setCursor(int number)
{
	vecCursor[0]->setCursor(number);
}
void Mouse::draw()
{
	vecCursor[0]->draw(window);
}
void Mouse::setMouseCursorVisible(bool boolean)
{
	if(boolean == true)
	{
		window->setMouseCursorVisible(true);
		vecCursor[0]->isVisible = false;
	}
	else 
	{
		window->setMouseCursorVisible(false);
		vecCursor[0]->isVisible = true;
	}
}
// =====