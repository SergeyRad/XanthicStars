#include "stdafx.h"

#include "mouse.h"
#include "keyboard.h"
#include "Client.h"
#include "Image.h"

#include "menu.h"
#include "tilemovi.h"
#include "BlastEffect.h"

using namespace std;

int main()
{
	////////////////////////////////////////////////
	// Фоновая музыка
	////////////////////////////////////////////////
	sf::SoundBuffer buffer; 
  buffer.loadFromFile("music/sound1.wav");
  sf::Sound sound1; 
	sound1.setBuffer(buffer);
	sound1.play();
	sound1.setLoop(true);
	////////////////////////////////////////////////


	Menu* menu = new Menu();
	menu->setFond("Menu/fon.png");
	

	sf::RenderWindow window(sf::VideoMode(1024, 768), "kychka-pc.ru/legozaur");
	
	
	////////////////////////////////////////////////
	// Создаём мышь и клаву
	////////////////////////////////////////////////
	Mouse* mouse = new Mouse();
	mouse->setWindow(&window);
	mouse->setDesign("images/Design/Cursor/2/3.png");
	mouse->setCursor(0);
	mouse->setMouseCursorVisible(false);
	////////////////////////////////////////////////
  Keyboard* kb = new Keyboard();
	////////////////////////////////////////////////


	////////////////////////////////////////////////
	// Создаём клиент игры и добавляем в неё клавиатуру, мышь и окно
	////////////////////////////////////////////////
	Client* client = new Client();
	client->setKeyboard(kb);
	client->setMouse(mouse);
	client->setWindow(&window);
	client->newPlayer();
	client->setMenu(menu);
	////////////////////////////////////////////////


	float time = 0;
	sf::Clock clock;

  while (window.isOpen())
  {
		time = clock.getElapsedTime().asSeconds();
		clock.restart();

	  sf::Event event;
	  while (window.pollEvent(event))
	  {
	    if (event.type == sf::Event::Closed) 
				window.close();
	  }

		//window.clear(sf::Color(255, 255, 255)); // Очистка экрана белым
		window.clear(sf::Color(0, 0, 0)); // Очистка экрана чёрным
		
		// ==== TODO ====

		client->behavior(time);
		client->draw(&window);
 
		// ==== TODO ====

		mouse->draw();
		window.display();
  }


	delete(mouse);
	delete(kb);
	return 0;
}