//Client.cpp
#include "Client.h"
#include "view.h"

Client::Client()
{
	data();
}
Client::~Client()
{
	for(std::vector<Mouse*>::iterator it = vecMouse.begin(); it != vecMouse.end(); it++)
		delete(*it);
	vecMouse.shrink_to_fit();

	for(std::vector<Keyboard*>::iterator it = vecKeyboard.begin(); it != vecKeyboard.end(); it++)
		delete(*it);
	vecKeyboard.shrink_to_fit();

	// Вектор игроков
	for(std::vector<Player*>::iterator it = vecPlayer.begin(); it != vecPlayer.end(); it++)
		delete(*it);
	vecPlayer.shrink_to_fit();
} 

void Client::draw(sf::RenderWindow *window)
{
	switch(status_game)
	{
		// Меню
	case 0:
		vecMenu[0]->draw(window);
		break;
		// Игра
	case 1:
		for(std::vector<Map*>::iterator it = vecMap.begin(); it != vecMap.end(); it++)
			(*it)->drawMap(window);

		vecPlayer[0]->drawSpaceShip(renderWindow);

		for(std::vector<Spawn*>::iterator it = vecSpawn.begin(); it != vecSpawn.end(); it++)
		  (*it)->drawSpawn(window);

		break;
	}
	window->setView(view);
}

void Client::data()
{
	//renderWindow->setView(*view);
	vecMap.reserve(1);
	Map* map = new Map();
	vecMap.push_back(map);



	vecSpawn.reserve(0);
	status_game = 0;

	vecMouse.reserve(1);
	Mouse* m = new Mouse();
	vecMouse.push_back(m);

	vecMenu.reserve(1);
	Menu* menu = new Menu();
	vecMenu.push_back(menu);

	vecKeyboard.reserve(1);
	Keyboard* k = new Keyboard();
	vecKeyboard.push_back(k);
	
	
	vecPlayer.reserve(1);
	Player* p = new Player();
	vecPlayer.push_back(p); // Добавляем в вектор
	/*
	//p->setPosition(100, 100);            // Устанавливаем позицию x=100 y=100
	//p->setScale(2, 2);                   // Увеличиваем размеры картинки в 2 раза
	//p->data_frames(3,4);                 // информация: 3x4 кадра
	//p->setIsRotate(false);               // Картинку не вращать
	//p->setIsShiftFrame(true);            // Разрешить смену кадров
	*/
	/*
	vecMonsters.reserve(1);              //
  Monsters* monsters = new Monsters(); //
	monsters->setTarget(vecPlayer[0]);   // Связываем всех монстров с игроком
	vecMonsters.push_back(monsters);     //
	*/
}
void Client::behavior(float time)
{

	behaviorMouse(time);
	behaviorKeyboard(time);
	behaviorObjects(time);

	viewmap(time);
	changeview();
}



void Client::behaviorMouse(float time)
{
	vecMouse[0]->behavior();
	
	switch(vecMouse[0]->getEventButton(sf::Mouse::Left))
	{
	case 1: 
		vecPlayer[0]->shot(vecMouse[0]->getX(), vecMouse[0]->getY()); 
		vecMenu[0]->behavior(time, vecMouse[0]);
		break;
	}
	
	/*
	int numEvent = vecMouse[0]->getEventButton(sf::Mouse::Right);
	if(numEvent == 2) // Если состояние правой кнопки 2(отжата), то задаётся новая точка в маршруте
		vecPlayer[0]->newTarget1(vecMouse[0]->getX(), vecMouse[0]->getY());
	*/
}

