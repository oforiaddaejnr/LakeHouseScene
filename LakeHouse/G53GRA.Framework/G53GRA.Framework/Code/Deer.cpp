#include "Deer.h"
Deer::Deer(): animationTime(6.f), nangle(-45.f)
{
}

void Deer::Display()
{
	
	glPushMatrix();

		glPushAttrib(GL_ALL_ATTRIB_BITS);
		glColor3f(1.f, 0.27f, 0.21f); //brown color
		glTranslatef(pos[0], pos[1], pos[2]);
		glScalef(scale[0], scale[1], scale[2]);
		drawDeer();

		glPopAttrib();
	glPopMatrix(); 
}

void Deer::drawDeer()
{
	glTranslatef(0.f, 2.f, 0.f); //move body up
	glPushMatrix();
	drawBody();
	glPopMatrix();

	//draw front right leg
	glPushMatrix();
	glTranslatef(3.2f, -0.2f, 1.8f); //move leg position forward and front
	glScalef(0.5f, 0.5f, 0.2f);
	drawLeg();
	glPopMatrix();

	//draw front left leg
	glPushMatrix();
	glTranslatef(3.2f, -0.2f, 0.7f); //move leg position forward and back
	glScalef(0.5f, 0.5f, 0.2f);
	drawLeg();
	glPopMatrix();

	//draw back right leg
	glPushMatrix();
	glTranslatef(0.2f, -0.2f, 1.8f); //move leg position backward and front 
	glScalef(0.5f, 0.5f, 0.2f);
	drawLeg();
	glPopMatrix();

	//draw back left leg
	glPushMatrix();
	glTranslatef(0.2f, -0.2f, 0.7f); //move leg position backward and back
	glScalef(0.5f, 0.5f, 0.2f);
	drawLeg();
	glPopMatrix();

	//draw neck
	glPushMatrix();
	glTranslatef(2.7f, 1.2f, 0.8f); //move next position forward and up
	glRotatef(nangle, 0.f, 0.f, 1.f);
	glScalef(0.8, 5.f, 0.8);
	drawNeck();
	glPopMatrix();


}

void Deer::drawBody()
{
	glPushMatrix();
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, fur); //bind texture
		glBegin(GL_QUADS);
		
		//front 
		glNormal3f(0.f, 0.f, 1.f);
		glTexCoord2f(1.f, 1.f); glVertex3f(3.5f, 1.5f, 2.f);
		glTexCoord2f(0.f, 1.f); glVertex3f(0.f, 1.5f, 2.f);
		glTexCoord2f(0.f, 0.f); glVertex3f(0.f, 0.f, 2.f);
		glTexCoord2f(1.f, 0.f); glVertex3f(3.5f, 0.f, 2.f);

		//right
		glNormal3f(1.f, 0.f, 0.f);
		glTexCoord2f(0.f, 1.f); glVertex3f(3.5f, 1.5f, 2.f);
		glTexCoord2f(0.f, 0.f); glVertex3f(3.5f, 0.f, 2.f);
		glTexCoord2f(1.f, 0.f); glVertex3f(3.5f, 0.f, 0.5f);
		glTexCoord2f(1.f, 1.f); glVertex3f(3.5f, 1.5f, 0.5f);

		//left
		glNormal3f(-1.f, 0.f, 0.f);
		glTexCoord2f(1.f, 1.f); glVertex3f(0.f, 1.5f, 2.f);
		glTexCoord2f(0.f, 1.f); glVertex3f(0.f, 1.5f, 0.5f);
		glTexCoord2f(0.f, 0.f); glVertex3f(0.f, 0.f, 0.5f);
		glTexCoord2f(1.f, 0.f); glVertex3f(0.f, 0.f, 2.f);

		//back
		glNormal3f(0.f, 0.f, -1.f);
		glTexCoord2f(0.f, 0.f); glVertex3f(3.5f, 0.f, 0.5f);
		glTexCoord2f(1.f, 0.f); glVertex3f(0.f, 0.f, 0.5f);
		glTexCoord2f(1.f, 1.f); glVertex3f(0.f, 1.5f, 0.5f);
		glTexCoord2f(0.f, 1.f); glVertex3f(3.5f, 1.5f, 0.5f);

		//top
		glNormal3f(0.f, 1.f, 0.f);
		glTexCoord2f(1.f, 0.f); glVertex3f(3.5f, 1.5f, 2.f);
		glTexCoord2f(1.f, 1.f); glVertex3f(3.5f, 1.5f, 0.5f);
		glTexCoord2f(0.f, 1.f); glVertex3f(0.f, 1.5f, 0.5f);
		glTexCoord2f(0.f, 0.f); glVertex3f(0.f, 1.5f, 2.f);

		//bottom
		glNormal3f(0.f, -1.f, 0.f);
		glTexCoord2f(0.f, 0.f); glVertex3f(3.5f, 0.f, 2.f);
		glTexCoord2f(0.f, 1.f); glVertex3f(0.f, 0.f, 2.f);
		glTexCoord2f(1.f, 1.f); glVertex3f(0.f, 0.f, 0.5f);
		glTexCoord2f(1.f, 0.f); glVertex3f(3.5f, 0.f, 0.5f);



		glEnd();
		glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}

