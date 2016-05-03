//myMath.cpp
#include "myMath.h"

// Created by Kildushov Oleg
// ��������� - ��������� ����
// vk.com/legozaur
// kychka-pc.ru - nikname: legozaur

float myCos(float angle)
{// ���������� ������� ���� � �������
	return cos(angle*PI/180);
}
float mySin(float angle)
{// ���������� ����� ���� � ��������
	return sin(angle*PI/180);
}
// =====
int myRand1(int n1, int n2)
{
    if(n1 > n2)
	{
        n1++;
        return n2 + rand()%(n1-n2);
    } 
	else 
	{
        n2++;
        return n1 + rand()%(n2-n1);
    }
}

float n2(float n)
{
	return n*n;
}

float distance(float  x1, float  y1, float  x2, float  y2)
{
	return sqrt(n2(x1-x2) + n2(y1-y2));
}

float d_angle(float dx, float dy)
{// ���������� ���� ����� ����� ���������
  // Object1( 0, 0) & Object2( 1, 1)
  // Object1(x1,y1) & Object2(x2,y2)
  // dx = x2 - x1; // dx = 1 - 0 = 1;
  // dy = y2 - y1; // dy = 1 - 0 = 1;
  // d_angle(1,1) = 135 
	float angle = 90 + atan2(dy,dx)*180/PI;
	if(angle < 0)                   // 
		angle = 270 + (90 + angle);   // ��������� �������
	return angle;
}

bool HitTestPointCircle(float x1, float y1, float d1, float x2, float y2, float d2)
{
	if(fabs(x2-x1) <= fabs(d2+d1)/2)                     // ���� ������ �������� ��������� � ������ ��� ����� �������� ������ ����� ���������  
		if(fabs(y2-y1) <= fabs(d2+d1)/2)                   // ����������� �������� �� Y
			if(sqrt(n2(x2-x1) + n2(y2-y1)) <= fabs(d2+d1)/2) // 
				return true;
			else
				return false;
		else 
			return false;
	else 
		return false;
}
//