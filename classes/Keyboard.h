//Keyboard.h
#include "stdafx.h"

// Created by Kildushov Oleg
// ��������� - ��������� ����
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
 	// ������ ������� ���������� �������, 
	// ������� ��������� � ����������� ��������, 
	// � ������� ������ �������
	// 0 - ��� �������         (�����������)
	// 1 - ������� �������     (��������)
	// 2 - ����������� ������� (�����������)
	// 3 - ���������� �������  (��������)
	int getEventButton(sf::Keyboard::Key key);
};

#endif  DSL_KEYBOARD_H