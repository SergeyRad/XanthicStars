//Keyboard.h
#include "stdafx.h"

// Created by Kildushov Oleg
// Создатель - Кильдюшов Олег
// vk.com/legozaur
// kychka-pc.ru - nikname: legozaur 
// v16.12.2015 14:57

#ifndef DSL_KEYBOARD_H
#define DSL_KEYBOARD_H

class Keyboard
{
private:
  bool mass[101];
	void data();
public:
	Keyboard();
	~Keyboard();
 	// Данная функция возвращает событие, 
	// которое произошло с принимаемой клавишей, 
	// в текущий момент времени
	// 0 - нет событий         (многократно)
	// 1 - нажатие клавиши     (единожды)
	// 2 - удерживание клавиши (многократно)
	// 3 - отпускание клавишы  (единожды)
	int getEventButton(sf::Keyboard::Key key);
};

#endif  DSL_KEYBOARD_H