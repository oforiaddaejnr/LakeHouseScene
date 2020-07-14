#pragma once
#include "DisplayableObject.h"

class Path:
	public DisplayableObject
{
public:
	Path();
	~Path() {};
	void Display();
private:
	void drawPath();
	GLuint path = Scene::GetTexture("./Textures/gravel.bmp"); //path texture
};