void Deer::drawLeg()
{
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, fur); //bind texture
		glBegin(GL_QUADS);
		//front 
		glNormal3f(0.f, 0.f, 1.f);
		glTexCoord2f(1.f, 1.f); glVertex3f(0.5f, 1.5f, 0.5f);
		glTexCoord2f(0.f, 1.f); glVertex3f(0.f, 1.5f, 0.5f);
		glTexCoord2f(0.f, 0.f); glVertex3f(0.f, -2.f, 0.5f);
		glTexCoord2f(1.f, 0.f); glVertex3f(0.5f, -2.f, 0.5f);

		//right
		glNormal3f(1.f, 0.f, 0.f);
		glTexCoord2f(0.f, 1.f); glVertex3f(0.5f, 1.5f,-0.5f);
		glTexCoord2f(0.f, 0.f); glVertex3f(0.5f, 1.5f, 0.5f);
		glTexCoord2f(1.f, 0.f); glVertex3f(0.5f, -2.f, 0.5f);
		glTexCoord2f(1.f, 1.f); glVertex3f(0.5f, -2.f, -0.5f);

		//left
		glNormal3f(-1.f, 0.f, 0.f);
		glTexCoord2f(1.f, 1.f); glVertex3f(0.f, 1.5f, 0.5f);
		glTexCoord2f(0.f, 1.f); glVertex3f(0.f, 1.5f, -0.5f);
		glTexCoord2f(0.f, 0.f); glVertex3f(0.f, -2.f, -0.5f);
		glTexCoord2f(1.f, 0.f); glVertex3f(0.f, -2.f, 0.5f);

		//back
		glNormal3f(0.f, 0.f, -1.f);
		glTexCoord2f(0.f, 0.f); glVertex3f(0.5f, 1.5f, -0.5f);
		glTexCoord2f(1.f, 0.f); glVertex3f(0.5f, -2.f, -0.5f);
		glTexCoord2f(1.f, 1.f); glVertex3f(0.f, -2.f, -0.5f);
		glTexCoord2f(0.f, 1.f); glVertex3f(0.f, 1.5f, -0.5f);

		//top
		glNormal3f(0.f, 1.f, 0.f);
		glVertex3f(0.f, 1.5f, 0.5f);
		glVertex3f(0.5f, 1.5f, 0.5f);
		glVertex3f(0.5f, 1.5f, -0.5f);
		glVertex3f(0.f, 1.5f, -0.5f);

		//bottom
		glNormal3f(0.f, -1.f, 0.f);
		glTexCoord2f(0.f, 0.f); glVertex3f(0.5f, -2.f, 0.5f);
		glTexCoord2f(0.f, 1.f); glVertex3f(0.5f, -2.f, -0.5f);
		glTexCoord2f(1.f, 1.f); glVertex3f(0.f, 1.5f, -0.5f);
		glTexCoord2f(1.f, 0.f); glVertex3f(0.f, 1.5f, 0.5f);



		glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}

