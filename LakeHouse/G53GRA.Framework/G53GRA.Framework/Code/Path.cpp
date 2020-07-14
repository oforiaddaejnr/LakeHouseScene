#include "Path.h"
Path::Path()
{

}

void Path::Display()
{
	glPushMatrix();
	glTranslatef(pos[0], pos[1], pos[2]);
	glScalef(scale[0], scale[1], scale[2]);
	drawPath();
	glPopMatrix();
}

void Path::drawPath()
{
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, path); //bind path texture
	glBegin(GL_QUADS);
	glNormal3f(0.f, 1.f, 0.f);
	glTexCoord2f(1.f, 0.f); glVertex3f(5.f, 0.f, 0.f);
	glTexCoord2f(1.f, 1.f); glVertex3f(5.f, 0.f, -20.f);
	glTexCoord2f(0.f, 1.f); glVertex3f(3.f, 0.f, -20.f);
	glTexCoord2f(0.f, 0.f); glVertex3f(3.f, 0.f, 0.f);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}