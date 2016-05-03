#include "stdafx.h"
 
sf::View view;//�������� sfml ������ "���", ������� � �������� �������

void setWindow(sf::RenderWindow* window)
{
	window->setView(view);
}

void getplayercoordinateforview(float x, float y) { //������� ��� ���������� ��������� ������
	float tempX = x; float tempY = y;//��������� ����� ������ � ��������� ��, ����� ������ ����
 
	if (x < 320) tempX = 320;//������� �� ���� ����� �������
	if (y < 240) tempY = 240;//������� �������
	if (y > 554) tempY = 554;//������ �������	
 
	view.setCenter(tempX, tempY); //������ �� �������, ��������� ��� ����������. 
	
}
 
 
void viewmap(float time) { //������� ��� ����������� ������ �� �����. ��������� ����� sfml
	int k = 300;
 
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) 
	{
		cout << "123454321";
		view.move(k*time, 0);//�������� ����� ������ (�� ����, ����� �� ������� ����� - �� ���� �����)
	}
 
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		view.move(0, k*time);//�������� ����� ���� (�� ����, ����� �� ������� ����� - �� ���� �����)
	}
 
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		view.move(-k*time, 0);//�������� ����� ����� (�� ����, ����� �� ������� ����� - �� ���� �����)
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		view.move(0, -k*time);//�������� ����� ������ (�� ����, ����� �� ������� ����� - �� ���� �����)
	}
 
}
 
void changeview(){
 
 
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::I)) {
		view.zoom(1.0100f); //������������, ����������
		//view.zoom(1.0006f); //���� ����� ����������� ��������������
	}
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::K)) {
		view.zoom(0.9900f); //������������, ����������
		//view.zoom(1.0006f); //���� ����� ����������� ��������������
	}
	/*
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::O)) {
		//view.setRotation(90);//����� �� ������ ������� ������
		view.rotate(1);//���������� ������������ ������ (������������� �������� - � �������� �������)
	}
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::L)) {
		//view.setRotation(90);//����� �� ������ ������� ������
		view.rotate(-1);//���������� ������������ ������ (������������� �������� - � �������� �������)
	}

  
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)) 
	{
		view.setSize(1200, 700);//������������� ������ ������ (��� ��������)
	}
   */

	/*
	if (Keyboard::isKeyPressed(Keyboard::E)) {
		view.setSize(540, 380);//�������� ������ ������
	}
  */
 
	/*
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::U)) {
		view.setViewport(sf::FloatRect(0, 0, 0.5f, 1));//����� ������� �������� ���������� ����� ��� ���� �� �����. ����� ������ ������� ��� ���� ������ View � ����������� � ���� ���������� ������ 2.
	}
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::J)) {
		view.setViewport(sf::FloatRect(0, 0, 1, 1));//����� ������� �������� ���������� ����� ��� ���� �� �����. ����� ������ ������� ��� ���� ������ View � ����������� � ���� ���������� ������ 2.
	}
	*/
}