void Client::behaviorKeyboard(float time)
{
	bool W = false;
	bool S = false;
	bool A = false;
	bool D = false;
	float angle = 0;
	if(vecKeyboard[0]->getEventButton(sf::Keyboard::W)==2) { W = true; }
	if(vecKeyboard[0]->getEventButton(sf::Keyboard::S)==2) { S = true; }
	if(vecKeyboard[0]->getEventButton(sf::Keyboard::A)==2) { A = true; }
	if(vecKeyboard[0]->getEventButton(sf::Keyboard::D)==2) { D = true; }
	if(W == S) { W = false; S = false; }
	if(A == D) { A = false; D = false; }
	bool WA = W && A;
	bool WD = W && D;
	bool SA = S && A;
	bool SD = S && D;
	if(WA||WD||SA||SD)
	{
		if(WD) { angle =  45; }
    if(SD) { angle = 135; }
		if(SA) { angle = 225; }
		if(WA) { angle = 315; }
		vecPlayer[0]->spaceShip_speedUp(time,  true);
		vecPlayer[0]->data_speed(400, angle);
		vecPlayer[0]->setRotation(angle);
	}
	else if(W||D||S||A)
	{
		if(W) { angle = 0; }
		if(D) { angle = 90; }
		if(S) { angle = 180; }
		if(A) { angle = 270; }
		vecPlayer[0]->spaceShip_speedUp(time,  true);
		vecPlayer[0]->setRotation(angle);
		vecPlayer[0]->data_speed(400, angle);
	} 
	else
	{
		vecPlayer[0]->spaceShip_speedUp(time,  false);
	}
	
	/*
	if(vecKeyboard[0]->getEventButton(sf::Keyboard::W)==2) { vecPlayer[0]->spaceShip_speedUp(time,  true); }
	if(vecKeyboard[0]->getEventButton(sf::Keyboard::S)==2) { vecPlayer[0]->spaceShip_speedUp(time, false); }
	if(vecKeyboard[0]->getEventButton(sf::Keyboard::A)==2) { vecPlayer[0]->spaceShip_rotate(time,  false); }
	if(vecKeyboard[0]->getEventButton(sf::Keyboard::D)==2) { vecPlayer[0]->spaceShip_rotate(time,   true); }
	*/
	if(vecKeyboard[0]->getEventButton(sf::Keyboard::Escape) == 1)
	{
		status_game = 1;
	}
	if(vecKeyboard[0]->getEventButton(sf::Keyboard::Num1)==3) 
	{
		Spawn* spawn = new Spawn();
		spawn->setXY(500, 500);         // Задаём центр спавна
		spawn->data2(1, 20, 200);       // Задаём тип, количество кораблей и радиусСпавна
		spawn->setTarget(vecPlayer[0]); // Передаём в спавн ссылку на Игрока
		vecSpawn.push_back(spawn);
	}
	if(vecKeyboard[0]->getEventButton(sf::Keyboard::Delete) == 1)
	{
		vecSpawn[0]->deleteSpawn();
	}
}

void Client::behaviorObjects(float time)
{
	switch(status_game)
	{
		// Меню
	case 0:
    if(vecMenu[0]->behavior(time, vecMouse[0]) == 1)
		{
			status_game = 1;
		}
		break;
		// Игра
	case 1:
    vecPlayer[0]->mouse_SetPosition(vecMouse[0]->getX(), vecMouse[0]->getY());
	  vecPlayer[0]->spaceShip_behavior(time);
		float x = vecPlayer[0]->getPositionX();
		float y = vecPlayer[0]->getPositionY();
		view.setCenter(x, y);
		for(std::vector<Spawn*>::iterator it = vecSpawn.begin(); it != vecSpawn.end(); it++)
			(*it)->behaviorSpawn(time);
		for(std::vector<Spawn*>::iterator it = vecSpawn.begin(); it != vecSpawn.end(); it++)
			(*it)->hitTestPoint(vecPlayer[0]->getVectorLaser());
		break;
	}
}





bool Client::setWindow(sf::RenderWindow* window)
{
	try
	{
    renderWindow = window;
		vecMouse[0]->setWindow(window);
	}
	catch(...)
	{
		return false;
	}
	return true;
}

void Client::setMouse(Mouse* mouse)
{
	vecMouse[0] = mouse;
}

void Client::setKeyboard(Keyboard* keyboard)
{
	vecKeyboard[0] = keyboard;
}

void Client::setMenu(Menu* menu)
{
	vecMenu[0] = menu;
}





void Client::newPlayer()
{
	Player* p = new Player();
	p->load("2/2.png");
	p->setScale(0.5,0.5);
	p->setPosition(100,100);
	p->addGun1("2/gun1_20x40.png", 0, 0, 0, 0);
	p->spaceShip_update();
	vecPlayer[0] = p;
}





//