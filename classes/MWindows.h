//MWindows.h
#ifndef DSL_MWindows_H
#define DSL_MWindows_H

#include "Window.h"
#include "Mouse.h"

class MWindows
{
protected:
	bool flag0; // true - было наведение на любое окно
	bool flag1; // true - если нажатие было на любом окне
	bool flag2; // true - если нажатие было на области перемещения
	bool flag3; // true - если нажатие было на растягивающей области
	bool flagBut;
	int numRote; // Необходима в переходе с 1 на 2 и на протяжении 2 (case)
	int iNum;
	int iNum2; 
	std::vector<Window*> vecWindow;
	std::vector<int> vecInt;
	void data(void);
	bool behaviorCase0(Mouse* mouse);
	bool behaviorCase1(Mouse* mouse);
	bool behaviorCase2(Mouse* mouse);
	bool behaviorCase3(Mouse* mouse);
public:
	MWindows(void);
	~MWindows(void);

	// Добавлякт окно в обработчик окон
	void add(Window* window);

	// Обработчик событий (поведение окон)
	bool behavior(Mouse* mouse);

	// Сортировка окон
	void sort1(int j);

	// Отрисовка во входящем окне
	void draw(sf::RenderWindow* window);
};

#endif DSL_MWindows_H
