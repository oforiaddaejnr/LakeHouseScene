#pragma once
#define _USE_MATH_DEFINES
#include "DisplayableObject.h"
#include "Animation.h"
#include <string>
#include <cmath>
#include <vector>;

using namespace std;

class Deer:
	public DisplayableObject,
	public Animation
{
public:
	Deer();
	~Deer() {};
	void Display();
	void addReplaceString(char flag, string str); //replace string for drawing antlers
	void setReplaceString(char flag, string str); // set string for drawing antlers
	void setNumIter(unsigned int num); // number of iterations
	void setInitString(string str);
	string sequence = "ff-[-& f + ff + < + f] + [+>f--f&-f]"; //sequence for drawing antlers
	float angle = 22.5f; //angle to draw branches at
	void Update(const double& deltaTime);
	float aT = 0;

private:
	void drawDeer();
	void drawBody();
	void drawLeg();
	void drawNeck();
	void drawHead();
	void drawAntlers();
	void branch();                          // draw branch function
	void getSequence();
	int iter = 2;
	string init = "f";
	vector<string> change;
	vector<char> flags;
	GLuint fur = Scene::GetTexture("./Textures/deer.bmp"); //deer texture
	float animationTime;                        // number of seconds in animation cycle
	float nangle;                       // neck angles

	
};

