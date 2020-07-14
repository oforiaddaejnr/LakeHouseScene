#include "Dock.h"

Dock::Dock() 
{
}

void Dock::Display()
{
	glPushMatrix();
		glPushAttrib(GL_ALL_ATTRIB_BITS);
		glColor3f(0.58f, 0.27f, 0.21f); //set colour to brown
		glTranslatef(pos[0], pos[1], pos[2]);
		glScalef(scale[0], scale[1], scale[2]);
		drawDock();

		glPopAttrib();
	glPopMatrix();
}

void Dock::drawDock()
{

		glPushMatrix(); //save current state
		glTranslatef(0.f, 1.f, 0.f); //move draw position up
		drawBoard();
		glPopMatrix();

		//draw parts connected to the board

		glPushMatrix();
		glTranslatef(0.75f, 2.f, 0.5f); //move leg upfront and left
		drawLeg(); //draw left leg
		glPopMatrix();

		glPushMatrix();
		glTranslatef(4.75f, 2.f, 0.5f); // move next leg upfront and right
		drawLeg(); //draw right leg
		glPopMatrix();

		glPushMatrix();
		glTranslatef(4.75f, 2.f, -7.5f); // move next leg position to middle and right
		drawLeg(); //draw middle right leg
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0.75f, 2.f, -7.5f); // move next leg position to middle and left
		drawLeg(); //draw middle left leg
		glPopMatrix();

		glPushMatrix();
		glTranslatef(4.75f, 2.f, -14.5f); // move next leg position to back and right
		drawLeg(); //draw back right leg
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0.75f, 2.f, -14.5f); // move next leg position to middle and left
		drawLeg(); //draw back left leg
		glPopMatrix();


}

void Dock::drawBoard() 
{
	glTranslatef(3.f, 0.f, 0.f);
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, dock); //bind fur to board
		glBegin(GL_QUADS);
		//draw front of board
		glNormal3f(0.f, 0.f, 1.f);
		glTexCoord2f(1.f, 0.f); glVertex3f(2.5f, 1.5f, 1.f);
		glTexCoord2f(1.f, 1.f); glVertex3f(2.5f, 2.f, 1.f);
		glTexCoord2f(0.f, 1.f); glVertex3f(-2.5f, 2.f, 1.f);
		glTexCoord2f(0.f, 0.f); glVertex3f(-2.5f, 1.5f, 1.f);

		//draw right of board
		glNormal3f(1.f, 0.f, 0.f);
		glTexCoord2f(1.f, 1.f); glVertex3f(2.5f, 2.f, -15.f);
		glTexCoord2f(0.f, 1.f); glVertex3f(2.5f, 2.f, 1.f);
		glTexCoord2f(0.f, 0.f); glVertex3f(2.5f, 1.5f, 1.f);
		glTexCoord2f(1.f, 0.f); glVertex3f(2.5f, 1.5f, -15.f);

		//draw left of board
		glNormal3f(-1.f, 0.f, 0.f);
		glTexCoord2f(1.f, 1.f); glVertex3f(-2.5f, 2.f, 1.f);
		glTexCoord2f(0.f, 1.f); glVertex3f(-2.5f, 2.f, -15.f);
		glTexCoord2f(0.f, 0.f); glVertex3f(-2.5f, 1.5f, -15.f);
		glTexCoord2f(1.f, 0.f); glVertex3f(-2.5f, 1.5f, 1.f);

		//draw back of board
		glNormal3f(0.f, 0.f, -1.f);
		glTexCoord2f(0.f, 1.f); glVertex3f(2.5f, 2.f, -15.f);
		glTexCoord2f(0.f, 0.f); glVertex3f(2.5f, 1.5f, -15.f);
		glTexCoord2f(1.f, 0.f); glVertex3f(-2.5f, 1.5f, -15.f);
		glTexCoord2f(1.f, 1.f); glVertex3f(-2.5f, 2.f, -15.f);

		//draw top of board
		glNormal3f(0.f, 1.f, 0.f);
		glTexCoord2f(1.f, 0.f); glVertex3f(2.5f, 2.f, 1.f);
		glTexCoord2f(1.f, 1.f); glVertex3f(2.5f, 2.f, -15.f);
		glTexCoord2f(0.f, 1.f); glVertex3f(-2.5f, 2.f, -15.f);
		glTexCoord2f(0.f, 0.f); glVertex3f(-2.5f, 2.f, 1.f);

		//draw bottom of board
		glNormal3f(0.0f, -1.0f, 0.0f);
		glTexCoord2f(1.f, 0.f); glVertex3f(-2.5f, 1.5f, 1.f);
		glTexCoord2f(1.f, 1.f); glVertex3f(-2.5f, 1.5f, -15.f);
		glTexCoord2f(0.f, 1.f); glVertex3f(2.5f, 1.5f, -15.f);
		glTexCoord2f(0.f, 0.f); glVertex3f(2.5f, 1.5f, 1.f);

		glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}

