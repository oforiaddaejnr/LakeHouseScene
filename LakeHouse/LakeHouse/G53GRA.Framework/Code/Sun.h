#pragma once

#include "DisplayableObject.h"
#include "Animation.h"

#include <cmath>

class Sun :
	public DisplayableObject,
	public Animation
{
public:
	Sun();
	~Sun() {};
	void Display();
	void Update(const double& deltaTime);
	
private:
	
	double _runtime;
	
	double _radius; //radius to move sun about

	GLfloat* _ambient, * _diffuse, * _specular;

	GLfloat _light; //variable to decide if I want point or directional light
};

