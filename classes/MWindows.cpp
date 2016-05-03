#include "stdafx.h"
#include "MWindows.h"

// Конструктор
MWindows::MWindows(void)
{
	data();
}

// Деструктор
MWindows::~MWindows(void)
{
	// Освобождаем память
	vecWindow.~vector();
}

// Задаёт начальную информацию
void MWindows::data(void)
{
	flag0 = false;
	flag1 = false;
	flag2 = false;
	flag3 = false;
	flagBut = false;
	vecWindow.reserve(1);
	numRote = 0;
	iNum = -1;
	vecInt.reserve(4);
	for(int i=0; i<4; i++)
	  vecInt.push_back(0);
}

// Добавляет окно в обработчик окон
void MWindows::add(Window* window)
{
	window->setVector(&vecInt);
	vecWindow.push_back(window);
}

// Обработчик событий (поведение окон)
bool MWindows::behavior(Mouse* mouse)
{
	// Обработчик ЛКМ
	switch(mouse->getEventButton(sf::Mouse::Left))
	{
	case 0: behaviorCase0(mouse); break; // ЛКМ не нажата
	case 1: behaviorCase1(mouse); break; // ЛКМ нажимается
	case 2: 
		if(!behaviorCase2(mouse)); 
		return false;
		break; // ЛКМ уже нажата 
	case 3: behaviorCase3(mouse); break; // ЛКМ отпускается
	}

	return true;
}

// Сортировка окон
void MWindows::sort1(int num)
{
	Window* window = vecWindow[num];

	for(int i=num; i>0; i--)
	{
		vecWindow[i] = vecWindow[i-1];
	}
	vecWindow[0] = window;
}

// Отрисовка во входящем окне
void MWindows::draw(sf::RenderWindow* window)
{
	int imax = vecWindow.size()-1;
	for(int i=imax; i>=0; i--)
		vecWindow[i]->draw(window);
}


bool MWindows::behaviorCase0(Mouse* mouse)
{
	int x = mouse->getX();
	int y = mouse->getY();
	// Если до этого было наведение на окно
	if(flag0 == true)
	{
		// А теперь курсор не в окне
		if(vecWindow[iNum]->check1(&x,&y) == false)
		{
			// меняем состояние кнопки на 0 (фича)
			// без неё иногда кнопка не меняться с 1 на 0
			vecWindow[iNum]->buttonSetCell(0, 0);
			flag0 = false;
		}
	}

	// Ищем первое окно на которое наведена мышка и помечаем его iNum
	for(std::vector<Window*>::iterator it = vecWindow.begin(); it != vecWindow.end(); it++)
  {
    if((*it)->check1(&x, &y))
    {
	    iNum = it - vecWindow.begin(); // В iNum зписываеться номер окна которое выше
			flag0 = true;
	    break; 
		}
	}
    
	// Если окно есть
	if(iNum != -1)
  {
		int num = vecWindow[iNum]->checkButton(&x, &y);
		if(num != iNum2)
		{
			vecWindow[iNum]->buttonSetCellAll(0);
			iNum2 = num;

			if(iNum2 != -1)
				vecWindow[iNum]->buttonSetCell(iNum2, 1); //vecWindow[iNum]->buttonSetCell(x, 1);
		}
		// записываем в numRote направление растяжения
    numRote = vecWindow[iNum]->check3(&x, &y);
		// если растяжение есть
		if(numRote != -1)
		{
			// меняем курсор
			if(numRote == 0 || numRote == 3) mouse->setCursor(4);
			if(numRote == 1 || numRote == 2) mouse->setCursor(5);
			if(numRote == 4 || numRote == 7) mouse->setCursor(2);
			if(numRote == 5 || numRote == 6) mouse->setCursor(3);
		} 
		// иначе если перемещение
	  else if(vecWindow[iNum]->check2(&x, &y)) 
	  {
			// меняем курсор
	    mouse->setCursor(1);
	  } else {
			// иначе меняем курсор на стандарт
	    mouse->setCursor(0);
	  }
  } else {
		// иначе меняем курсор на стандарт
	  mouse->setCursor(0);
  }
	return true;
}
bool MWindows::behaviorCase1(Mouse* mouse)
{
	int x = mouse->getX();
	int y = mouse->getY();
	// Проходим по всем окнам, начиная с первого
	for(std::vector<Window*>::iterator it = vecWindow.begin(); it != vecWindow.end(); it++)
	{
		// Проверка: было ли нажатие мыши в окне
		if((*it)->check1(&x, &y) == true)
		{
			// Если нажатие было (но хз зачем)
			flag1 = true;

			// Запоминаем координаты окна и мыши
			vecInt[0] = (*it)->getPositionX();
			vecInt[1] = (*it)->getPositionY();
			vecInt[2] = x;
			vecInt[3] = y;
			// Сортируем окна вынося на первый план то, которое было выделено
			sort1(it - vecWindow.begin());

			vecWindow[0]->save();

			iNum2 = vecWindow[0]->checkButton(&x, &y);
			if(iNum2 != -1)
				flagBut = true;
			
			
			// Если клик мыши был по растягиваемой зоне
			numRote = vecWindow[0]->check3(&x, &y);
			if(numRote != -1)
				flag3 = true;

			// Если клик мыши был по перетаскиваемой зоне
			if(vecWindow[0]->check2(&x, &y))
				flag2 = true;

			break; // предварительно выходим из вектора окно, т.к. мы нашли окно на которое кликнули.
		}
	}
	return true;

}
bool MWindows::behaviorCase2(Mouse* mouse)
{
	int x = mouse->getX();
	int y = mouse->getY();
	if(flagBut)
	{
		int num = vecWindow[0]->checkButton(&x, &y);
		if(num == 0)
			return false;
		if(num == -1)
		{
			vecWindow[0]->buttonSetCell(0, 2);
		}
		else
		{
			vecWindow[0]->buttonSetCell(iNum2, 2);
		}
	}
	else if(flag3) 
		vecWindow[0]->changeSize(mouse, numRote);
	else if(flag2)
		vecWindow[0]->changePosition(mouse);
	return true;
}
bool MWindows::behaviorCase3(Mouse* mouse)
{
	int x = mouse->getX();
	int y = mouse->getY();
	if(flagBut)
	{
		if(vecWindow[0]->checkButton(&x, &y) != -1)
		{
			vecWindow[0]->isVisible = false;
		}
	}
	flag1 = false;
	flag2 = false;
	flag3 = false;
	flagBut = false;
	numRote = 0;
	return true;
}