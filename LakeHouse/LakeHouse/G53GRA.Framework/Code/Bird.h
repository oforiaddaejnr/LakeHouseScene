#pragma once
#include "DisplayableObject.h"
#include "Animation.h"
class Bird:
	public DisplayableObject,
	public Animation
{
public:
	Bird();
	~Bird() {};
	void Display();
	void Update(const double& deltaTime);
private:
	void drawBird();
	void drawBody();
	void drawHead();
	void drawNeck();
	void drawWing();
	void drawTail();
	void drawBeak();
	void drawLeg();
	void drawTalons();
	float rwAngle; //right wing angle
	float lwAngle; //left wing angle
	float height; //move bird up
	int keyframe = 0; //keyframe
};

