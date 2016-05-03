#include "Object.h"


Object::Object()
{
  data();
}
Object::Object(sf::String filename)
{
	data();
	load(filename);
}
Object::~Object()
{
	
}

void Object::draw(sf::RenderWindow* window)
{
	drawImage(window);
	window->draw(sprite);
}
void Object::drawImage(sf::RenderWindow* window)
{
	for(std::vector<Image*>::iterator it = vecImage.begin(); it != vecImage.end(); it++)
		(*it)->draw(window);
}

bool Object::load_image()
{
	
	Image* image = new Image("test/radius1_200x200.png");
	vecImage.push_back(image);

	Image* image2 = new Image("test/radius2_200x200.png");
	vecImage.push_back(image2);

	Image* hp = new Image("test/hp.png");
	vecImage.push_back(hp);

	Image* mp = new Image("test/mp.png");
	vecImage.push_back(mp);
	
	return true;
}

void Object::setRadiusAttack(float radius)
{
	radius_ataki = radius;
	radius_ataki_current = radius;

	float scale = 2*radius_ataki_current/vecImage[0]->getSizeX();
	vecImage[0]->setScale(scale,scale);
}
float Object::getRadiusAttack()
{
	return radius_ataki;
}
void Object::setRadiusReview(float radius)
{
	radius_review = radius;
	radius_review_current = radius;
	float scale = 4*radius_ataki_current/vecImage[1]->getSizeX();
	vecImage[1]->setScale(scale,scale);
}
float Object::getRadiusReview()
{
	return radius_review;
}
void Object::setHp(float hp_)
{
	hp_current = hp = hp_;
	vecImage[2]->setScale(100,1);
}
void Object::setDHP(float damage)
{
	hp_current -= damage;
	vecImage[2]->setScale(100*hp_current/hp,1);
}
void Object::setMp(float mp_)
{
	mp_current = mp = mp_;
	vecImage[3]->setScale(100,1);
}

void Object::data()
{
	radius_physical = 0;
	setActivism(true);
	setIsMove(true);
	setIsRotate(true);
	data_time_life(0, 0);
	speed = 0;
	speedMax = 500;
	speedMin = -speedMax/2;
	speedUp = speedMax/5;
	speedRotation = 180;
	speedX = 0;
	speedY = 0;

	setScale(1,1);
	data_time_frame(0.25);
	setFlag1(true);

	// Задаём параметры маршрута
	vecRound.reserve(1);
	Round* round = new Round;
	round->data();
	vecRound.push_back(round);
	
	vecTarget.reserve(1);
	//Object* obj = new Object();
	//vecTarget.push_back(obj);
	vecTarget.push_back(NULL);

	load_image();
	setRadiusAttack(0);
	setRadiusReview(0);
	setHp(1);
	setMp(1);

	// Устанавливаем статус 0 - ожидание
	setStatus(1);
	setStatus(0); 
	//=============
	angle2 = 0;
	setIsMove(true);

	time1max = 1; time1 = time1max;
	time2max = 1; time2 = time2max;
	status_attack = 1;
}

void Object::behaviorObject(float time)
{
	// В соответствии со статусом своё поведение
	switch(getStatus())
	{
	case 0: behavior_wait(time); break;         // ОЖИДАНИЕ 
	case 1: behavior_movement(time); break;     // ПЕРЕМЕЩЕНИЕ
	case 2: behavior_searchTarget(time); break; // ПОИСК ЦЕЛИ
	case 3: behavior_follow(time); break;       // СЛЕДОВАНИЕ
	case 4: behavior_pursuit(time); break;      // ПРЕСЛЕДОВАНИЕ
	case 5: break;
	case 6: break;
	case 7: break;
	}
	shift_frame(time);
}

void Object::behavior_wait(float time)
{
	// ОЖИДАНИЕ
}

