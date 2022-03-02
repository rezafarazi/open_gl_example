#include "stdafx.h"
#include <iostream>
#include "GL\glut.h"

using namespace std;


void Display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(14);
	glColor3f(0.0f, 0.0f, 0.0f);

	float x1 = -0.9f, x2 = 0.9f, x3 = 0.9f, x4 = -0.9f;
	float y1 = -0.9f, y2 = -0.9f, y3 = 0.9f, y4 = 0.9f;
	float space = 0.6;

	for (int i = 0; i <= 3; i++)
	{
		cout << i;

		glBegin(GL_LINE_LOOP);

		glVertex2f(x1, y1);
		glVertex2f(x2, y2);
		glVertex2f(x3, y3);
		glVertex2f(x4, y4);

		x1 += 0.3f;
		y2 -= 0.3f;
		y3 -= 0.3f;
		x4 += 0.3f;

		glEnd();
	}


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
