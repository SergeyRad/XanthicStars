//Tilemove.h
#pragma once
#include "stdafx.h"
#include "tileset.h"
class Tilemovi :
	public Tileset
{
private:
	float timeFrameCur; // ����� ��� ����������
  float timeFrameMax; // ����� ��� ����� �����
public:
	Tilemovi(void);
	Tilemovi(sf::String filename);
	~Tilemovi(void);
	void data();

	bool shift_frame(float time);
  void data_time_frame(float time_shift_frame);
};