void Object::behavior_movement(float time)
{
	cout << "1";
	// разовое ПЕРЕМЕЩЕНИЕ 
	if(isMove == true)
	{
		cout << "1";
	  // Если дистанция до точки назначения больше перемещения
	 	if(vecRound[0]->distanceCurrent > speed*time)
		{
			cout << "1";
			move(speedX*time, speedY*time); // Двигаемся
			vecRound[0]->update(getPositionX(), getPositionY()); // Обновляем путь
		} 
		// Иначе дистанция до точки назначения меньше перемещения
		else 
		{
			cout << "2";
			// Создаём новые координаты
			float x = vecRound[0]->vecPoint[2]->posX;
			float y = vecRound[0]->vecPoint[2]->posY;
			// Встаём в точку назначения 
			setPosition(x, y);
			newTarget_rand();
			//setIsMove(false);
			////setStatus(0); // Достигли точки назначения - ожидаем
			//setNumFrameWcur(2);
		}
		moveImage();
	}
	else
	{
		cout << "3";
	}
	cout << endl;
}

void Object::behavior_movement_rand(float time)
{
	if(isMove)
	{
	  // Если дистанция до точки назначения больше перемещения
	 	if(vecRound[0]->distanceCurrent > speed*time)
		{
			move(speedX*time, speedY*time); // Двигаемся
			vecRound[0]->update(getPositionX(), getPositionY()); // Обновляем путь
		} 
		// Иначе дистанция до точки назначения меньше перемещения
		else 
		{
			float x = vecRound[0]->vecPoint[2]->posX;
			float y = vecRound[0]->vecPoint[2]->posY;
			setPosition(x, y);

			newTarget_rand();
		}
		moveImage();
	}
}
void Object::behavior_follow(float time)
{
	// СЛЕДОВАНИЕ
	if(vecTarget[0] != NULL)
	{
		//if(getIsMove() == true)
		//{
			newTarget1(vecTarget[0]->getPositionX(), vecTarget[0]->getPositionY());
			behavior_movement(time);
		//}
		if(test1() == false)
		{
			setStatus(2);
			behavior_movement_rand(time);
		}
	}
	
}
void Object::behavior_pursuit(float time)
{
	// ПРЕСЕДОВАНИЕ
	if(vecTarget[0] != NULL)
	{
		newTarget1(vecTarget[0]->getPositionX(), vecTarget[0]->getPositionY());
		if(vecRound[0]->distanceCurrent > getRadiusAttack())
		{
			behavior_movement(time);
		} 
		else 
		{
			behavior_attack(time);
		}
		if(test1() == false)
		{
			setStatus(2);
			behavior_movement_rand(time);
		}
	}
}
bool Object::behavior_searchTarget(float time)
{
	// ПОИСК ЦЕЛИ
	if(test1() == true)
	{
		setStatus(4); // Статус преследования
		return true;
	} else {
		behavior_movement_rand(time);
	}
	return false;
}

void Object::behavior_attack(float time)
{
	switch(status_attack)
	{
	case 1: function1(time); break;
	case 2: function2(time); break;
	}
}

void Object::moveImage()
{
	vecImage[0]->setPosition(getPositionX(), getPositionY()); // r ataka
	vecImage[1]->setPosition(getPositionX(), getPositionY()); // r review
	vecImage[2]->setPosition(getPositionX()-50, getPositionY() - 55); // hp
	vecImage[3]->setPosition(getPositionX()-50, getPositionY() - 45); // mp
}

void Object::newTarget1(float x, float y)
{
	vecRound[0]->newPoint(getPositionX(), getPositionY(), x, y);

	float angle = vecRound[0]->angle;
	
	if(isRotate == true) 
		sprite.setRotation(angle);
	
	if(isShiftFrame == true)
	{
		if(0 <= angle && angle <=  0+45 || 270+45 <= angle && angle <= 360)
			setNumFrameHcur(4);
		else if( 90-45 < angle && angle <  90+45)
			setNumFrameHcur(3);
		else if(180-45 < angle && angle < 180+45)
			setNumFrameHcur(1);
		else if(270-45 < angle && angle < 270+45)
			setNumFrameHcur(2);
	}

	speedX =      mySin(angle)*speed;
	speedY = -1 * myCos(angle)*speed;
	setIsMove(true);
}

