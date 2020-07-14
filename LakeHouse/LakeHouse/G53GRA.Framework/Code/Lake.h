#pragma once
#include "DisplayableObject.h"

class Lake:
	public DisplayableObject
{
public:
	Lake();
	~Lake() {};
	void Display();

private:
	void drawLake();
	GLuint lake = Scene::GetTexture("./Textures/water.bmp"); //lake texture
	float water_move = 0;
};

