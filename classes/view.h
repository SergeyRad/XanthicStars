#include "stdafx.h"
 
sf::View view;//объявили sfml объект "вид", который и является камерой

void setWindow(sf::RenderWindow* window)
{
	window->setView(view);
}

void getplayercoordinateforview(float x, float y) { //функция для считывания координат игрока
	float tempX = x; float tempY = y;//считываем коорд игрока и проверяем их, чтобы убрать края
 
	if (x < 320) tempX = 320;//убираем из вида левую сторону
	if (y < 240) tempY = 240;//верхнюю сторону
	if (y > 554) tempY = 554;//нижнюю сторону	
 
	view.setCenter(tempX, tempY); //следим за игроком, передавая его координаты. 
	
}
 
 
void viewmap(float time) { //функция для перемещения камеры по карте. принимает время sfml
	int k = 300;
 
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) 
	{
		cout << "123454321";
		view.move(k*time, 0);//скроллим карту вправо (см урок, когда мы двигали героя - всё тоже самое)
	}
 
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		view.move(0, k*time);//скроллим карту вниз (см урок, когда мы двигали героя - всё тоже самое)
	}
 
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		view.move(-k*time, 0);//скроллим карту влево (см урок, когда мы двигали героя - всё тоже самое)
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		view.move(0, -k*time);//скроллим карту вправо (см урок, когда мы двигали героя - всё тоже самое)
	}
 
}
 
void changeview(){
 
 
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::I)) {
		view.zoom(1.0100f); //масштабируем, уменьшение
		//view.zoom(1.0006f); //тоже самое помедленнее соответственно
	}
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::K)) {
		view.zoom(0.9900f); //масштабируем, уменьшение
		//view.zoom(1.0006f); //тоже самое помедленнее соответственно
	}
	/*
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::O)) {
		//view.setRotation(90);//сразу же задает поворот камере
		view.rotate(1);//постепенно поворачивает камеру (отрицательное значение - в обратную сторону)
	}
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::L)) {
		//view.setRotation(90);//сразу же задает поворот камере
		view.rotate(-1);//постепенно поворачивает камеру (отрицательное значение - в обратную сторону)
	}

  
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)) 
	{
		view.setSize(1200, 700);//устанавливает размер камеры (наш исходный)
	}
   */

	/*
	if (Keyboard::isKeyPressed(Keyboard::E)) {
		view.setSize(540, 380);//например другой размер
	}
  */
 
	/*
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::U)) {
		view.setViewport(sf::FloatRect(0, 0, 0.5f, 1));//таким образом делается раздельный экран для игры на двоих. нужно только создать ещё один объект View и привязывать к нему координаты игрока 2.
	}
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::J)) {
		view.setViewport(sf::FloatRect(0, 0, 1, 1));//таким образом делается раздельный экран для игры на двоих. нужно только создать ещё один объект View и привязывать к нему координаты игрока 2.
	}
	*/
}