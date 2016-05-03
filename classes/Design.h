//Desigh.h
//v1.0 05.04.2016
//by DSL.legozaur
#ifndef DSL_DESIGN_H
#define DSL_DESIGN_H

#include "stdafx.h"

class Design
{
protected:
	sf::String filename; // ��� ����� �������
	sf::Image image;     // �������� ������ �������
	std::vector<sf::Image> vecImage; // ���������� ��������

	// ����� �������, ������� ����� ��� getImage(int numCell, int factorX, int factorY)
	//sf::Image getNewImage1(int numCell, int factorX, int factorY);
	//sf::Image getNewImage2(int numCell, int factorX, int factorY);
	//sf::Image getNewImageX(int numCell, int factor);
	//sf::Image getNewImageY(int numCell, int factor);
public:
	// ����������� �� ���������
	Design(void);
	// �������� �������
	bool loadImage(sf::String filename);

	// ����������
	~Design(void);
	// �������� ������� ������������� ������ � ����� ��������
  bool designToImage(sf::Image* image1, sf::Image* image2, int numImageW, int numImageH, int sideImage);
	// ���������� �������� �������
	sf::Image getImage();
	// ���������� ���������� �������� ������� ��� �������
	sf::Image getImage(int numCell);
	// ���������� ���������� �������� ������� ��� ������� ����������� �� � � factorX ���, �� Y � factorY ���
  //sf::Image getImage(int numCell, int factorX, int factorY);
	//���������� ��� �������
	sf::String getFilename();
};

#endif DSL_DESIGN_H