void Dock::drawLeg()
{
	glTranslatef(0.f, -1.f, 0.f); //move leg below the board and to the left
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, dock); //bind fur to legs
		glBegin(GL_QUADS);

		//draw front of leg
		glNormal3f(0.f, 0.f, 1.f);
		glTexCoord2f(1.f, 0.f); glVertex3f(0.5f, 1.5f, 0.5f);
		glTexCoord2f(1.f, 1.f); glVertex3f(0.f, 1.5f, 0.5f);
		glTexCoord2f(0.f, 1.f); glVertex3f(0.f, -2.f, 0.5f);
		glTexCoord2f(0.f, 0.f); glVertex3f(0.5f, -2.f, 0.5f);

		//draw right of leg
		glNormal3f(1.f, 0.f, 0.f);
		glTexCoord2f(1.f, 1.f); glVertex3f(0.5f, 1.5f,-0.5f);
		glTexCoord2f(0.f, 1.f); glVertex3f(0.5f, 1.5f, 0.5f);
		glTexCoord2f(0.f, 0.f); glVertex3f(0.5f, -2.f, 0.5f);
		glTexCoord2f(1.f, 0.f); glVertex3f(0.5f, -2.f, -0.5f);

		//draw left of leg
		glNormal3f(-1.f, 0.f, 0.f);
		glTexCoord2f(1.f, 1.f); glVertex3f(0.f, 1.5f, 0.5f);
		glTexCoord2f(0.f, 1.f); glVertex3f(0.f, 1.5f, -0.5f);
		glTexCoord2f(0.f, 0.f); glVertex3f(0.f, -2.f, -0.5f);
		glTexCoord2f(1.f, 0.f); glVertex3f(0.f, -2.f, 0.5f);

		//draw back of leg
		glNormal3f(0.f, 0.f, -1.f);
		glTexCoord2f(0.f, 1.f); glVertex3f(0.5f, 1.5f, -0.5f);
		glTexCoord2f(0.f, 0.f); glVertex3f(0.5f, -2.f, -0.5f);
		glTexCoord2f(1.f, 0.f); glVertex3f(0.f, -2.f, -0.5f);
		glTexCoord2f(1.f, 1.f); glVertex3f(0.f, 1.5f, -0.5f);

		//draw top of leg
		glNormal3f(0.f, 1.f, 0.f);
		glVertex3f(0.f, 1.5f, 0.5f);
		glVertex3f(0.5f, 1.5f, 0.5f);
		glVertex3f(0.5f, 1.5f, -0.5f);
		glVertex3f(0.f, 1.5f, -0.5f);

		//draw bottom of leg
		glNormal3f(0.f, -1.f, 0.f);
		glVertex3f(0.5f, -2.f, 0.5f);
		glVertex3f(0.5f, -2.f, -0.5f);
		glVertex3f(0.f, 1.5f, -0.5f);
		glVertex3f(0.f, 1.5f, 0.5f);

		glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}
