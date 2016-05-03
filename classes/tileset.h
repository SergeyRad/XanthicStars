//Tileset.h
#include "stdafx.h"
#include "Image.h"

#ifndef DSL_TILESET_H
#define DSL_TILESET_H

class Tileset : public Image
{
protected:
  bool flag1; // ƒошЄл до конца, идти обратно? (true - разворот)
  bool flag2; // ”же конец строчки тайлсета?
  bool flag3; // Ќужно ли переходить на новую строку (дл€ нелинейных тайлсетов)

  int numFrameWcur; // текущей номер кадра по ширине
  int numFrameHcur; //                        высоте
  int numFrameWmax; // максимальное количество кадров на ширину
  int numFrameHmax; //                                   высоту

	int numFrameWmax2; // максимальное текущее количество кадров на ширину
  int numFrameHmax2; //                                           высоту

  int frameW; //  ???
  int frameH; //  ???

	int numFrame;
public:
  Tileset();
  //Tileset(sf::String filename, int number_frame_width, int number_frame_height);
	Tileset(sf::String filename);
	//

	void data_frames(int number_frame_width, int number_frame_height); 
	void data_frames_blackboard(int number_frame_width, int number_frame_height);


  void draw(sf::RenderWindow *window); //

  void data();
  bool update_frame();

  void setNumFrameWcur(int number); //
  void setNumFrameHcur(int number); //

  int getNumFrameWcur(); //
  int getNumFrameHcur(); //
  
  void setFlag1(bool flag); //
  void setFlag3(bool flag); //
  //bool getFlag1();
  //bool getFlag3();
};

#endif DSL_TILESET_H

//