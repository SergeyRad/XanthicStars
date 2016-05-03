//MWindows.h
#ifndef DSL_MWindows_H
#define DSL_MWindows_H

#include "Window.h"
#include "Mouse.h"

class MWindows
{
protected:
	bool flag0; // true - ���� ��������� �� ����� ����
	bool flag1; // true - ���� ������� ���� �� ����� ����
	bool flag2; // true - ���� ������� ���� �� ������� �����������
	bool flag3; // true - ���� ������� ���� �� ������������� �������
	bool flagBut;
	int numRote; // ���������� � �������� � 1 �� 2 � �� ���������� 2 (case)
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

	// ��������� ���� � ���������� ����
	void add(Window* window);

	// ���������� ������� (��������� ����)
	bool behavior(Mouse* mouse);

	// ���������� ����
	void sort1(int j);

	// ��������� �� �������� ����
	void draw(sf::RenderWindow* window);
};

#endif DSL_MWindows_H
