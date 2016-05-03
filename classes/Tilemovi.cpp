//Tilemovi.cpp
#include "Tilemovi.h"

Tilemovi::Tilemovi(void)
{
	data();
}
Tilemovi::Tilemovi(sf::String filename)
{
	data();
	load(filename);
}
Tilemovi::~Tilemovi(void)
{

}
void Tilemovi::data(void)
{
	data_time_frame(0.25); // ������� ����� ������
}
bool Tilemovi::shift_frame(float time)
{
  ///////////////////////////////////////////////////////////
  // if(numFrame <= 1) - ���� ���� <= 1, �� ������ ����� �� ���� 
  ///////////////////////////////////////////////////////////
  if(numFrame > 1)
  {
		timeFrameCur += time;
		if(timeFrameCur >= timeFrameMax)
		{
			if(!update_frame())
				return false;
			timeFrameCur -= timeFrameMax;
		}
  }
	return true;
}

void Tilemovi::data_time_frame(float time_shift_frame)
{
	// ����� �����, ��� ������� ����� ��������� ����
  timeFrameCur = 0;                //
  timeFrameMax = time_shift_frame; //
}

