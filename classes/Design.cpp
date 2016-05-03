//Desigh.cpp
//v1.0 05.04.2016
//by DSL.legozaur
#include "Design.h"

// Конструктор по умолчанию
Design::Design(void)
{
	vecImage.reserve(0);
}

bool Design::loadImage(sf::String filename)
{
	vecImage.reserve(0);
	this->filename = filename;

	if(image.loadFromFile(filename))
		return true;
	return false;
}

Design::~Design(void)
{
	//
}

sf::Image Design::getImage()
{
	return image;
}
sf::Image Design::getImage(int numCell)
{
	int numberImage = vecImage.size();
	if(numCell < numberImage)
	  return vecImage[numCell];
}
sf::String Design::getFilename()
{
	return filename;
}

// designToImage - режет дизайн, на картинки
// *image1 - ссылка на Целый дизайн
// *image2 - ссылка на картинку, в которую будет вставлена часть дизайна
// numCellWidth  - положение картинки в дизайне по ширине [начиная с 0]
// numCellHeight -                              по высоте [начиная с 0]
// sideCell - размер ячейки (обычно 32)
bool Design::designToImage(sf::Image *image1, sf::Image *image2, int numCellWidth, int numCellHeight, int sideCell)
{
	// Если в ячейке будет картинка, то W и H её ширина и высота соответственно
	int W = -1; // ширина
	int H = -1; // высота

	int imin = numCellWidth * sideCell;  
	int imax = imin + sideCell;         

	int jmin = numCellHeight * sideCell; 
	int jmax = jmin + sideCell;          
	
	for(int j = jmin; j < jmax; j++)
	{
		for(int i = imin; i < imax; i++)
		{
			if(image1->getPixel(i, j) != sf::Color(255,255,255,0))
			{// Если пиксель не пустой
				if( W < i-imin) W++;
				if( H < j-jmin) H++;
			}
		}
	}
	
	if(W != -1 && H != -1)
	{
		W++; H++; // Фича 31.03.2016 8:40 МСК // нужная поправка на 1 пиксель
		image2->create(W, H, sf::Color(255, 255, 255, 255));
		image2->copy(*image1, 0, 0, sf::IntRect(imin,jmin, imin+W,jmin+H));
		return true;
	}
	return false;
}

/*
// Возвращает картинку под номером numCell увеличенную по ширине в factorX раз и по высоте в factorY раз
sf::Image Design::getNewImage1(int numCell, int factorX, int factorY)
{
	sf::Image img0 = getNewImageX(numCell, factorX); // Растягиваем картинку до нужной нам ширины (factorX)
	int h = img0.getSize().y; // высота полосы (необходимо для расчётов)

	sf::Image img; // Создаём картинку которую будем возвращать

	img.create(factorX, factorY, sf::Color(0,0,0,0)); // Задаём её размеры
	int a = int(float(factorY)/h); // а - это количество полос в высоту
	if(a*h <= factorY) // Если не всё пространство занято полосами
		a++; // добавляем 1 полосу, она всё равно обрежется

	for(int i=0; i<a; i++) // делаем "а" раз нижеуказанное 
		img.copy(img0, 0, i*h, sf::IntRect(0,0,factorX,h)); // вставляем (каждая следующая ниже на величину h)
	return img; // возвращаем картинку
}

// Возвращает картинку под номером numCell увеличенную по ширине в factorX раз и по высоте в factorY раз
sf::Image Design::getNewImage2(int numCell, int factorX, int factorY)
{
	sf::Image img0 = getNewImageY(numCell, factorY); // Растягиваем картинку до нужной нам ширины (factorX)
	int w = img0.getSize().x; // ширина полосы (необходимо для расчётов)
	int h = img0.getSize().y; // высота полосы (необходимо для расчётов)
	sf::Image img; // Создаём картинку которую будем возвращать
	img.create(factorX, factorY, sf::Color(0,0,0,0)); // Задаём её размеры

	for(int i=0; i<factorX; i++) // делаем "а" раз нижеуказанное 
		img.copy(img0, i*w, 0, sf::IntRect(0,0,w,h)); // вставляем (каждая следующая ниже на величину h)
	return img; // возвращаем картинку
}

// Возвращает картинку под номером numCell увеличенную по ширине в factor раз
sf::Image Design::getNewImageX(int numCell, int factor)
{
	int w = vecImage[numCell].getSize().x; // ширина исходной картинки
	int h = vecImage[numCell].getSize().y; // высота исходной картинки

	sf::Image img; // создаём картинку, которую будем возвращать

	img.create(w*factor, h, sf::Color(0,0,0,0)); // Задаём ей форму и цвет
	for(int i=0; i<factor; i++) // Делаем нижеуказанное factor раз
		img.copy(vecImage[numCell], i*w, 0, sf::IntRect(0,0,w,h)); // вставляем картинку на 1 пиксель правее
	return img; // возвращаем картинку
}

// Возвращает картинку под номером numCell увеличенную по высоте в factor раз
sf::Image Design::getNewImageY(int numCell, int factor)
{
	int w = vecImage[numCell].getSize().x; // ширина исходной картинки
	int h = vecImage[numCell].getSize().y; // высота исходной картинки

	sf::Image img; // создаём картинку, которую будем возвращать

	img.create(w, h*factor, sf::Color(0,0,0,0)); // Задаём ей форму и цвет
	for(int i=0; i<factor; i++) // Делаем нижеуказанное factor раз
		img.copy(vecImage[numCell], 0, i*h, sf::IntRect(0,0,w,h)); // вставляем картинку на 1 пиксель правее
	return img; // возвращаем картинку
}
*/

/*
// Возвращает картинку под номером numCell из vecImage в зависимости от factorX и factorY (factor - множитель)
sf::Image Design::getImage(int numCell, int factorX, int factorY)
{
	// Если размер изменять не нужно,                    вызываем getImage(...)
	// Иначе если нужно изменить картинку в обе стороны, вызываем getNewImage2(...)
	// Иначе если нужно изменить картинку по ширине,     вызываем getNewImageX(...)
	// Иначе нужно изменить картинку по высоте,          вызываем getNewImageY(...)
	if(factorX <= 1 && factorY <= 1)    return getImage(numCell);
  else if(factorX > 1 && factorY > 1) return getNewImage2(numCell, factorX, factorY);
	else if(factorX > 1)                return getNewImageX(numCell, factorX);
	else                                return getNewImageY(numCell, factorY);
}
*/