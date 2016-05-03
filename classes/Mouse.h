//Mouse.h
#include "stdafx.h"

// Created by Kildushov Oleg
// Создатель - Кильдюшов Олег
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
	sf::RenderWindow* window; // Ссылка на окно
public:
	Mouse();
	~Mouse();

	bool setWindow(sf::RenderWindow *RenderWindow);

	void behavior();
	int getX();
	int getY();
	// Данная функция возвращает событие, 
	// которое произошло с принимаемой клавишей, 
	// в текущий момент времени
	// 0 - нет событий         (многократно)
	// 1 - нажатие клавиши     (единожды)
	// 2 - удерживание клавиши (многократно)
	// 3 - отпускание клавишы  (единожды)
	int getEventButton(sf::Mouse::Button button);


	// =====
	void setDesign(sf::String filename);
	void setCursor(int number);
	void draw();
	void setMouseCursorVisible(bool boolean);
	// =====
};

#endif  DSL_MOUSE_H