#include "stdafx.h"
#include <iostream>
#include "GL\glut.h"

using namespace std;


void Display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0f, 0.0f, 0.0f);
	
	//This Code For Remove Triangels inside With Color
	glPolygonMode(GL_FRONT_AND_BACK , GL_LINE);
	
	//Create a Triangel
	/*glBegin(GL_TRIANGLES);
	glVertex2f(-0.8f, -0.8f);
	glVertex2f(-0.8f, 0.8f);
	glVertex2f(0.0f, -0.8f);
	glEnd();*/

	//Create Infinity Triangel
	/*glBegin(GL_TRIANGLE_STRIP);
	glVertex2f(-0.8f, -0.8f);
	glVertex2f(-0.8f, 0.8f);
	glVertex2f(0.0f, -0.8f);
	glVertex2f(0.0f, 0.8f);
	glVertex2f(0.0f, -0.8f);
	glEnd();*/

	//Connected All Lines To Center
	/*glBegin(GL_TRIANGLE_FAN);
	glVertex2f(0.0f, -0.0f);
	glVertex2f(-0.7f, 0.0f);
	glVertex2f(-0.7f, 0.7f);
	glVertex2f(0.0f, 0.7f);
	glVertex2f(0.0f, -0.8f);
	glEnd();*/

	//End Point To Start Point
	/*glBegin(GL_POLYGON);
	glVertex2f(0.0f, -0.0f);
	glVertex2f(-0.7f, 0.0f);
	glVertex2f(-0.7f, 0.7f);
	glVertex2f(0.0f, 0.7f);
	glVertex2f(0.0f, -0.8f);
	glEnd();*/

	//Create Infinity Shape Disconnected
	/*glBegin(GL_QUADS);
	glVertex2f(-0.7f, 0.0f);
	glVertex2f(-0.7f, 0.7f);
	glVertex2f(0.0f, 0.7f);
	glVertex2f(0.0f, -0.8f);
	glEnd();*/

	//Create Infinity Shape Connected
	/*glBegin(GL_QUAD_STRIP);
	glVertex2f(-0.7f, 0.0f);
	glVertex2f(-0.7f, 0.7f);
	glVertex2f(0.0f, 0.7f);
	glVertex2f(0.0f, -0.8f);
	glVertex2f(0.9f, 0.2f);
	glVertex2f(-0.3f, 0.4f);
	glVertex2f(0.6f, 0.8f);
	glVertex2f(-0.4f, 0.2f);
	glEnd();*/


	glFlush();
}


void setup()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
}


int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutCreateWindow("Reza Fta");
	glutDisplayFunc(Display);
	setup();
	glutMainLoop();
	return 0;
}