void Deer::drawNeck()
{
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, fur); //bind texture
	glBegin(GL_QUADS); 
	//front 
	glNormal3f(0.f, 0.f, 1.f);
	glTexCoord2f(1.f, 1.f); glVertex3f(0.5f, 0.5f, 1.f);
	glTexCoord2f(0.f, 1.f); glVertex3f(0.f, 0.5f, 1.f);
	glTexCoord2f(0.f, 0.f); glVertex3f(0.f, 0.f, 1.f);
	glTexCoord2f(1.f, 0.f); glVertex3f(0.5f, 0.f, 1.f);

	//right
	glNormal3f(1.f, 0.f, 0.f);
	glTexCoord2f(0.f, 1.f); glVertex3f(0.5f, 0.5f, 1.f);
	glTexCoord2f(0.f, 0.f); glVertex3f(0.5f, 0.f, 1.f);
	glTexCoord2f(1.f, 0.f); glVertex3f(0.5f, 0.f, 0.5f);
	glTexCoord2f(1.f, 1.f); glVertex3f(0.5f, 0.5f, 0.5f);

	//left
	glNormal3f(-1.f, 0.f, 0.f);
	glTexCoord2f(1.f, 1.f); glVertex3f(0.f, 0.5f, 1.f);
	glTexCoord2f(0.f, 1.f); glVertex3f(0.f, 0.5f, 0.5f);
	glTexCoord2f(0.f, 0.f); glVertex3f(0.f, 0.f, 0.5f);
	glTexCoord2f(1.f, 0.f); glVertex3f(0.f, 0.f, 1.f);

	//back
	glNormal3f(0.f, 0.f, -1.f);
	glTexCoord2f(0.f, 0.f); glVertex3f(0.5f, 0.f, 0.5f);
	glTexCoord2f(1.f, 0.f); glVertex3f(0.f, 0.f, 0.5f);
	glTexCoord2f(1.f, 1.f); glVertex3f(0.f, 0.5f, 0.5f);
	glTexCoord2f(1.f, 0.f); glVertex3f(0.5f, 0.5f, 0.5f);

	//top
	glNormal3f(0.f, 1.f, 0.f);
	glVertex3f(0.f, 0.5f, 1.f);
	glVertex3f(0.5f, 0.5f, 1.f);
	glVertex3f(0.5f, 0.5f, 0.5f);
	glVertex3f(0.f, 0.5f, 0.5f);

	//bottom
	glNormal3f(0.f, -1.f, 0.f);
	glVertex3f(0.5f, 0.f, 1.f);
	glVertex3f(0.f, 0.f, 1.f);
	glVertex3f(0.f, 0.f, 0.5f);
	glVertex3f(0.5f, 0.f, 0.5f);



	glEnd();
		glPushMatrix(); //push unto stack and start drawing head in relation to the neck
		glTranslatef(0.8f, 0.5f, 0.75f);
		drawHead();
		glPopMatrix();
	glPopMatrix();
}

void Deer::drawHead()
{
	glPushMatrix();
	glScalef(0.2f, 0.02f, 0.1f);
	glutSolidSphere(5, 20, 15);
		glTranslatef(-4.f, -0.5f, 1.f);
		glRotatef(-40.f, 0.f, 0.f, 1.f);
		glRotatef(-115.f, 0.f, 1.f, 0.f);
		glPushMatrix();
		glScalef(5.f, 5.f, 5.f);
		drawAntlers();
		glPopMatrix();
	glPopMatrix();

}

void Deer::drawAntlers()
{
	char curr;

	for (unsigned int i = 0; i < sequence.size(); i++)
	{
		curr = sequence[i];             // for each char in sequence
		switch (curr) {                  // check current char command
		case 'f':                   // draw branch, move forward
			glScalef(0.9f, 0.9f, 0.9f);
			branch();
			break;
		case '+':                   // yaw clockwise
			glRotatef(-angle, 0.f, 0.f, 1.f);
			break;
		case '-':                   // yaw counter-clockwise
			glRotatef(angle, 0.f, 0.f, 1.f);
			break;
		case '^':                   // pitch clockwise
			glRotatef(-angle, 1.f, 0.f, 0.f);
			break;
		case '&':                   // pitch counter-clockwise
			glRotatef(angle, 1.f, 0.f, 0.f);
			break;
		case '<':                   // roll clockwise
			glRotatef(-angle, 0.f, 1.f, 0.f);
			break;
		case '>':                   //roll counter-clockwise
			glRotatef(angle, 0.f, 1.f, 0.f);
			break;
		case '|':                   // roll upside-down
			glRotatef(180.f, 0.f, 1.f, 0.f);
			break;
		case '[': //"Save"
			glPushMatrix();
			break;
		case ']': //"Restore"
			glPopMatrix();
			break;

		}
	}
}

