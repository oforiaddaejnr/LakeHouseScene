#include "Sun.h"

Sun::Sun()
	: _runtime(0.0), _radius(50.0), _light(0.0f) //make light directional
{
	static GLfloat ambient[] = { 0.2f, 0.2f, 0.2f, 1.0f }; //set ambience

	static GLfloat diffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f }; //set diffuse

	static GLfloat specular[] = { 1.0f, 1.0f, 1.0f, 1.0f }; //set specular

	

	_ambient = ambient;
	_diffuse = diffuse;
	_specular = specular;
	
}


void Sun::Display()
{

	if (_light)
	{
		// Disable lighting on this geometry (since it is the source
		// of the light)
		glDisable(GL_LIGHTING);

		glPushMatrix();
		glPushAttrib(GL_ALL_ATTRIB_BITS);
		// Match colour of sphere to diffuse colour of light
		glColor4fv(_diffuse);
		glTranslatef(pos[0], pos[1], pos[2]);
		glScalef(5.f, 5.f, 5.f);
		glutSolidSphere(20.0, 20, 20);
		glPopAttrib();
		glPopMatrix();
		// Re-enable lighting after light source has been drawn
		glEnable(GL_LIGHTING);
	}
}

void Sun::Update(const double& deltaTime)
{
	_runtime += deltaTime;

	pos[0] = static_cast<float>(_radius * cos(_runtime)); //update x-axis position of sun based on run time
	pos[1] = static_cast<float>(_radius * sin(_runtime)); //update y-axis position of sun based on run time

	glEnable(GL_LIGHTING);


	// Set properties GL_LIGHT0 (overwrites default global framework lighting)
	glLightfv(GL_LIGHT0, GL_AMBIENT, _ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, _diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, _specular);

	GLfloat lPosition[4] = { pos[0], pos[1], pos[2], _light };
	glLightfv(GL_LIGHT0, GL_POSITION, lPosition);

	// enable GL_LIGHT0 with these defined properties
	glEnable(GL_LIGHT0);
}

