#include "stdafx.h"
#include "Window.h"


Window::Window(int width, int height)
{
	data();

	width_current = width;
	height_current = height;
}
Window::Window(int width, int height, bool isMove, bool isConsiderBorder, bool isChangeSize)
{
	data();

	width_current = width;
	height_current = height;
	this->isMove = isMove;
	this->isConsiderBorder = isConsiderBorder;
	this->isChangeSize = isChangeSize;
}
Window::~Window(void)
{
	//
}
void Window::data(void)
{
	numDesCur = -1; // пока дизайна нет'
	x = 0;
	y = 0;

	width_min = 100;
	height_min = 100;
	width_max = 0;
	height_max = 0;
	height_x = 0;

	isMove = true;
	isConsiderBorder = false;
	isChangeSize = false;
	isVisible = true;
	isClose = false;
	// === vector ===
	vecDesign.reserve(1);

	vecWinSprite.reserve(9);
	for(int i=0; i<9; i++)
		vecWinSprite.push_back(new winSprite());

	vecSave.reserve(1);
	winSave* win = new winSave();
	vecSave.push_back(win);

	vecButton.reserve(1);
	Button* b = new Button();
	vecButton.push_back(b);
}


//////////////////////////////////////////////
// Управление Дизайнами
//////////////////////////////////////////////
void Window::setDesign(sf::String filename)
{
	int num = checkDesignName(filename); // получаем номер дизайна в векторе
	if(num >= 0) 
	{// если дизайн есть
		if(num != numDesCur)// если дизайн не используеться
			numDesCur = num; // устанавливаем дизайн
	}
	else 
	{
		if(addDesign(filename))
		  numDesCur = vecDesign.size()-1; // Текущий дизайн - последний
	}
	// !!!!!!!!!
	setDesign2();
	//update();
	// !!!!!!!!!
	setPosition(x, y);
}
void Window::setDesign2()
{
	std::vector<int> w; // вектор ширин
	std::vector<int> h; // вектор высот

	for(int i=0; i<9; i++)
	{
		w.push_back(0);
		h.push_back(0);
	}
	// 1. Загружаем все картинки в winSprite
	for(int i=0; i<9; i++)
	{
		sf::Image img = vecDesign[numDesCur]->getImage(i);
		vecWinSprite[i]->setImage(img);
	}

  for(int i=0; i<9; i++)
	{
		int W = vecWinSprite[i]->wc; w[i]=W;
		int H = vecWinSprite[i]->hc; h[i]=H;
	}		

	// 2. Задаём размеры спрайтам
	vecWinSprite[4]->setScale(width_current-w[0]-w[1], 1);
	vecWinSprite[5]->setScale(1, height_current-h[0]-h[2]);
	vecWinSprite[6]->setScale(1, height_current-h[1]-h[3]);
	vecWinSprite[7]->setScale(width_current-w[2]-w[3], 1);
	vecWinSprite[8]->setScale(width_current-w[5]-w[6], height_current-h[4]-h[7]);

	for(int i=0; i<9; i++)
	{
		int W = vecWinSprite[i]->wc; w[i]=W;
		int H = vecWinSprite[i]->hc; h[i]=H;
	}
	// 3. Задаём смещение спрайтам
	vecWinSprite[0]->setDXY(0,                  0                  );
	vecWinSprite[1]->setDXY(width_current-w[1], 0                  );
	vecWinSprite[2]->setDXY(0,                  height_current-h[2]);
	vecWinSprite[3]->setDXY(width_current-w[3], height_current-h[3]);
	vecWinSprite[4]->setDXY(w[0],               0                  );
	vecWinSprite[5]->setDXY(0,                  h[0]               );
	vecWinSprite[6]->setDXY(width_current-w[6], h[1]               );
	vecWinSprite[7]->setDXY(w[2],               height_current-h[7]);
	vecWinSprite[8]->setDXY(w[0],               h[0]               );

	height_x = h[4];
}
// Добавляет дизайн в vecDesign
bool Window::addDesign(sf::String filename)
{
	DesignWindow* dw = new DesignWindow();
	if(dw->load(filename))
	{
	  vecDesign.push_back(dw); // добавляем
		return true;
	}
	return false;
}

