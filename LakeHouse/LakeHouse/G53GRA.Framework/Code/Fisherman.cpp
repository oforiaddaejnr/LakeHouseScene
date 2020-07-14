#include "Fisherman.h"

Fisherman::Fisherman()
{

}

void Fisherman::Display()
{
	glPushMatrix();

	glPushAttrib(GL_ALL_ATTRIB_BITS);
	glTranslatef(pos[0], pos[1], pos[2]);
	glScalef(scale[0], scale[1], scale[2]);
	drawTorso();

	glPopAttrib();
	glPopMatrix();
}


void Fisherman::drawTorso()
{
	glPushMatrix();

	glTranslatef(5.f, 0.f, 5.f); //move torso up and forward
	glBegin(GL_QUADS);
	//draw front of torso
	glNormal3f(0.f, 0.f, 1.f);
	glVertex3f(2.f, 2.f, 2.f);
	glVertex3f(2.f, 0.f, 2.f);
	glVertex3f(4.f, 0.f, 2.f);
	glVertex3f(4.f, 2.f, 2.f);

	//draw right torso
	glNormal3f(1.f, 0.f, 0.f);
	glVertex3f(4.f, 2.f, 2.f);
	glVertex3f(4.f, 0.f, 2.f);
	glVertex3f(4.f, 0.f, 0.5f);
	glVertex3f(4.f, 2.f, 0.5f);

	//draw left torso
	glNormal3f(-1.f, 0.f, 0.f);
	glVertex3f(2.f, 2.f, 2.f);
	glVertex3f(2.f, 2.f, 0.5f);
	glVertex3f(2.f, 0.f, 0.5f);
	glVertex3f(2.f, 0.f, 2.f);

	//draw back torso
	glNormal3f(0.f, 0.f, -1.f);
	glVertex3f(4.f, 0.f, 0.5f);
	glVertex3f(2.f, 0.f, 0.5f);
	glVertex3f(2.f, 2.f, 0.5f);
	glVertex3f(4.f, 2.f, 0.5f);

	//draw top torso
	glNormal3f(0.f, 1.f, 0.f);
	glVertex3f(2.f, 2.f, 2.f);
	glVertex3f(4.f, 2.f, 2.f);
	glVertex3f(4.f, 2.f, 0.5f);
	glVertex3f(2.f, 2.f, 0.5f);

	//draw bottom torso
	glNormal3f(0.f, -1.f, 0.f);
	glVertex3f(4.f, 0.f, 2.f);
	glVertex3f(2.f, 0.f, 2.f);
	glVertex3f(2.f, 0.f, 0.5f);
	glVertex3f(4.f, 0.f, 0.5f);


	glEnd();

	glPushMatrix();
	//draw head
	glTranslatef(0.f, 3.f, 0.f);
	drawHead();
	glPopMatrix();

	glPushMatrix();
	//draw right arm
	glTranslatef(4.2f, 1.f, 1.f);
	drawArm();
	glPopMatrix();


	//draw left arm
	glPushMatrix();
	glTranslatef(1.8f, 1.f, 2.f);
	glRotatef(rotateArm, 1.f, 0.f, 0.f); //rortae arm and an ange
	drawArm();
	glPushMatrix(); //push unto stack draw fishing spear in relation to arm
	glTranslatef(0.f, -0.7f, -2.f);
	glRotatef(-180.f, 1.f, 0.f, 0.f);
	drawFishingSpear();
	glPopMatrix();
	glPopMatrix();

	//draw left thigh
	glPushMatrix();
	glTranslatef(2.5f, -0.5f, 1.2f);
	drawThigh();
	glPopMatrix();

	//draw right thigh
	glPushMatrix();
	glTranslatef(3.5f, -0.5f, 1.2f);
	drawThigh();
	glPopMatrix();
	//draw right leg

	//draw left leg
	glPopMatrix();
}

void Fisherman::drawHead()
{
	glPushMatrix();
	glTranslatef(3.f, -0.7f, 1.3f); //move head position up and forward
	glScalef(0.1f, 0.1f, 0.1f);
	glutSolidSphere(5.f, 50.f, 50.f);
	glPopMatrix();
}

void Fisherman::drawArm()
{
	glPushMatrix();
	glScalef(0.5f, 1.5f, 0.5f);
	glutSolidCube(1.f);
	//draw hand
	glPushMatrix(); //push unto stack and draw hand in relation to the arm
	glTranslatef(0.f, -0.5f, 0.f);
	drawHand();
	glPopMatrix();
	glPopMatrix();
}


void Fisherman::drawHand()
{
	glPushMatrix();
	glScalef(0.5f, 0.2f, 0.5f);
	glutSolidCube(1.f);
	glPopMatrix();
}

void Fisherman::drawThigh()
{
	glPushMatrix();
	glScalef(1.f, 1.5f, 1.f);
	glutSolidCube(1.f);
	//draw leg
	glPushMatrix(); //push unto stack and draw leg in relation to the thigh
	glTranslatef(0.f, -0.8f, 0.f);
	drawLeg();
	glPopMatrix();
	glPopMatrix();
}

void Fisherman::drawLeg()
{
	glPushMatrix();
	glScalef(0.5f, 1.f, 0.5f);
	glutSolidCube(1.f);
	glPopMatrix();
}

void Fisherman::drawFishingSpear()
{
	//draw pole
	glPushMatrix();
	glScalef(0.2f, 0.2f, 10.f);
	glutSolidCube(1.f);
	glPopMatrix();

	//draw sharp edge of spear
	glPushMatrix();
	glTranslatef(0.f, 0.f, 5.f);
	glScalef(0.15, 0.15f, 0.15f);
	glutSolidCone(2, 5, 10, 10);
	glPopMatrix();
}

void Fisherman::Update(const double& deltaTime)
{


	if(keyframe == 0) //stage 0
	{
		rotateArm = -120.f;
		keyframe = 1;

	}

	else if (keyframe == 1) //stage 1
	{
		rotateArm = -115.f;
		keyframe = 2;
	}

	else if (keyframe == 2) //stage 2
	{
		rotateArm = -110.f;
		keyframe = 3;
	}

	else if (keyframe == 3) //stage 3
	{
		rotateArm = -105.f;
		keyframe = 4;
	}

	else if (keyframe == 4) //stage 4
	{
		rotateArm = -100.f;
		keyframe = 5;
	}

	else if (keyframe == 5) //stage 5
	{
		rotateArm = -95.f;
		keyframe = 0; //return back to stage 0
	}

}