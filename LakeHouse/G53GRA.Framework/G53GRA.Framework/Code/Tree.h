#pragma once
#define _USE_MATH_DEFINES
#include "DisplayableObject.h"
#include <cmath>
#include <string>
#include <vector>;
using namespace std;
class Tree :
	public DisplayableObject //making tree a displayable object
{
public:
    Tree();                                 // constructor
    ~Tree() { };                            // destructor
    void Display();                         // overloaded virtual display function
    void addReplaceString(char flag, string str);
    void setReplaceString(char flag, string str);
    void setNumIter(unsigned int num);
    void setInitString(string str);
    string sequence = "ff-[-& f + ff + < + f] + [+>f--f&-f]"; //sequence to draw tree
    float angle = 22.5f;
private:
    void branch();       // draw branch function
    void getSequence();  // obtain sequence for drawing tree         
    int iter = 3;
    string init = "f";
    vector<string> change;
    vector<char> flags;
    bool toTexture = true;
    GLuint bark = Scene::GetTexture("./Textures/bark.bmp");
 
};

