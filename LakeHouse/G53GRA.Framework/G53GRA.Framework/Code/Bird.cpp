#include "Bird.h"
Bird::Bird()
{

}

void Bird::Display()
{
	
	glPushMatrix();
		glPushAttrib(GL_ALL_ATTRIB_BITS); //save and all attributes to bird object
		glColor3f(0.f, 0.f, 1.f); //blue color
		glTranslatef(pos[0], pos[1] + height, pos[2]);
		glScalef(scale[0], scale[1], scale[2]);
		drawBird();
		glPopAttrib();
	glPopMatrix();
}

void Bird::drawBird()
{

	glPushMatrix();
	glTranslatef(0.f, 1.f, 0.f); // move bired position up one
	drawBody(); //draw the round body of bird
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-3.0f, 4.5f, 0.f); //move neck position back and up
	glRotatef(-30.f, 0.f, 0.f, 1.f); //rotate position 30 degrees forward in the z-axis
	drawNeck(); // draw neck
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-6.f, 2.f, -0.5f); //move tail position back
	glRotatef(-45.f, 0.f, 0.f, 1.f); // rotate tail position 45 degrees forward in the z-axis
	drawTail(); //draw tail
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-3.5f, 1.f, 0.f);
	//draw right wing
	drawWing();
	glPopMatrix();

	
	glPushMatrix();
	glTranslatef(-3.5f, 1.f, -4.f);
	//draw left wing
	drawWing();
	glPopMatrix();

	//draw right leg
	glPushMatrix();
	glTranslatef(1.f, -1.f, 1.f);
	glRotatef(45.f, 0.f, 0.f, 1.f);
	drawLeg();
	glPopMatrix();

	//draw right talon
	glPushMatrix();
	glTranslatef(-3.f, 0.3f, 1.72f);
	drawTalons();
	glPopMatrix();

	//draw left leg
	glPushMatrix();
	glTranslatef(1.f, -1.f, -1.5f);
	glRotatef(45.f, 0.f, 0.f, 1.f);
	drawLeg();
	glPopMatrix();

	//draw left talon
	glPushMatrix();
	glTranslatef(-3.f, 0.3f, -0.78f);
	drawTalons();
	glPopMatrix();

}

void Bird::drawBody()
{
	glPushMatrix();
	glTranslatef(-4.f, 1.f, 0.f);
	glutSolidSphere(2.f, 10, 10);
	glPopMatrix();
}


void Bird::drawNeck()
{
	glPushMatrix();
	glScalef(0.2f, 1.f, 0.2f);
	glutSolidCube(2.5);
		glPushMatrix(); //push unto a stack and stack drawing the head in relation to the neck
		glTranslatef(1.f, 1.f, 0.f);
		drawHead();
		glPopMatrix();
	glPopMatrix();
}

void Bird::drawHead()
{
	glPushMatrix();
	glScalef(2.5f, 0.5f, 2.5f);
	glutSolidSphere(2.5f, 10, 10);
		glPushMatrix();
		glTranslatef(1.f, 0.f, 0.f);
		glRotatef(90.f, 0.f, 1.f, 0.f); //push unto a stack and start drawing beak in realtion to the head
		drawBeak();
		glPopMatrix();
	glPopMatrix();
}


void Bird::drawWing()
{
	glPushMatrix();
	glDisable(GL_CULL_FACE); //disable, so we can see other side of the wind when we change camera view
		glBegin(GL_TRIANGLES);
		glVertex3f(1.f, 1.f, 2.f);
		glVertex3f(0.f, 2.f, 2.f);
		glVertex3f(-3.f, -3.f, 2.f);
		glEnd();
	glEnable(GL_CULL_FACE);
	glPopMatrix();
}

void Bird::drawTail()
{
	glPushMatrix();
	glDisable(GL_CULL_FACE); //disable, so we can see other side of the wind when we change camera view
		glBegin(GL_TRIANGLES);
		glVertex3f(1.f, 1.f, 0.5f);
		glVertex3f(0.f, -2.f, 2.f);
		glVertex3f(0.f, -2.f, -1.5f);
		glEnd();
	glEnable(GL_CULL_FACE);
	glPopMatrix();
}

void Bird::drawBeak()
{
	glPushMatrix();
	glPushAttrib(GL_ALL_ATTRIB_BITS);
	glColor3f(1.f, 1.f, 0.f); //yellow
	glutSolidCone(2, 5, 10, 10);
	glPopAttrib();
	glPopMatrix();
}

void Bird::drawLeg()
{
	glPushMatrix();
	glTranslatef(-2.f, 4.5f, 0.2f);
	glScalef(0.2f, 1.5f, 0.2f);
	glutSolidCube(1.f);
	glPopMatrix();
}

void Bird::drawTalons()
{
	//draw three cubes to represent the talons of the bird
	glPushMatrix();
	glPushAttrib(GL_ALL_ATTRIB_BITS);
	glColor3f(1.f, 1.f, 0.f); //yellow
	glTranslatef(0.f, 0.f, -0.5f);
	glRotatef(-45.f, 0.f, 1.f, 0.f);
	glScalef(0.5f, 0.2, 0.2f);
	glutSolidCube(0.5f);
	glPopAttrib();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.f, 0.f, -0.55f);
	glScalef(0.5f, 0.2, 0.2f);
	glutSolidCube(0.5f);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.f, 0.f, -0.6f);
	glRotatef(45.f, 0.f, 1.f, 0.f);
	glScalef(0.5f, 0.2, 0.2f);
	glutSolidCube(0.5f);
	glPopMatrix();
}

void Bird::Update(const double& deltaTime)
{
	//make the baby bird jump up and down
	if (keyframe == 0)
	{
	
		height = 0;
		keyframe = 1;

	}

	else if (keyframe == 1) {
		rwAngle = 0.f;
		lwAngle = 0.f;
		keyframe = 2;
		height = 50.f;
	}

	else if (keyframe == 2) {
		
		keyframe = 3;
		height = 25.f;
	}

	else if (keyframe == 3) {
		keyframe = 0;
	}

}
