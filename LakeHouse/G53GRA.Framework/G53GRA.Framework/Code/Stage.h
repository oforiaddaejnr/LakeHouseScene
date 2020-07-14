#pragma once

#include "DisplayableObject.h"

class Stage :
	public DisplayableObject
{
public:
	Stage();
	~Stage() {};
	void Display();
private:
	void drawStage();
	//skybox textures
	GLuint skybox_back = Scene::GetTexture("./Textures/skybox_back.bmp");
	GLuint skybox_down = Scene::GetTexture("./Textures/skybox_down.bmp");
	GLuint skybox_front = Scene::GetTexture("./Textures/skybox_front.bmp");
	GLuint skybox_left = Scene::GetTexture("./Textures/skybox_left.bmp");
	GLuint skybox_right = Scene::GetTexture("./Textures/skybox_right.bmp");
	GLuint skybox_up = Scene::GetTexture("./Textures/skybox_up.bmp");
};

