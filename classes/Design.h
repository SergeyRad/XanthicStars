//Desigh.h
//v1.0 05.04.2016
//by DSL.legozaur
#ifndef DSL_DESIGN_H
#define DSL_DESIGN_H

#include "stdafx.h"

class Design
{
protected:
	sf::String filename; // Имя файла дизайна
	sf::Image image;     // картинка целого дизайна
	std::vector<sf::Image> vecImage; // Обрезанные картинки

	// Набор функций, которые нужны для getImage(int numCell, int factorX, int factorY)
	//sf::Image getNewImage1(int numCell, int factorX, int factorY);
	//sf::Image getNewImage2(int numCell, int factorX, int factorY);
	//sf::Image getNewImageX(int numCell, int factor);
	//sf::Image getNewImageY(int numCell, int factor);
public:
	// Конструктор по умолчанию
	Design(void);
	// Загрузка дизайна
	bool loadImage(sf::String filename);

	// Деструктор
	~Design(void);
	// Основная функция преобразующая дизайн в набор картинок
  bool designToImage(sf::Image* image1, sf::Image* image2, int numImageW, int numImageH, int sideImage);
	// Возвращает картинку дизайна
	sf::Image getImage();
	// Возвращает обрезанную картинку дизайна под номером
	sf::Image getImage(int numCell);
	// Возвразает обрезанную картинку дизайна под номером увеличенную по Х в factorX раз, по Y в factorY раз
  //sf::Image getImage(int numCell, int factorX, int factorY);
	//Возвращает имя дизайна
	sf::String getFilename();
};

#endif DSL_DESIGN_H
