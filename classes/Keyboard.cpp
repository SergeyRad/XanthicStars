//Keyboard.cpp
#include "Keyboard.h"

// Created by Kildushov Oleg
// Создатель - Кильдюшов Олег
// vk.com/legozaur
// kychka-pc.ru - nikname: legozaur 
// v16.12.2015 14:57

Keyboard::Keyboard()
{
	data();
}
Keyboard::~Keyboard(){}
void Keyboard::data()
{
	for(int i = 0; i<101; i++)
		mass[i] = false; 
}
int Keyboard::getEventButton(sf::Keyboard::Key key)
{
	bool isPressed = sf::Keyboard::isKeyPressed(key); // Нажата ли принимаемая клавиша?
	bool isPressed2 = mass[key]; // Была ли до этого нажата данная клавиша?
	
	if(isPressed2 != isPressed)
	{ // Если состояние клавишь различны
		if(isPressed2 == true)
		{ // Кнопка была нажата, теперь не нажата
			mass[key] = false;
			return 3; // 3 если была отпущена
		}
		else
		{ // Кнопка была не нажата, теперь нажата
			mass[key] = true;
			return 1; // 1 если была нажата
		}
	}
	else
	{ // Состояние не менялось
		if(isPressed2 == true) // Если кнопка была нажата
			return 2; // 2 если кнопка зажата
		else
		  return 0; // 0 если кнопка не нажата
	}
}