//////////////////////////////////////
// Функционал для управления окном
///////////////////////////////////////
void Window::setSize(int width, int height)
{
	if( width >=  width_min)  width_current =  width; else  width_current =  width_min;
	if(height >= height_min) height_current = height; else height_current = height_min;
	setDesign2();
	//================================
	for(std::vector<Button*>::iterator it = vecButton.begin(); it != vecButton.end(); it++)
		(*it)->update();
	//================================
	for(std::vector<WinItem*>::iterator it = vecWinItem.begin(); it != vecWinItem.end(); it++)
		(*it)->update();
}
void Window::move(int dx, int dy)
{
	x += dx; 
	y += dy;
	if(!isConsiderBorder)
	{
		if(x < 0) x = 0;
		if(y < 0) y = 0;
	}
	for(std::vector<winSprite*>::iterator it = vecWinSprite.begin(); it != vecWinSprite.end(); it++)
		(*it)->move(dx, dy);
	// =============================
	for(std::vector<Button*>::iterator it = vecButton.begin(); it != vecButton.end(); it++)
		(*it)->update();
	// =============================
	for(std::vector<WinItem*>::iterator it = vecWinItem.begin(); it != vecWinItem.end(); it++)
		(*it)->update();
}
void Window::setPosition(int x, int y)
{
	if(!isConsiderBorder)
	{
		if(x < 0) x = 0;
		if(y < 0) y = 0;
	}
	this->x = x;
	this->y = y;
	for(std::vector<winSprite*>::iterator it = vecWinSprite.begin(); it != vecWinSprite.end(); it++)
		(*it)->setPosition(x, y);
	// =============================
	for(std::vector<Button*>::iterator it = vecButton.begin(); it != vecButton.end(); it++)
		(*it)->update();
	// =============================
	for(std::vector<WinItem*>::iterator it = vecWinItem.begin(); it != vecWinItem.end(); it++)
		(*it)->update();
}
void Window::changeSize(Mouse* mouse, int num)
{
	// Если можно изменять размеры окна
	if(isChangeSize && 0 <= num && num <= 7)
	{
		// поздаём копию вектора по ссылке
		std::vector<int> vecInt = *vec;

		int x1 = vecInt[0]; // коорд окна в момент нажатия
		int y1 = vecInt[1]; //  
		int x2 = vecInt[2]; // коорд мыши в момент нажатия
		int y2 = vecInt[3]; // 

	  // Ищем перемещение мыши
		int dx = x2 - mouse->getX();
		int dy = y2 - mouse->getY();
	
		// в какую сторону изменяем 
		switch(num)
		{
		case 0: setSize(vecSave[0]->width +dx, vecSave[0]->height +dy); setPosition(x1 - dx, y1 - dy); break;
		case 1: setSize(vecSave[0]->width -dx, vecSave[0]->height +dy); setPosition(x1, y1 - dy); break;
		case 2: setSize(vecSave[0]->width +dx, vecSave[0]->height -dy); setPosition(x1 - dx, y1); break;
		case 3: setSize(vecSave[0]->width -dx, vecSave[0]->height -dy); setPosition(x1, y1); break;

		case 4: setSize(vecSave[0]->width, vecSave[0]->height +dy); setPosition(x1, y1 - dy); break;
		case 5: setSize(vecSave[0]->width +dx, vecSave[0]->height); setPosition(x1 - dx, y1); break;
		case 6: setSize(vecSave[0]->width -dx, vecSave[0]->height); setPosition(x1, y1); break;
		case 7: setSize(vecSave[0]->width, vecSave[0]->height -dy); setPosition(x1, y1); break;
		//Прикольный баг с окном) сами знаете как включить
		//case 6: setSize(vecSave[0]->width +dx, vecSave[0]->height); setPosition(x1, y1); break;
		//case 7: setSize(vecSave[0]->width, vecSave[0]->height +dy); setPosition(x1, y1); break;
		}
		//setSize(vecSave[0]->width +dx, vecSave[0]->height +dy);
		//setPosition(x1 - dx, y1 - dy);
		//////setSize(vecSave[0]->width +dx, vecSave[0]->height +dy);
		// Если поставить setPosition перед setSize, то будет интересный баг :))
	}
}
void Window::changePosition(Mouse* mouse)
{
	std::vector<int> vecInt = *vec;

	int dx = mouse->getX() - vecInt[2];
	int dy = mouse->getY() - vecInt[3];
	// Ставим окно в координаты с учётом сдвига
	setPosition(vecInt[0] + dx, vecInt[1] + dy);
}

/////////////////////////////////////////
// Получение информации об окне
///////////////////////////////////////
int Window::getPositionX()
{
	return x;
}
int Window::getPositionY()
{
	return y;
}

/////////////////////////////////////////
// Другие методы
///////////////////////////////////////
void Window::draw(sf::RenderWindow *window)
{
	if(!isClose)
	{
		if(isVisible == true)
		{
			for(int i = vecWinSprite.size(); i > 0; i--)
				vecWinSprite[i-1]->draw(window);
		}
		for(int i = vecButton.size(); i > 0; i--)
		{
			vecButton[i-1]->draw(window);
		}
		//================================
		for(int i = vecWinItem.size(); i > 0; i--)
			vecWinItem[i-1]->draw(window);
	}
}
void Window::save()
{
	// Предполагается что предварительно уже 
	// использована функция setVector(...);
	std::vector<int> vector1 = *vec;
	vecSave[0]->x = vector1[0];
	vecSave[0]->y = vector1[1];
	vecSave[0]->width = width_current;
	vecSave[0]->height = height_current;
}
void Window::setVector(std::vector<int>* vector_)
{
	vec = vector_;
}

