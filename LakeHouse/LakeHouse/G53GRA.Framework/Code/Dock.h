#pragma once
#include "DisplayableObject.h"
class Dock:
	public DisplayableObject
{
public:
	Dock(); //constructor
	~Dock() {}; //deconstrutor
	void Display();
private:
	void drawDock(); 
	void drawBoard();
	void drawLeg();
	GLuint dock = Scene::GetTexture("./Textures/dockwood.bmp"); //texture

};

