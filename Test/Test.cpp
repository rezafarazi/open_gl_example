#include "stdafx.h"
#include <iostream>
#include "GL\glut.h"

using namespace std;


void Display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0f, 1.0f, 0.0f);
	glLineWidth(15);
	glPointSize(15);

	float radius = 0.2;
	glBegin(GL_TRIANGLE_FAN);
	for (int i = 180; i <= 360; i++)
	{
		glVertex2f(cos(i)*radius, sin(i)*radius);
	}
	glEnd();


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
	glMatrixMode(GL_MODELVIEW);
	setup();
	glutMainLoop();
	return 0;
}
