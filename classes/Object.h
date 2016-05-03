#include "stdafx.h"

#include "image.h"
#include "tileset.h"
#include "tilemovi.h"

#include "myMath.h"

#ifndef DSL_OBJECT_H
#define DSL_OBJECT_H

struct Point
{
	float posX;
	float posY;
};

struct Round
{
	float angle; // ���� ����� ������� � ������ (0 -�����, 90 - ������, 0~360); 
	float distanceMax; // ���������� �� ����� �� �����;
	float distanceCurrent; // ������� ���������� �� �����;
	std::vector<Point*> vecPoint;
	
	void data()
	{
		// ����������� ����� ��� 2 �����
		vecPoint.reserve(3);
		// ������ 2 ����� ����� (��������)
		for(int i=0; i<3; i++)
		{
		  Point* point = new Point;
		  point->posX = 0;
		  point->posY = 0;
		  vecPoint.push_back(point);
		}
	}
	// ������� ��������� ��������� �������
	void update(float x, float y)
	{
		// ��������� ���������� �������� ���������
		vecPoint[1]->posX = x;
		vecPoint[1]->posY = y;
		// ��������� ��������� �� �������� ��������� �� ����� ����������
		distanceCurrent = distance(vecPoint[1]->posX, vecPoint[1]->posY, vecPoint[2]->posX,  vecPoint[2]->posY);
	}
	// ������� ����� ����� ������ � ���� ���� ���������
	void newPoint(float x1, float y1, float x2, float y2)
	{
		// ������
	  vecPoint[0]->posX = x1;
		vecPoint[0]->posY = y1;
		// ��� ������
		vecPoint[1]->posX = x1;
		vecPoint[1]->posY = y1;
		// ����
		vecPoint[2]->posX = x2;
		vecPoint[2]->posY = y2;
		// ���������� ����
		angle = d_angle(x2-x1, y2-y1);
		// ���������� ���������� �� ������ �� �����
		distanceMax = distance(x1, y1, x2, y2);
		// ������� ���������� = �������������, �.�. ������ ��� ������� ����� �����
		distanceCurrent = distanceMax;
	}
};

class Object :
	public Tilemovi
{
protected:
	std::vector<Object*> vecTarget; // ������ �� ������ �����

	std::vector<Image*> vecImage;
	std::vector<Round*> vecRound; // ������ ���������

	bool isActivism;   // ����������
	bool isRotate;
	bool isMove;       // ���� �� ���������? 
	bool isShiftFrame; // ���� �� ������� �����?
	
	////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////
	float speed;    // ������� ��������
	float speedMax; // ������������ ��������
	float speedMin; // ����������� �������� (������ ���)
	float speedUp;  // ���������
	float speedX;
	float speedY;
	float speedRotation; // �������� ��������
	/////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////
	float time_life_max;     // ������������ ����� �����
  float time_life_current; //      ������� ����� �����
	/////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////
	float radius_ataki;          // ��������� ������ �����
	float radius_ataki_current;  //   ������� ������ �����
	float radius_review;         //         ������ ������
	float radius_review_current; // ������� ������ ������
	float radius_physical;
	/////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////
	float hp;
	float hp_current;

	float mp;
	float mp_current;

	int status_previous; // ���������� ������
	int status_current;  // ������� ������

	// ===========
	float angle2;
	// === NEW ===
  float time1;
	float time1max;
	float time2;
	float time2max;
	int status_attack;
	// === NEW ===
public:
	////////////////////////////////
	// ������������ � �����������
	////////////////////////////////
	Object();
	Object(sf::String filename);
	~Object();
	////////////////////////////////

	////////////////////////////////
	// DRAW ������
	////////////////////////////////
	void draw(sf::RenderWindow* window);
	void drawImage(sf::RenderWindow* window);
  ////////////////////////////////

	////////////////////////////////
	// ������ ���������
	////////////////////////////////
	void behaviorObject(float time);
	// ���������: ��������
	void behavior_wait(float time);  
	// ���������: �����������
	void behavior_movement(float time);
	// ���������: �����������
	void behavior_movement_rand(float time);
	// ���������: ����� ����
	bool behavior_searchTarget(float time);
	// ���������: �����
	void behavior_attack(float time);
	// ���������: ����������
	void behavior_follow(float time);
	// ���������: �������������
	void behavior_pursuit(float time); 
	/////////////////////////////////

	////////////////////////////////
	// ������ ����������
	////////////////////////////////
	void moveImage();
	bool moveObject(float time);
	void newTarget1(float x, float y);
	void newTarget_rand();
	bool test1();
  bool time_life(float time);
	///////////////////////////////

	///////////////////////////////
	// ���������� �����
	///////////////////////////////
	void function1(float time);
	void function2(float time);
	void attack();
	///////////////////////////////

	////////////////////////////////
	// ����������
	////////////////////////////////
	void activation_();
	void deactivation_();
	void activation(float x, float y, float speed_, float angle, bool rotate, float time);
  void deactivation();
	////////////////////////////////
  
	////////////////////////////////
	// DATA ������
	////////////////////////////////
	bool load_image();
	void data();
	void data_speed(float speed_, float angle2_);
	void data_time_life(float time_life_max_, float time_life_current_);
	////////////////////////////////

	//////////////////////////////////
	// SET ������
	//////////////////////////////////
	void setRadiusPhysical(float radius);
	void setRadiusAttack(float radius);
	void setRadiusReview(float radius);

	void setHp(float hp_);
	void setDHP(float damage);
	void setMp(float mp_);
	void setAngle2(float angle);
	void setStatus(int status);
  void setTarget(Object* object);
  void setIsMove(bool boolean);
  void setIsRotate(bool boolean);
  void setIsShiftFrame(bool boolean);
  void setActivism(bool boolean);
	//////////////////////////////////

	//////////////////////////////////
	// GET ������
	//////////////////////////////////
	float getRadiusPhysical();
	float getRadiusAttack();
	float getRadiusReview();

	float getAngle2(void);
	int   getStatus(void);
	bool  getIsMove(void);
	bool  getIsRotate(void);
	bool  getIsShiftFrame(void);
  bool getActivism();
	//////////////////////////////////

  void coutInfoPosition();
	void coutInfoSpeed();
};


#endif DSL_OBJECT_H