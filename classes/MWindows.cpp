#include "stdafx.h"
#include "MWindows.h"

// �����������
MWindows::MWindows(void)
{
	data();
}

// ����������
MWindows::~MWindows(void)
{
	// ����������� ������
	vecWindow.~vector();
}

// ����� ��������� ����������
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

// ��������� ���� � ���������� ����
void MWindows::add(Window* window)
{
	window->setVector(&vecInt);
	vecWindow.push_back(window);
}

// ���������� ������� (��������� ����)
bool MWindows::behavior(Mouse* mouse)
{
	// ���������� ���
	switch(mouse->getEventButton(sf::Mouse::Left))
	{
	case 0: behaviorCase0(mouse); break; // ��� �� ������
	case 1: behaviorCase1(mouse); break; // ��� ����������
	case 2: 
		if(!behaviorCase2(mouse)); 
		return false;
		break; // ��� ��� ������ 
	case 3: behaviorCase3(mouse); break; // ��� �����������
	}

	return true;
}

// ���������� ����
void MWindows::sort1(int num)
{
	Window* window = vecWindow[num];

	for(int i=num; i>0; i--)
	{
		vecWindow[i] = vecWindow[i-1];
	}
	vecWindow[0] = window;
}

// ��������� �� �������� ����
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
	// ���� �� ����� ���� ��������� �� ����
	if(flag0 == true)
	{
		// � ������ ������ �� � ����
		if(vecWindow[iNum]->check1(&x,&y) == false)
		{
			// ������ ��������� ������ �� 0 (����)
			// ��� �� ������ ������ �� �������� � 1 �� 0
			vecWindow[iNum]->buttonSetCell(0, 0);
			flag0 = false;
		}
	}

	// ���� ������ ���� �� ������� �������� ����� � �������� ��� iNum
	for(std::vector<Window*>::iterator it = vecWindow.begin(); it != vecWindow.end(); it++)
  {
    if((*it)->check1(&x, &y))
    {
	    iNum = it - vecWindow.begin(); // � iNum ������������ ����� ���� ������� ����
			flag0 = true;
	    break; 
		}
	}
    
	// ���� ���� ����
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
		// ���������� � numRote ����������� ����������
    numRote = vecWindow[iNum]->check3(&x, &y);
		// ���� ���������� ����
		if(numRote != -1)
		{
			// ������ ������
			if(numRote == 0 || numRote == 3) mouse->setCursor(4);
			if(numRote == 1 || numRote == 2) mouse->setCursor(5);
			if(numRote == 4 || numRote == 7) mouse->setCursor(2);
			if(numRote == 5 || numRote == 6) mouse->setCursor(3);
		} 
		// ����� ���� �����������
	  else if(vecWindow[iNum]->check2(&x, &y)) 
	  {
			// ������ ������
	    mouse->setCursor(1);
	  } else {
			// ����� ������ ������ �� ��������
	    mouse->setCursor(0);
	  }
  } else {
		// ����� ������ ������ �� ��������
	  mouse->setCursor(0);
  }
	return true;
}
bool MWindows::behaviorCase1(Mouse* mouse)
{
	int x = mouse->getX();
	int y = mouse->getY();
	// �������� �� ���� �����, ������� � �������
	for(std::vector<Window*>::iterator it = vecWindow.begin(); it != vecWindow.end(); it++)
	{
		// ��������: ���� �� ������� ���� � ����
		if((*it)->check1(&x, &y) == true)
		{
			// ���� ������� ���� (�� �� �����)
			flag1 = true;

			// ���������� ���������� ���� � ����
			vecInt[0] = (*it)->getPositionX();
			vecInt[1] = (*it)->getPositionY();
			vecInt[2] = x;
			vecInt[3] = y;
			// ��������� ���� ������ �� ������ ���� ��, ������� ���� ��������
			sort1(it - vecWindow.begin());

			vecWindow[0]->save();

			iNum2 = vecWindow[0]->checkButton(&x, &y);
			if(iNum2 != -1)
				flagBut = true;
			
			
			// ���� ���� ���� ��� �� ������������� ����
			numRote = vecWindow[0]->check3(&x, &y);
			if(numRote != -1)
				flag3 = true;

			// ���� ���� ���� ��� �� ��������������� ����
			if(vecWindow[0]->check2(&x, &y))
				flag2 = true;

			break; // �������������� ������� �� ������� ����, �.�. �� ����� ���� �� ������� ��������.
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