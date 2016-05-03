//Mouse.h
#include "stdafx.h"

// Created by Kildushov Oleg
// ��������� - ��������� ����
// vk.com/legozaur
// kychka-pc.ru - nikname: legozaur 
// 10:06 16.12.2015

#ifndef DSL_MOUSE_H
#define DSL_MOUSE_H
#include "Cursor.h"

struct MouseKey
{
	bool isKeyPressed;
};

class Mouse
{
private:
	//=====
	std::vector<Cursor*> vecCursor;
	//=====

	int posX;
	int posY;
  bool mass[5];
	void data();
	sf::RenderWindow* window; // ������ �� ����
public:
	Mouse();
	~Mouse();

	bool setWindow(sf::RenderWindow *RenderWindow);

	void behavior();
	int getX();
	int getY();
	// ������ ������� ���������� �������, 
	// ������� ��������� � ����������� ��������, 
	// � ������� ������ �������
	// 0 - ��� �������         (�����������)
	// 1 - ������� �������     (��������)
	// 2 - ����������� ������� (�����������)
	// 3 - ���������� �������  (��������)
	int getEventButton(sf::Mouse::Button button);


	// =====
	void setDesign(sf::String filename);
	void setCursor(int number);
	void draw();
	void setMouseCursorVisible(bool boolean);
	// =====
};

#endif  DSL_MOUSE_H