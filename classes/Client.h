//Client.h
#include "stdafx.h"
#include "keyboard.h"
#include "mouse.h"

#include "player.h"
//#include "monsters.h"
#include "spawn.h"

#include "image.h"
#include "menu.h"
#include "map.h"
//#include "view.h"

// Created by Kildushov Oleg
// ��������� - ��������� ����
// vk.com/legozaur
// kychka-pc.ru - nikname: legozaur 

#ifndef DSL_CLIENT_H
#define DSL_CLIENT_H

class Client
{
private:
	sf::RenderWindow* renderWindow; // ������ �� ����
	std::vector<Map*> vecMap;

	std::vector<Menu*> vecMenu;

	std::vector<Mouse*> vecMouse; // ������ �����
 	std::vector<Keyboard*> vecKeyboard; //  ������ ����������

	std::vector<Player*> vecPlayer; // ������ �����
	std::vector<Spawn*> vecSpawn;   // ������ ����� �������� ������
	//std::vector<Monsters*> vecMonsters; // ������ ��������


	int status_game;
public:
	Client();
	~Client();
	void start();

  void draw(sf::RenderWindow *window);

	void data();
	void behavior(float time);
	void behaviorMouse(float time);
	void behaviorKeyboard(float time);
	void behaviorObjects(float time);

	void setMouse(Mouse* mouse);
	void setKeyboard(Keyboard* keyboard);
	bool setWindow(sf::RenderWindow* window); // ������������� ����� ������� � ����
	void setMenu(Menu* menu);
	/////////////////////////////////////////////////////////////
	void newPlayer();
	/////////////////////////////////////////////////////////////
};

#endif  DSL_CLIENT_H
//