void Deer::branch()
{
	
	float res = 0.1f * M_PI;                  // resolution (in radians: equivalent to 18 degrees)
	float r = 0.15f;                        // ratio of radius to height
	float x = r, z = 0.f;                   // initialise x and z on right of cylinder centre
	float t = 0.f;                          // initialise angle as 0

	float mat_colour[]                      // colour reflected by diffuse light
		= { 0.58f, 0.27f, 0.21f, 1.f };         // mid brown
	float mat_ambient[]                     // ambient colour
		= { 0.29f, 0.14f, 0.11f, 1.f };         // dark brown
	float mat_spec[]                        // specular colour
		= { 0.f, 0.f, 0.f, 1.f };               // no reflectance (black)

	glPushAttrib(GL_ALL_ATTRIB_BITS);       // save current style attributes (inc. material properties)
	glDisable(GL_COLOR_MATERIAL);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient); // set colour for ambient reflectance
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_colour);  // set colour for diffuse reflectance
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_spec);   // set colour for specular reflectance 

	do
	{                                     // create branch with multiple QUADS
		glBegin(GL_QUADS);
		// Create first points (with normals)
		glNormal3f(x, 0.f, z);          // define a normal facing out from the centre (0,0,0)
		glVertex3f(x, 0.f, z);          // bottom (with normal (x,0,z))
		glVertex3f(x, 1.f, z);          // top (with normal (x,0,z))
		// Iterate around circle
		t += res;                       // add increment to angle
		x = r * cos(t);                   // move x and z around circle
		z = r * sin(t);
		// Close quad (with new vertex normals)
		glNormal3f(x, 0.f, z);          // define a new normal now that x,z have moved around
		glVertex3f(x, 1.f, z);          // top
		glVertex3f(x, 0.f, z);          // bottom
		glEnd();
	} while (t <= 2 * M_PI);                // full rotation around circle

	glTranslatef(0.f, 1.f, 0.f);            // translate to top of branch
	glutSolidSphere(r, 5, 5);                 // add a sphere to cap cylinders and create 'joints'
	glEnable(GL_COLOR_MATERIAL);
	glPopAttrib();
	
}

void Deer::getSequence()
{
	int gen = 0, j = 0;
	string next;
	bool changed;
	sequence = init;
	char curr;
	while (gen < iter) { //iterative sccheme
		next = ""; //start with blank
		for (unsigned int i = 0; i < sequence.size(); i++) {
			curr = sequence[i]; //For each letter in the sequence
			changed = false;
			j = 0;
			for (vector<char>::iterator it = flags.begin(); it != flags.end(); ++it, j++) {
				if (curr == *it) { //Iterate through vector of 'flags'
					next += change[j];  //Replace flag with corresponding change string
					changed = true;
					break;
				}
			}
			if (!changed)        //if current char does not match a flag
				next += curr;

		}
		sequence = next;
		gen++;
	}
}

void Deer::addReplaceString(char flag, string str) {
	flags.push_back(flag); //add char to flags
	change.push_back(str); //add string to change
	getSequence(); //Recompute sequence
}

void Deer::setReplaceString(char flag, string str) {
	flags.erase(flags.begin(), flags.end()); //Empty flags
	change.erase(change.begin(), change.end()); //Empty change
	flags.push_back(flag); //Add char to flags
	change.push_back(str);  //Add string to change
	getSequence();
}

void Deer::setNumIter(unsigned int num) {
	iter = num;
}

void Deer::setInitString(string str) {
	init = str;
}

void Deer::Update(const double& deltaTime)
{
	aT = fmod(aT + deltaTime, animationTime);          // update time in animation cycle

	float aS = 14.f * aT / animationTime;         // calculate stage (out of 14)

	// Animation cycle: move head down for first 7 seconds then reverse animation
	// nangle sets position of neck (from 45 degrees to 45 degrees down)
	// hangle sets position of head (from 90 degrees down forward 

	if (aS < 1.f || aS > 13.f)
	{                 // 1st or final stage      
		nangle = -45.f;
	}
	else if (aS < 2.f || aS > 12.f)
	{          // 2nd or 13th stage
		nangle = -60.5f;
	}
	else if (aS < 3.f || aS > 11.f)
	{          // 3rd or 12th stage    
		nangle = -80.f;
	}
	else if (aS < 4.f || aS > 10.f)
	{          // 4th or 11th stage
		nangle = -100.5f;
	}
	else if (aS < 5.f || aS > 9.f)
	{           // 5th or 10th stage
		nangle = -110.f;
	}
	else if (aS < 6.f || aT > 8.f)
	{           // 6th or 9th stage
		nangle = -110.f;
	}
	else
	{                                     // 7th and 8th stage
		nangle = -110.f;
	}
}