/////////////////////////////////////////
// Различные проверки
//////////////////////////////////////////
bool Window::check1(int* x, int* y)
{
	if(!isClose)
	{
		if((this->x <= *x) && (*x <= this->x +  width_current)
		&& (this->y <= *y) && (*y <= this->y + height_current)) 
		  return true;
	}
	return false;
}
bool Window::check2(int* x, int* y)
{
	if(!isClose)
	{
		if((this->x +1 <= *x) && (*x <= this->x + width_current -1) && 
			 (this->y +1 <= *y) && (*y <= this->y + height_x -1)) 
		  return true;
	}
	return false;
}
int Window::check3(int* x, int* y)
{
	if(!isClose && isChangeSize)
	{
		int k = 5;
	
		bool b4 = (this->y <= *y) && (*y <= this->y + k); // Up
		bool b5 = (this->x <= *x) && (*x <= this->x + k); // Left
		bool b6 = (this->x +width_current -k <= *x) && (*x <= this->x + width_current);  // right
		bool b7 = (this->y + height_current -k <= *y) && (*y < this->y + height_current); // down

		if(b4 && b5) return 0;
		if(b4 && b6) return 1;
		if(b7 && b5) return 2;
		if(b7 && b6) return 3;
		if(b4)       return 4;
		if(b5)       return 5;
		if(b6)       return 6;
		if(b7)       return 7;
	}
	return -1;
}


// Ищет в vecDesign дизайн с именем filename. Возвращает номер в векторе если нашёл, и -1 если не нашёл
int Window::checkDesignName(sf::String filename)
{
	int num = -1; // номер дизайна в векторе
	int imax = vecDesign.size(); // Количество дизайнов в векторе
	// Проходим по дизайнам
	for(int i=0; i<imax; i++)
	{
		// Если имена дизайнов совпадают
		if(vecDesign[i]->getFilename() == filename)
		{
			num = i; // записываем номер дизайна в векторе
			break;
		}
	}
	return num;
}



int Window::checkButton(int* x, int*y)
{
	for(std::vector<Button*>::iterator it = vecButton.begin(); it != vecButton.end(); it++)
	{
		if((*it)->check1(x, y))
		{
			 return (it-vecButton.begin());
			 break;
		}
	}
	return -1;
}

bool Window::addButtonClose(sf::String filename, int posX, int posY, int orient, int max)
{
	Button* b = new Button();
	if(b->load(filename))
	{
		// Привязка справа на 5 пикселей от края
		b->set("d", b->getW() + 8);
		b->set("w", 1);
		b->isHorizontal = false;
		b->setNumTileMax(max);
		b->setTile(0);
		// передаём в Button ссылки на координаты окон и текущие размеры, чтобы она всегда их знала
		b->setWindow(&x, &y, &width_current, &height_current);
		b->update();
		b->setVisible(true);
		vecButton[0] = b;
		return true;
	}
	return false;
}

bool Window::addButton(sf::String filename, int posX, int posY, int orient, int max)
{

	Button* b = new Button();
	if(b->load(filename))
	{
		// Привязка слева и сверху на posX и posY
		b->set("a", posX);
		b->set("w", posY);
		b->isHorizontal = false;
		b->setNumTileMax(max);
		b->setTile(0);
		// передаём в Button ссылки на координаты окон и текущие размеры, чтобы она всегда их знала
		b->setWindow(&x, &y, &width_current, &height_current);
		b->update();
		b->setVisible(true);
		vecButton.push_back(b);
		return true;
	}
	return false;
}

void Window::buttonSetCell(int numButton, int numCell)
{
	vecButton[numButton]->setTile(numCell);
}
void Window::buttonSetCellAll(int numCell)
{
	for(std::vector<Button*>::iterator it = vecButton.begin(); it != vecButton.end(); it++)
	  (*it)->setTile(numCell);
}
void Window::addWinItem(sf::String filename)
{
	WinItem* item = new WinItem();
	if(item->load(filename))
	{
		item->set("d", item->getW() + 8);
		item->set("w", 1);
		item->setWindow(&x, &y, &width_current, &height_current);
		vecWinItem.push_back(item);
	}
}
void Window::addWinItem(WinItem* item)
{
	vecWinItem.push_back(item);
}