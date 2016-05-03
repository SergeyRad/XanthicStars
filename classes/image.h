//Image.h
#include "stdafx.h"

// Created by Kildushov Oleg
// Создатель - Кильдюшов Олег
// vk.com/legozaur
// kychka-pc.ru - nikname: legozaur 

#ifndef DSL_IMAGE_H
#define DSL_IMAGE_H

class Image
{
protected:
  float alpha;         // прозрачность

  sf::String file;     // Файл с расширением
  sf::Image	image;     // SFML изображение
  sf::Texture texture; // SFML текстура
  sf::Sprite sprite;   // SFML спрайт
  
  void update_alpha(); 
public:
  Image();
  Image(sf::String filename);

  void data();

  void load(sf::String filename);

  void draw(sf::RenderWindow *window);

	////////////////////////////////////////////
	// КООРДИНАТЫ
	////////////////////////////////////////////
  float getPositionX(void);
  float getPositionY(void);

  void setPositionX(float x);
  void setPositionY(float y);
	void setPosition(float x, float y);

  void move(float dx, float dy);
	void move2(float distance, float angle);
	////////////////////////////////////////////

	////////////////////////////////////////////
	// ПРОЗРАЧНОСТЬ
	////////////////////////////////////////////
  void setAlpha(float value_alpha);
  void setDAlpha(float value_alpha);
  float getAlpha();
	////////////////////////////////////////////

	////////////////////////////////////////////
	// ВРАЩЕНИЕ: УГОЛ ПОВОРОТА
	////////////////////////////////////////////
  void setRotation(float angle);
  void rotate(float angle);
  float getRotation();
	////////////////////////////////////////////

	////////////////////////////////////////////
	// УВЕЛИЧЕНИЕ / УМЕНЬШЕНИЕ
	////////////////////////////////////////////
  void setScale(float factorX, float factorY);
	void scale(float factor);
	void scale(float factorX, float factorY);

  float getScale();
  float getScaleX();
  float getScaleY();
  /////////////////////////////////////////////

	/////////////////////////////////////////////
  // РАЗМЕРЫ
	/////////////////////////////////////////////
  float getSizeX(void);
  float getSizeY(void);

  float getSizeXcurr();
  float getSizeYcurr();
	/////////////////////////////////////////////
  
	/////////////////////////////////////////////
	// ПРОЧИЕ
	/////////////////////////////////////////////
	void setOriginNum(int number);
	void coutPosition(void);
  void flipHorizontally();
  void flipVertically();
  sf::Sprite getSprite();
	sf::Image getImage();
	void setImage(sf::Image image);
	/////////////////////////////////////////////
};

#endif DSL_IMAGE_H

//
