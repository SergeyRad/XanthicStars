//Desigh.cpp
//v1.0 05.04.2016
//by DSL.legozaur
#include "Design.h"

// ����������� �� ���������
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

// designToImage - ����� ������, �� ��������
// *image1 - ������ �� ����� ������
// *image2 - ������ �� ��������, � ������� ����� ��������� ����� �������
// numCellWidth  - ��������� �������� � ������� �� ������ [������� � 0]
// numCellHeight -                              �� ������ [������� � 0]
// sideCell - ������ ������ (������ 32)
bool Design::designToImage(sf::Image *image1, sf::Image *image2, int numCellWidth, int numCellHeight, int sideCell)
{
	// ���� � ������ ����� ��������, �� W � H � ������ � ������ ��������������
	int W = -1; // ������
	int H = -1; // ������

	int imin = numCellWidth * sideCell;  
	int imax = imin + sideCell;         

	int jmin = numCellHeight * sideCell; 
	int jmax = jmin + sideCell;          
	
	for(int j = jmin; j < jmax; j++)
	{
		for(int i = imin; i < imax; i++)
		{
			if(image1->getPixel(i, j) != sf::Color(255,255,255,0))
			{// ���� ������� �� ������
				if( W < i-imin) W++;
				if( H < j-jmin) H++;
			}
		}
	}
	
	if(W != -1 && H != -1)
	{
		W++; H++; // ���� 31.03.2016 8:40 ��� // ������ �������� �� 1 �������
		image2->create(W, H, sf::Color(255, 255, 255, 255));
		image2->copy(*image1, 0, 0, sf::IntRect(imin,jmin, imin+W,jmin+H));
		return true;
	}
	return false;
}

/*
// ���������� �������� ��� ������� numCell ����������� �� ������ � factorX ��� � �� ������ � factorY ���
sf::Image Design::getNewImage1(int numCell, int factorX, int factorY)
{
	sf::Image img0 = getNewImageX(numCell, factorX); // ����������� �������� �� ������ ��� ������ (factorX)
	int h = img0.getSize().y; // ������ ������ (���������� ��� ��������)

	sf::Image img; // ������ �������� ������� ����� ����������

	img.create(factorX, factorY, sf::Color(0,0,0,0)); // ����� � �������
	int a = int(float(factorY)/h); // � - ��� ���������� ����� � ������
	if(a*h <= factorY) // ���� �� �� ������������ ������ ��������
		a++; // ��������� 1 ������, ��� �� ����� ���������

	for(int i=0; i<a; i++) // ������ "�" ��� ������������� 
		img.copy(img0, 0, i*h, sf::IntRect(0,0,factorX,h)); // ��������� (������ ��������� ���� �� �������� h)
	return img; // ���������� ��������
}

// ���������� �������� ��� ������� numCell ����������� �� ������ � factorX ��� � �� ������ � factorY ���
sf::Image Design::getNewImage2(int numCell, int factorX, int factorY)
{
	sf::Image img0 = getNewImageY(numCell, factorY); // ����������� �������� �� ������ ��� ������ (factorX)
	int w = img0.getSize().x; // ������ ������ (���������� ��� ��������)
	int h = img0.getSize().y; // ������ ������ (���������� ��� ��������)
	sf::Image img; // ������ �������� ������� ����� ����������
	img.create(factorX, factorY, sf::Color(0,0,0,0)); // ����� � �������

	for(int i=0; i<factorX; i++) // ������ "�" ��� ������������� 
		img.copy(img0, i*w, 0, sf::IntRect(0,0,w,h)); // ��������� (������ ��������� ���� �� �������� h)
	return img; // ���������� ��������
}

// ���������� �������� ��� ������� numCell ����������� �� ������ � factor ���
sf::Image Design::getNewImageX(int numCell, int factor)
{
	int w = vecImage[numCell].getSize().x; // ������ �������� ��������
	int h = vecImage[numCell].getSize().y; // ������ �������� ��������

	sf::Image img; // ������ ��������, ������� ����� ����������

	img.create(w*factor, h, sf::Color(0,0,0,0)); // ����� �� ����� � ����
	for(int i=0; i<factor; i++) // ������ ������������� factor ���
		img.copy(vecImage[numCell], i*w, 0, sf::IntRect(0,0,w,h)); // ��������� �������� �� 1 ������� ������
	return img; // ���������� ��������
}

// ���������� �������� ��� ������� numCell ����������� �� ������ � factor ���
sf::Image Design::getNewImageY(int numCell, int factor)
{
	int w = vecImage[numCell].getSize().x; // ������ �������� ��������
	int h = vecImage[numCell].getSize().y; // ������ �������� ��������

	sf::Image img; // ������ ��������, ������� ����� ����������

	img.create(w, h*factor, sf::Color(0,0,0,0)); // ����� �� ����� � ����
	for(int i=0; i<factor; i++) // ������ ������������� factor ���
		img.copy(vecImage[numCell], 0, i*h, sf::IntRect(0,0,w,h)); // ��������� �������� �� 1 ������� ������
	return img; // ���������� ��������
}
*/

/*
// ���������� �������� ��� ������� numCell �� vecImage � ����������� �� factorX � factorY (factor - ���������)
sf::Image Design::getImage(int numCell, int factorX, int factorY)
{
	// ���� ������ �������� �� �����,                    �������� getImage(...)
	// ����� ���� ����� �������� �������� � ��� �������, �������� getNewImage2(...)
	// ����� ���� ����� �������� �������� �� ������,     �������� getNewImageX(...)
	// ����� ����� �������� �������� �� ������,          �������� getNewImageY(...)
	if(factorX <= 1 && factorY <= 1)    return getImage(numCell);
  else if(factorX > 1 && factorY > 1) return getNewImage2(numCell, factorX, factorY);
	else if(factorX > 1)                return getNewImageX(numCell, factorX);
	else                                return getNewImageY(numCell, factorY);
}
*/