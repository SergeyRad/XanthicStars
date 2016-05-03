#pragma once


#include "Image.h"
#include "DesignWindow.h"
#include "Mouse.h"
#include "Button.h"
#include "WinItem.h"

struct winSave
{
	int x; // позиция по Х
	int y; // позиция по У
	int width; // ширина
	int height; // длинна
	winSave() : x(0), y(0), width(0), height(0) {}
};

struct winSprite
{
	sf::Image image0;
	sf::Image image;
	sf::Texture texture;
	sf::Sprite sprite;
	int w;
	int h;
	int wc;
	int hc;
	int dx;
	int dy;
	winSprite() : w(0), h(0), wc(0), hc(0), dx(0), dy(0) {}
	bool setImage(sf::Image img)
	{
    image0 = img;

		image = img;
		wc = w = image.getSize().x;
		hc = h = image.getSize().y;
		texture.loadFromImage(image);
		//texture.setSmooth(true); // сглаживание
		sprite.setTexture(texture);
		return true;
	}
	void setImage1(sf::Image img)
	{
		image = img;
		wc = w = image.getSize().x;
		hc = h = image.getSize().y;

		texture.loadFromImage(img);
		sprite.setTexture(texture);
		sprite.setTextureRect(sf::IntRect(0,0, wc, hc));
	}
	void setDXY(int dx, int dy)
	{
		this->dx = dx;
		this->dy = dy;
	}
	void move(int dx, int dy)
	{
		sprite.move(dx, dy);
	}
	void setPosition(int x, int y)
	{
		sprite.setPosition(x + dx, y + dy);
	}
	void setScale(int factorX, int factorY)
	{
		bool bx = factorX > 1;
		bool by = factorY > 1;
	  if((bx && !by) ||(!bx && by))
		{ // Если увеличение только в 1 сторону
		  sprite.setScale(factorX, factorY);
		  wc = w*factorX;
		  hc = h*factorY;
		} 
		else if(bx && by)
		{ // Если изменение размеров в обе стороны
			sf::Image img;
			img.create(w, factorY, sf::Color(255,0,0,255));
			img.copy(image, 0, 0, sf::IntRect(0,0,wc,hc)); // копируем в неё уже имеющуюся image
			if(factorY > hc)
			{
				for(int i = hc; i<factorY; i+=h)
					img.copy(image0, 0, i, sf::IntRect(0,0,w,h));
			}
			setImage1(img);
			setScale(factorX, 1);
		}
	}
	void draw(sf::RenderWindow* window)
	{
		window->draw(sprite);
	}
};

class Window
{
protected:
	std::vector<DesignWindow*> vecDesign; // Вектор для 1 дизайна
	std::vector<winSave*> vecSave; // 
	std::vector<winSprite*> vecWinSprite; // Вектор из 9 спрайтов
	std::vector<Button*> vecButton; // Вектор кнопок
	std::vector<WinItem*> vecWinItem;
	int numDesCur; // номер дизайна текущего в vecDesign

	void setDesign2();

	int width_min;
	int width_max;

	int height_min;
	int height_max;
	int height_x;

  bool isMove;       // Можно перемещать окно?
	bool isConsiderBorder; // Учитывать границы?
	bool isChangeSize; // Можно изменять размеры?
	//bool isVisible;
public:
	bool isVisible;
	bool isClose;
	int x;
	int y;
	int height_current;
	int width_current;
	std::vector<int>* vec; // ссылка на вектор int

	Window(int width, int height);
	Window(int width, int height, bool isMove, bool isConsiderBorder, bool isChangeSize);
	~Window(void);

	int checkDesignName(sf::String filename);
	bool addDesign(sf::String filename);
	//====
	void setVector(std::vector<int>*);
	//====
	void setSize(int width, int height);
	// Установить дизайн окна
	void setDesign(sf::String filename); 

	void data();

	void move(int dx, int dy);

	void setPosition(int x, int y);
	int getPositionX();
	int getPositionY();
	
	bool check1(int* x, int* y); // Входит ли в окно
	bool check2(int* x, int* y); // Входит ли в верхнюю часть, за которую перетаскивают
	int  check3(int* x, int* y); // Входит ли курсор в края для растягивания
	int  checkButton(int* x, int*y); // Входит ли курсор в кнопки (Возвращает номер кнопки)

	void changeSize(Mouse*, int num);
	void changePosition(Mouse*);

	void save();
	void draw(sf::RenderWindow*);

	// ===============================
  bool addButtonClose(sf::String filename, int posX, int posY, int orient, int numCellMax);
	bool addButton(sf::String filename, int posX, int posY, int orient, int numCellMax);
	void buttonSetCell(int numButton, int numCell);
	void buttonSetCellAll(int numCell);
	void addWinItem(sf::String filename);
	void addWinItem(WinItem* item);
};

