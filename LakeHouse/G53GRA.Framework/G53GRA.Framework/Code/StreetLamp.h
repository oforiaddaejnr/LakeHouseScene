#pragma once
#include "DisplayableObject.h"

class StreetLamp : 
	public DisplayableObject

{
public:
	StreetLamp();
	~StreetLamp() {};
	void Display();

private:
	void drawBase();
	void drawPole();
	void drawDisc();
	void drawLight();
	GLfloat* _ambient, * _diffuse, * _specular;
};

