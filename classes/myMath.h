//myMath.h
#include "stdafx.h"

// Created by Kildushov Oleg
// Создатель - Кильдюшов Олег
// vk.com/legozaur
// kychka-pc.ru - nikname: legozaur

#ifndef DSL_MYMATH_H
#define DSL_MYMATH_H

double const PI = 3.14159265;

// Возвращает значение синуса и косинуса по аргумету измеряемому в градусах
float myCos(float angle);
float mySin(float angle);
// ===== ===== =====
int myRand1(int n1, int n2);
float n2(float n);

float distance(float  x1, float  y1, float  x2, float  y2);
float d_angle(float dx, float dy);
bool HitTestPointCircle(float x1, float y1, float h1, float x2, float y2, float h2);

#endif DSL_MYMATH_H
//













