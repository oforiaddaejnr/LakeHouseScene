#include "Stage.h"

Stage::Stage()
{
}

void Stage::Display()
{
	glPushMatrix();
	glTranslatef(0.f, -150.f, 0.f);
	glScalef(scale[0], scale[1], scale[2]);
	drawStage();
	glPopMatrix();

}

void Stage::drawStage()
{
	glEnable(GL_TEXTURE_2D);
	glColor4f(1.f, 1.f, 1.f, 1.f);
	
	// NEAR SIDE
	glBindTexture(GL_TEXTURE_2D, skybox_front);
	glBegin(GL_QUADS);
	glTexCoord2f(1.f, 1.f); glVertex3f(-1.f, 1.f, 1.f);
	glTexCoord2f(0.f, 1.f); glVertex3f(1.f, 1.f, 1.f);
	glTexCoord2f(0.f, 0.f); glVertex3f(1.f, 0.f, 1.f);
	glTexCoord2f(1.f, 0.f); glVertex3f(-1.f, 0.f, 1.f);
	glEnd();
	// FAR SIDE
	glBindTexture(GL_TEXTURE_2D, skybox_back);
	glBegin(GL_QUADS);
	glTexCoord2f(1.f, 1.f); glVertex3f(1.f, 1.f, -1.f);
	glTexCoord2f(0.f, 1.f); glVertex3f(-1.f, 1.f, -1.f);
	glTexCoord2f(0.f, 0.f); glVertex3f(-1.f, 0.f, -1.f);
	glTexCoord2f(1.f, 0.f); glVertex3f(1.f, 0.f, -1.f);
	glEnd();
	// BOTTOM SIDE
	glBindTexture(GL_TEXTURE_2D, skybox_down);
	glBegin(GL_QUADS);
	glTexCoord2f(1.f, 1.f); glVertex3f(-1.f, 0.f, 1.f);
	glTexCoord2f(0.f, 1.f); glVertex3f(1.f, 0.f, 1.f);
	glTexCoord2f(0.f, 0.f); glVertex3f(1.f, 0.f, -1.f);
	glTexCoord2f(1.f, 0.f); glVertex3f(-1.f, 0.f, -1.f);
	glEnd();

	// TOP SIDE
	glBindTexture(GL_TEXTURE_2D, skybox_up);
	glBegin(GL_QUADS);
	glTexCoord2f(0.f, 0.f); glVertex3f(1.f, 1.f, 1.f);
	glTexCoord2f(1.f, 0.f); glVertex3f(-1.f, 1.f, 1.f);
	glTexCoord2f(1.f, 1.f); glVertex3f(-1.f, 1.f, -1.f);
	glTexCoord2f(0.f, 1.f); glVertex3f(1.f, 1.f, -1.f);
	glEnd();

	// LEFT SIDE
	glBindTexture(GL_TEXTURE_2D, skybox_right);
	glBegin(GL_QUADS);
	glTexCoord2f(1.f, 1.f); glVertex3f(-1.f, 1.f, -1.f);
	glTexCoord2f(0.f, 1.f); glVertex3f(-1.f, 1.f, 1.f);
	glTexCoord2f(0.f, 0.f); glVertex3f(-1.f, 0.f, 1.f);
	glTexCoord2f(1.f, 0.f); glVertex3f(-1.f, 0.f, -1.f);
	glEnd();

	// RIGHT SIDE
	glBindTexture(GL_TEXTURE_2D, skybox_left);
	glBegin(GL_QUADS);
	glTexCoord2f(1.f, 1.f); glVertex3f(1.f, 1.f, 1.f);
	glTexCoord2f(0.f, 1.f); glVertex3f(1.f, 1.f, -1.f);
	glTexCoord2f(0.f, 0.f); glVertex3f(1.f, 0.f, -1.f);
	glTexCoord2f(1.f, 0.f); glVertex3f(1.f, 0.f, 1.f);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	
}


