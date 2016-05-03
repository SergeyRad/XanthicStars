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
	float angle; // Угол между началом и концом (0 -вверх, 90 - вправо, 0~360); 
	float distanceMax; // расстояние от точки до точки;
	float distanceCurrent; // Текущее расстояние до точки;
	std::vector<Point*> vecPoint;
	
	void data()
	{
		// Резервируем место под 2 точки
		vecPoint.reserve(3);
		// Создаём 2 новых точки (основные)
		for(int i=0; i<3; i++)
		{
		  Point* point = new Point;
		  point->posX = 0;
		  point->posY = 0;
		  vecPoint.push_back(point);
		}
	}
	// Функция обновляет положение объекта
	void update(float x, float y)
	{
		// Обновляет координату текущего положения
		vecPoint[1]->posX = x;
		vecPoint[1]->posY = y;
		// Обновляет дистанцию от текущего положения до точки назначения
		distanceCurrent = distance(vecPoint[1]->posX, vecPoint[1]->posY, vecPoint[2]->posX,  vecPoint[2]->posY);
	}
	// Функция задаёт точку откуда и куда надо следовать
	void newPoint(float x1, float y1, float x2, float y2)
	{
		// Откуда
	  vecPoint[0]->posX = x1;
		vecPoint[0]->posY = y1;
		// Где сейчас
		vecPoint[1]->posX = x1;
		vecPoint[1]->posY = y1;
		// Куда
		vecPoint[2]->posX = x2;
		vecPoint[2]->posY = y2;
		// Определяем угол
		angle = d_angle(x2-x1, y2-y1);
		// Определяем расстояние от начала до конца
		distanceMax = distance(x1, y1, x2, y2);
		// Текущие расстояние = максимальному, т.к. только что создана новая точка
		distanceCurrent = distanceMax;
	}
};

class Object :
	public Tilemovi
{
protected:
	std::vector<Object*> vecTarget; // ссылка на вектор жертв

	std::vector<Image*> vecImage;
	std::vector<Round*> vecRound; // Вектор маршрутов

	bool isActivism;   // Активность
	bool isRotate;
	bool isMove;       // Надо ли двигаться? 
	bool isShiftFrame; // Надо ли сменять кадры?
	
	////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////
	float speed;    // Текущая скорость
	float speedMax; // Максимальная скорость
	float speedMin; // Минимальная скорость (Задний ход)
	float speedUp;  // Ускорение
	float speedX;
	float speedY;
	float speedRotation; // скорость поворота
	/////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////
	float time_life_max;     // максимальное время жизни
  float time_life_current; //      текущее время жизни
	/////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////
	float radius_ataki;          // Начальный радиус атаки
	float radius_ataki_current;  //   Текущий радиус атаки
	float radius_review;         //         Радиус обзора
	float radius_review_current; // Текущий радиус обзора
	float radius_physical;
	/////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////
	float hp;
	float hp_current;

	float mp;
	float mp_current;

	int status_previous; // Предыдущий статус
	int status_current;  // Текущий статус

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
	// КОНСТРУКТОРЫ И ДЕСТРУКТОРЫ
	////////////////////////////////
	Object();
	Object(sf::String filename);
	~Object();
	////////////////////////////////

	////////////////////////////////
	// DRAW МЕТОДЫ
	////////////////////////////////
	void draw(sf::RenderWindow* window);
	void drawImage(sf::RenderWindow* window);
  ////////////////////////////////

	////////////////////////////////
	// МЕТОДЫ ПОВЕДЕНИЯ
	////////////////////////////////
	void behaviorObject(float time);
	// Поведение: ожидание
	void behavior_wait(float time);  
	// Поведение: перемещение
	void behavior_movement(float time);
	// Поведение: перемещение
	void behavior_movement_rand(float time);
	// Поведение: поиск цели
	bool behavior_searchTarget(float time);
	// Поведение: атака
	void behavior_attack(float time);
	// Поведение: следование
	void behavior_follow(float time);
	// Поведение: преследование
	void behavior_pursuit(float time); 
	/////////////////////////////////

	////////////////////////////////
	// МЕТОДЫ УПРАВЛЕНИЯ
	////////////////////////////////
	void moveImage();
	bool moveObject(float time);
	void newTarget1(float x, float y);
	void newTarget_rand();
	bool test1();
  bool time_life(float time);
	///////////////////////////////

	///////////////////////////////
	// РЕАЛИЗАЦИЯ АТАКИ
	///////////////////////////////
	void function1(float time);
	void function2(float time);
	void attack();
	///////////////////////////////

	////////////////////////////////
	// АКТИВНОСТЬ
	////////////////////////////////
	void activation_();
	void deactivation_();
	void activation(float x, float y, float speed_, float angle, bool rotate, float time);
  void deactivation();
	////////////////////////////////
  
	////////////////////////////////
	// DATA МЕТОДЫ
	////////////////////////////////
	bool load_image();
	void data();
	void data_speed(float speed_, float angle2_);
	void data_time_life(float time_life_max_, float time_life_current_);
	////////////////////////////////

	//////////////////////////////////
	// SET МЕТОДЫ
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
	// GET МЕТОДЫ
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