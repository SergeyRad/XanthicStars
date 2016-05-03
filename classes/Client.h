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
// Создатель - Кильдюшов Олег
// vk.com/legozaur
// kychka-pc.ru - nikname: legozaur 

#ifndef DSL_CLIENT_H
#define DSL_CLIENT_H

class Client
{
private:
	sf::RenderWindow* renderWindow; // ссылка на окно
	std::vector<Map*> vecMap;

	std::vector<Menu*> vecMenu;

	std::vector<Mouse*> vecMouse; // вектор мышка
 	std::vector<Keyboard*> vecKeyboard; //  вектор клавиатура

	std::vector<Player*> vecPlayer; // вектор игрок
	std::vector<Spawn*> vecSpawn;   // вектор точек создания врагов
	//std::vector<Monsters*> vecMonsters; // вектор монстров


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
	bool setWindow(sf::RenderWindow* window); // Устанавливает связь Клиента и Окна
	void setMenu(Menu* menu);
	/////////////////////////////////////////////////////////////
	void newPlayer();
	/////////////////////////////////////////////////////////////
};

#endif  DSL_CLIENT_H
//