void Object::newTarget_rand()
{
	float r = radius_review_current;
	float x2 = getPositionX() + myRand1(-r,r);
	float y2 = getPositionY() + myRand1(-r,r);
	newTarget1(x2, y2);
}

void Object::setTarget(Object* object)
{
	vecTarget[0] = object;
}

void Object::setIsMove(bool boolean)
{
	isMove = boolean;
}
bool Object::getIsMove(void)
{
	return isMove;
}
void Object::setIsRotate(bool boolean)
{
	isRotate = boolean;
}
bool Object::getIsRotate(void)
{
	return isRotate;
}

void Object::setIsShiftFrame(bool boolean)
{
	isShiftFrame = boolean;
}
bool Object::getIsShiftFrame(void)
{
	return isShiftFrame;
}


void Object::setStatus(int status)
{
	status_previous = status_current;
	status_current = status;
}
int Object::getStatus()
{
	return status_current;
}

bool Object::test1()
{
	if(vecTarget[0] != NULL)
	{
		if(HitTestPointCircle(getPositionX(), 
													getPositionY(), 
													getRadiusReview()*2, 
													vecTarget[0]->getPositionX(), 
													vecTarget[0]->getPositionY(), 
													0) == true
													)
		{
			return true; // цель в зоне атаки
		}
	}
	return false;
}
void Object::function1(float time)
{
	if(time1 <= 0)
	{
		status_attack = 2;
		time2 = time2max + time1;
	} else {
		time1 -= time;
	}
}
void Object::function2(float time)
{
	if(time2 <= 0)
	{
		status_attack = 1;
		time1 = time1max + time2;
		attack();
	} else {
		time2 -= time;
	}
}
void Object::attack()
{
	vecTarget[0]->setDHP(10);
}
void Object::setAngle2(float angle)
{
	angle2 = angle;
}
float Object::getAngle2(void)
{
	return angle2;
}


////////////////////////////////
// АКТИВНОСТЬ
////////////////////////////////
void Object::activation_()
{
	isActivism = true;
  setAlpha(255);
}
void Object::deactivation_()
{
	isActivism = false;
  setAlpha(0);
}
bool Object::getActivism()
{
	return isActivism;
}
void Object::setActivism(bool boolean)
{
	isActivism = boolean;
}
void Object::activation(float x, float y, float speed_, float angle, bool rotate, float time)
{
  setPosition(x, y);
  if( rotate == true )
    sprite.setRotation(angle);

	// Задаём параметры скорости
  data_speed(speed_, angle);
	//data_speed(0, angle);

  // Задаём максимальнео время жизни
	data_time_life(time, 0);
	// Элементарная активация
  activation_();
}
void Object::deactivation()
{
  deactivation_();
  //data();
}
////////////////////////////////
void Object::data_speed(float speed_, float angle2_)
{
  angle2 = angle2_;
  speed = speed_;
	// Проверяем на выход за пределы 
	if(speed > speedMax) speed = speedMax;
	if(speed < speedMin) speed = speedMin;
	// задаём значения для скоростей по осям
  speedX =      speed * mySin(angle2);
  speedY = -1 * speed * myCos(angle2);
}
void Object::data_time_life(float time_life_max_, float time_life_current_)
{
  time_life_max = time_life_max_;
  time_life_current = time_life_current_;
}
////////////////////////////////
bool Object::moveObject(float time)
{
	move(speedX*time,speedY*time);
  return true;
}
bool Object::time_life(float time)
{
  time_life_current += time;
  if( time_life_current >= time_life_max )
	  return false;
  else
    return true;
}
////////////////////////////////
void Object::coutInfoPosition()
{
	cout << "(x:y)=(" << getPositionX() << ":" << getPositionY() << ")" << endl;
}
void Object::coutInfoSpeed()
{
	//
}

void Object::setRadiusPhysical(float radius)
{
	radius_physical = radius;
}
float Object::getRadiusPhysical()
{
	return radius_physical;
}