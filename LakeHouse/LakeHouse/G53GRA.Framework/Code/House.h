#pragma once
#include "DisplayableObject.h"


class House :
	public DisplayableObject
{
public:
	House();
	~House() {};
	void Display();
private:
	void drawHouse();
	void drawBody();
	void drawDoor();
	void drawRoof();
	GLuint house = Scene::GetTexture("./Textures/housewood.bmp"); //house body and roof texture
	GLuint door = Scene::GetTexture("./Textures/doorwood.bmp"); //door texture

};

