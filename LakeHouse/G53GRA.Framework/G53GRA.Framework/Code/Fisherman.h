#pragma once
#include "DisplayableObject.h"
#include "Animation.h"

class Fisherman:
	public DisplayableObject,
	public Animation
{
public:
	Fisherman();
	~Fisherman() {};
	void Display();
	void Update(const double& deltaTime);

private:
	void drawTorso();
	void drawHead();
	void drawArm();
	void drawHand();
	void drawThigh();
	void drawLeg();
	void drawFishingSpear();
	float rotateArm = -120.f; //angle arm is originally in
	int keyframe = 0; //keyframe
};

