#include "House.h"

House::House() 
{

}

void House::Display()
{
	glPushMatrix();
	glPushAttrib(GL_ALL_ATTRIB_BITS);
	glColor3f(0.58f, 0.27f, 0.21f); //color brown
	glTranslatef(pos[0], pos[1], pos[2]);
	glScalef(scale[0], scale[1], scale[2]);
	drawHouse();
	glPopAttrib();
	glPopMatrix();
}

void House::drawHouse()
{
	glPushMatrix();
	drawBody();
	glPopMatrix();
}

void House::drawBody()
{
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, house); //bind texture to body
	glBegin(GL_QUADS);
		//front part of house
		glNormal3f(0.f, 0.f, 1.f);
		glTexCoord2f(1.f, 1.f); glVertex3f(8.f, 5.f, 8.f);
		glTexCoord2f(0.f, 1.f); glVertex3f(0.f, 5.f, 8.f);
		glTexCoord2f(0.f, 0.f); glVertex3f(0.f, 0.f, 8.f);
		glTexCoord2f(1.f, 0.f); glVertex3f(8.f, 0.f, 8.f);

		//right part of house
		glNormal3f(1.f, 0.f, 0.f);
		glTexCoord2f(0.f, 1.f); glVertex3f(8.f, 5.f, 8.f);
		glTexCoord2f(0.f, 0.f); glVertex3f(8.f, 0.f, 8.f);
		glTexCoord2f(1.f, 0.f); glVertex3f(8.f, 0.f, 0.f);
		glTexCoord2f(1.f, 1.f); glVertex3f(8.f, 5.f, 0.f);

		//left part of house
		glNormal3f(-1.f, 0.f, 0.f);
		glTexCoord2f(1.f, 1.f); glVertex3f(0.f, 5.f, 8.f);
		glTexCoord2f(0.f, 1.f); glVertex3f(0.f, 5.f, 0.f);
		glTexCoord2f(0.f, 0.f); glVertex3f(0.f, 0.f, 0.f);
		glTexCoord2f(1.f, 0.f); glVertex3f(0.f, 0.f, 8.f);

		//back part of house
		glNormal3f(0.f, 0.f, -1.f);
		glTexCoord2f(0.f, 1.f); glVertex3f(8.f, 5.f, 0.f);
		glTexCoord2f(0.f, 0.f); glVertex3f(8.f, 0.f, 0.f);
		glTexCoord2f(1.f, 0.f); glVertex3f(0.f, 0.f, 0.f);
		glTexCoord2f(1.f, 1.f); glVertex3f(0.f, 5.f, 0.f);

		//top part of hosue
		glNormal3f(0.f, 1.f, 0.f);
		glVertex3f(0.f, 5.f, 8.f);
		glVertex3f(8.f, 5.f, 8.f);
		glVertex3f(8.f, 5.f, 0.f);
		glVertex3f(0.f, 5.f, 0.f);

		//bottom part of house
		glNormal3f(0.f, -1.f, 0.f);
		glVertex3f(0.f, 0.f, 8.f);
		glVertex3f(0.f, 0.f, 0.f);
		glVertex3f(8.f, 0.f, 0.f);
		glVertex3f(8.f, 0.f, 8.f);

	glEnd();
	glDisable(GL_TEXTURE_2D);
		glPushMatrix(); //push unto stack and draw roof in relation to the body
		glPushAttrib(GL_ALL_ATTRIB_BITS);
		drawRoof();
		glPopAttrib();
		glPopMatrix();
	glPopMatrix();

	glPushMatrix(); //push unto stack and draw door in relation to the body
	glPushAttrib(GL_ALL_ATTRIB_BITS);
	drawDoor();
	glPopAttrib();
	glPopMatrix();
}

void House::drawDoor()
{
	glEnable(GL_TEXTURE_2D);
	glDisable(GL_CULL_FACE);
	glBindTexture(GL_TEXTURE_2D, door); //bind texture to door
	glBegin(GL_QUADS);
	glNormal3f(0.f, 0.f, 1.f);
	glTexCoord2f(1.f, 1.f); glVertex3f(5.f, 3.f, 8.01f);
	glTexCoord2f(0.f, 1.f); glVertex3f(3.f, 3.f, 8.01f);
	glTexCoord2f(0.f, 0.f); glVertex3f(3.f, 0.f, 8.01f);
	glTexCoord2f(1.f, 0.f); glVertex3f(5.f, 0.f, 8.01f);
	glEnd();
	glEnable(GL_CULL_FACE);
	glDisable(GL_TEXTURE_2D);

}

void House::drawRoof()
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, house); //bind texture to roof
	glBegin(GL_TRIANGLES);

	//right part of roof
	glNormal3f(1.f, 0.f, 0.f);
	glTexCoord2f(0.f, 0.f); glVertex3f(8.f, 5.f, 8.f);
	glTexCoord2f(1.f, 0.f); glVertex3f(8.f, 5.f, 0.f);
	glTexCoord2f(1.f, 1.f); glVertex3f(8.f, 8.f, 4.f);

	glEnd();

	glBegin(GL_QUADS);

	//front part of roof
	glNormal3f(0.f, 0.f, 1.f);
	glTexCoord2f(1.f, 1.f); glVertex3f(8.f, 8.f, 4.f);
	glTexCoord2f(0.f, 1.f); glVertex3f(0.f, 8.f, 4.f);
	glTexCoord2f(0.f, 0.f); glVertex3f(0.f, 5.f, 8.f);
	glTexCoord2f(1.f, 0.f); glVertex3f(8.f, 5.f, 8.f);

	glEnd();

	glBegin(GL_TRIANGLES);

	//left part of roof
	glNormal3f(-1.f, 0.f, 0.f);
	glTexCoord2f(1.f, 0.f); glVertex3f(0.f, 8.f, 4.f);
	glTexCoord2f(0.f, 1.f); glVertex3f(0.f, 5.f, 0.f);
	glTexCoord2f(1.f, 1.f); glVertex3f(0.f, 5.f, 8.f);

	glEnd();

	glBegin(GL_QUADS);

	//back part of roof
	glNormal3f(0.f, 0.f, -1.f);
	glTexCoord2f(0.f, 1.f); glVertex3f(8.f, 8.f, 4.f);
	glTexCoord2f(0.f, 0.f); glVertex3f(8.f, 5.f, 0.f);
	glTexCoord2f(1.f, 0.f); glVertex3f(0.f, 5.f, 0.f);
	glTexCoord2f(1.f, 1.f); glVertex3f(0.f, 8.f, 4.f);

	glEnd();
	glDisable(GL_TEXTURE_2D);


}