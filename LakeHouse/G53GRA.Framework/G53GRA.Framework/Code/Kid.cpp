#include "Kid.h"

Kid::Kid()
{
}

void Kid::Display() 
{
	glPushMatrix();

		glPushAttrib(GL_ALL_ATTRIB_BITS);
		glRotatef(rotKid, rotation[0], rotation[1], rotation[2]);
		glTranslatef(pos[0]-x, pos[1], pos[2]-z);
		glScalef(scale[0], scale[1], scale[2]);
		drawTorso();

	glPopAttrib();
	glPopMatrix();
}

void Kid::drawTorso()
{
	glPushMatrix();

		glTranslatef(5.f, 0.f, 5.f); //move torso position up and forward
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
		glTranslatef(0.f, 3.f, 0.f); //move head position up
		drawHead();
		glPopMatrix();

		glPushMatrix();
		//draw right arm
		glTranslatef(4.2f, 1.f, 1.2f); //move arm right and forward
		drawArm();
		glPopMatrix();


		//draw left arm
		glPushMatrix();
		glTranslatef(1.8f, 1.f, 1.2f); //move arm left and forward
		drawArm();
		glPopMatrix();

		//draw left thigh
		glPushMatrix();
		glTranslatef(2.5f, -0.5f, 1.2f); //move thigh down, left, and forward
		glRotatef(leftThighRot, 1.f, 0.f, 0.f);
		drawThigh();
		glPopMatrix();

		//draw right thigh
		glPushMatrix();
		glTranslatef(3.5f, -0.5f, 1.2f); //move thigh down, right, and forward
		glRotatef(rightThighRot, 1.f, 0.f, 0.f);
		drawThigh();
		glPopMatrix();
		
	glPopMatrix();
}

void Kid::drawHead()
{
	glPushMatrix();
	glTranslatef(3.f, -0.7f, 1.3f); //move head position up and front
	glScalef(0.1f, 0.1f, 0.1f);
	glutSolidSphere(5.f, 50.f, 50.f);
	glPopMatrix();
}

void Kid::drawArm()
{
	glPushMatrix();
	glScalef(0.5f, 1.5f, 0.5f); 
	glutSolidCube(1.f);
		//draw hand
		glPushMatrix();
		glTranslatef(0.f, -0.5f, 0.f);
		drawHand();
		glPopMatrix();
	glPopMatrix();
}


void Kid::drawHand() 
{
	glPushMatrix();
	glScalef(0.5f, 0.2f, 0.5f);
	glutSolidCube(1.f);
	glPopMatrix();
}

void Kid::drawThigh()
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

void Kid::drawLeg()
{
	glPushMatrix();
	glScalef(0.5f, 1.f, 0.5f);
	glutSolidCube(1.f);
	glPopMatrix();
}

void Kid::Update(const double& deltaTime)
{
	//make kid run in circles
	do
	{             
	
		// Iterate around circle
		t += res;                       // add increment to angle
		x = _radius * cos(t);		// move x and z around circle
		z = _radius * sin(t);
	
	} while (t <= 2 * M_PI);                // full rotation around circle

	//move legs back and forth
	if (keyframe == 0)
	{
		leftThighRot = 45.f;
		rightThighRot = -45.f;
		keyframe = 1;

	}

	else if (keyframe == 1) {
		leftThighRot = -45.f;
		rightThighRot = 45.f;
		keyframe = 0;
	}

}
