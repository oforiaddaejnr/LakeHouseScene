#pragma once

#define _USE_MATH_DEFINES
#include "DisplayableObject.h"
#include "Animation.h"

class Kid:
	public DisplayableObject,
	public Animation
{
public:
	Kid(); //constructor
	~Kid() {}; //deconstructor
	void Display();
	void Update(const double& deltaTime);

private:
	void drawTorso();
	void drawHead();
	void drawArm();
	void drawHand();
	void drawThigh();
	void drawLeg();
	float rightThighRot = 45.f; 
	float leftThighRot = -45.f;			//thigh angles
	int keyframe = 0;               // variable to track which keyframe we are on
	double _runtime = 0.0;
	double _radius = 800.0;  //radius to run around
	float rotKid = 45.f;

	float res = 0.1f * M_PI;

	float t = 0.f;                          // initialise angle as 0

	float x = _radius, z = 0.f;

};

