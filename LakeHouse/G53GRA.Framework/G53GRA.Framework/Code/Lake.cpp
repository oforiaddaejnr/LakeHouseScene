#include "Lake.h"

Lake::Lake()
{

}

void Lake::Display()
{
	glPushMatrix();
	glPushAttrib(GL_ALL_ATTRIB_BITS);
	glTranslatef(pos[0], pos[1], pos[2]);
	glScalef(scale[0], scale[1], scale[2]);
	glColor3f(0.0f, 0.5f, 1.0f); //baby blue color
	drawLake();
	glPopAttrib();
	glPopMatrix();
}

void Lake::drawLake()
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, lake); //bind lake texture
	glBegin(GL_QUADS);
	water_move += 0.001;
	if (water_move > 1) {
		water_move = 0;
	}
	glNormal3f(0.f, 1.f, 0.f);
	//simuate water flow movement by moving texture bit by bit
	glTexCoord2f(1.f + water_move, 0.f); glVertex3f(15.f, 0.f, 0.f);
	glTexCoord2f(1.f + water_move, 1.f); glVertex3f(15.f, 0.f, -5.f);
	glTexCoord2f(0.f + water_move, 1.f); glVertex3f(0.f, 0.f, -5.f);
	glTexCoord2f(0.f + water_move, 0.f); glVertex3f(0.f, 0.f, 0.f);
	glEnd();
	glDisable(GL_TEXTURE_2D);
}