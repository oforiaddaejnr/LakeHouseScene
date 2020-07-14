#include "StreetLamp.h"
StreetLamp::StreetLamp()
{
}

void StreetLamp::Display()
{
	glPushMatrix();
		
		glPushAttrib(GL_ALL_ATTRIB_BITS);
		glTranslatef(pos[0], pos[1], pos[2]);
		glScalef(scale[0], scale[1], scale[2]);
		drawBase();

		glPopAttrib();
	glPopMatrix();
}

void StreetLamp::drawBase() 
{
	glPushMatrix();
	glTranslatef(0.f, -1.f, 0.f); //move base position down
	glScalef(1.f, 0.2f, 1.f);
	glutSolidCube(1.f);
		glPushMatrix(); //push unto stack an draw pole in relation to the base
		glTranslatef(0.f, 7.f, 0.f);
		drawPole();
		glPopMatrix();
	glPopMatrix();
}

void StreetLamp::drawPole()
{
	glPushMatrix();
	glTranslatef(0.f, 13.f, 0.f);
	glScalef(0.3f, 40.f, 0.5f);
	glutSolidCube(1.f);
		glPushMatrix();//push unto stack an draw disc in relation to the base
		glTranslatef(0.1f, 0.5f, 1.f);
		drawDisc();
		glPopMatrix();
	glPopMatrix();
}

void StreetLamp::drawDisc()
{
	glPushMatrix();
	glScalef(1.f, 0.005f, 1.f);
	glutSolidCube(5.f);
		glPushMatrix();//push unto stack an draw light buld in relation to the base
		glTranslatef(0.f, -11.f, 1.f);
		drawLight();
		glPopMatrix();
	glPopMatrix();
}

void StreetLamp::drawLight()
{
	
	glPushMatrix();
	glDisable(GL_COLOR_MATERIAL);
	static GLfloat ambient[] = { 0.15f, 0.15f, 0.1f, 1.0f };

	// Set diffuse colour of the light (yellow)
	static GLfloat diffuse[] = { 1.f, 1.f, 0.0f, 1.0f };

	// Set specular colour (white)
	static GLfloat specular[] = { 0.0f, 0.0f, 0.0f, 1.0f };

	_ambient = ambient;
	_diffuse = diffuse;
	_specular = specular;
	glPushAttrib(GL_ALL_ATTRIB_BITS);       // save current style attributes (inc. material properties)
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, _ambient); // set colour for ambient reflectance
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, _diffuse);  // set colour for diffuse reflectance
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, _specular);   // set colour for specular reflectance 
	glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, _diffuse); //set emission color to yellow
	glScalef(1.f, 6.0f, 0.5f);
	glutSolidSphere(2.f, 50, 10);
	glPopMatrix();
	glEnable(GL_COLOR_MATERIAL);
	glPopAttrib();
	
}
