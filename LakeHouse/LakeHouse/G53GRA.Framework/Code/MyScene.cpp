#define _USE_MATH_DEFINES
#include "MyScene.h"
#include "Tree.h"
#include "Dock.h"
#include "Kid.h"
#include "StreetLamp.h"
#include "Bird.h"
#include "Deer.h"
#include "House.h"
#include "Fisherman.h"
#include "Stage.h"
#include "Path.h"
#include "Lake.h";
#include "Sun.h";

MyScene::MyScene(int argc, char** argv, const char *title, const int& windowWidth, const int& windowHeight)
	: Scene(argc, argv, title, windowWidth, windowHeight)
{

}

void MyScene::Initialise()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); //set background colour to black
	//glClearColor(1.f, 1.f, 1.f, 1.f);     // set background colour to white

	//Initialize objects and add to scene here
	int xspace = 0;
	for (int i = 0; i < 3; i++) 
	{
		Tree* t = new Tree(); //creating tree displayable object to add to scene
		t->setReplaceString('f', "ff-[-& f + ff + < + f] + [+>f--f&-f]");
		t->position(-320.f + xspace, -150.f, -2500.f);
		t->size(80.f);
		AddObjectToScene(t);
		xspace -= 300;
	}

	for (int i = 0; i < 3; i++)
	{
		Tree* t = new Tree(); //creating tree displayable object to add to scene
		t->setReplaceString('f', "ff-[-& f + ff + < + f] + [+>f--f&-f]");
		t->position(2000.f + xspace, -150.f, -2500.f);
		t->size(80.f);
		AddObjectToScene(t);
		xspace += 300;
	}


	Dock* d = new Dock(); //creating dock displayable object to add to scene
	d->position(220.f, -100.f, 1000.f);
	d->size(50.f);
	AddObjectToScene(d);

	Kid* kid = new Kid();
	kid->position(600.f, -50.f, -1000.f);
	kid->size(50.f);
	kid->orientation(0.f, 1.f, 0.f);
	AddObjectToScene(kid);

	

	Fisherman* fisherman = new Fisherman();
	fisherman->position(-50.f, 175.f, 700.f);
	fisherman->size(50.f);
	AddObjectToScene(fisherman);

	StreetLamp* sl = new StreetLamp();
	sl->position(-150.f, -80.f, -2500.f);
	sl->size(60.f);
	AddObjectToScene(sl);

	Bird* birdy = new Bird();
	birdy->position(-450.f, -130.f, -2500.f);
	birdy->size(6.f);
	AddObjectToScene(birdy);

	Deer* deer = new Deer();
	deer->position(-1000.f, -210.f, 800.f);
	deer->size(60.f);
	deer->setReplaceString('f', "f-[-& f < + f] + [+>f-f&f]");
	AddObjectToScene(deer);


	House* h = new House();
	h->position(0.f, -150.f, -3000.f);
	h->size(100.f);
	AddObjectToScene(h);

	Path* p = new Path();
	p->position(0.f, -145.f, 100.f);
	p->size(100.f);
	AddObjectToScene(p);

	Lake* l = new Lake();
	l->position(-3400.f, -145.f, 3300.f);
	l->size(452.f);
	AddObjectToScene(l);

	Sun* s = new Sun();
	AddObjectToScene(s);

	Stage* sb = new Stage();
	float camrad = ((windowHeight) / 2.f) / tan(M_PI / 8.f);
	sb->size(camrad * 7, camrad*5, camrad*7);
	AddObjectToScene(sb);


}

void MyScene::Projection()
{
	GLdouble aspect = static_cast<GLdouble>(windowWidth) / static_cast<GLdouble>(windowHeight);
	gluPerspective(60.0, aspect, 1.0, 10500.0);
}
