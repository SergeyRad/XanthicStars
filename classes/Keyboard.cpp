//Keyboard.cpp
#include "Keyboard.h"

// Created by Kildushov Oleg
// ��������� - ��������� ����
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
	bool isPressed = sf::Keyboard::isKeyPressed(key); // ������ �� ����������� �������?
	bool isPressed2 = mass[key]; // ���� �� �� ����� ������ ������ �������?
	
	if(isPressed2 != isPressed)
	{ // ���� ��������� ������� ��������
		if(isPressed2 == true)
		{ // ������ ���� ������, ������ �� ������
			mass[key] = false;
			return 3; // 3 ���� ���� ��������
		}
		else
		{ // ������ ���� �� ������, ������ ������
			mass[key] = true;
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