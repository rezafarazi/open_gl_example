#include "stdafx.h"
#include <iostream>
#include "GL\glut.h"
#include "math.h"

using namespace std;

float a=0.0, b = 0.0;

void Display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.0);

	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glLineWidth(5);


	glBegin(GL_LINES);
	glVertex2f(0.9, 0.6);
	glVertex2f(-0.9, 0.6);
	glVertex2f(-0.85, 0.6);
	glVertex2f(-0.85, 0.8);
	glVertex2f(0.85, 0.6);
	glVertex2f(0.85, 0.8);
	glVertex2f(0.85, 0.8);
	glVertex2f(0.40, 0.8);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex2f(0.40, 0.7);
	glVertex2f(0.40, 0.9);
	glVertex2f(-0.40, 0.9);
	glVertex2f(-0.40, 0.7);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(-0.40, 0.8);
	glVertex2f(-0.85, 0.8);
	glEnd();

	for (float i = -0.9; i < 0.9; i += 0.1)
	{
		glBegin(GL_LINES);
		glVertex2f(i, 0.6);
		glVertex2f(i, 0.3);
		glVertex2f((i + 0.1), 0.3);
		glVertex2f((i + 0.1), 0.6);
		glEnd();

		glPointSize(4.0f);
		glBegin(GL_POINTS);		
		int radius = 360;
		for (int ii = 180; ii < (radius); ii++)
		{
			float theta = 2.0f * 3.1415926f * float(ii) / float(radius);

			float x = 0.05 * cosf(theta);
			float y = 0.05 * sinf(theta);

			glVertex2f(((i + 0.05)+x), 0.3+y);

		}
		glEnd();

	}

	glBegin(GL_LINES);
	glVertex2f(-0.85, 0.26);
	glVertex2f(-0.85, -0.5);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(0.85, 0.26);
	glVertex2f(0.85, -0.5);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(-0.9, -0.5);
	glVertex2f(0.9, -0.5);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(-0.75, -0.5);
	glVertex2f(-0.75, 0.1);
	glVertex2f(-0.75, 0.1);
	glVertex2f(-0.45, 0.1);
	glVertex2f(-0.45, 0.1);
	glVertex2f(-0.45, -0.5);
	glVertex2f(-0.45, -0.4);
	glVertex2f(-0.75, -0.4);
	glVertex2f(-0.5, -0.1);
	glVertex2f(-0.5, -0.15);
	glEnd();


	glBegin(GL_LINE_LOOP);
	glVertex2f(0.7, -0.4);
	glVertex2f(-0.1, -0.4);
	glVertex2f(-0.1, 0.1);
	glVertex2f(0.7, 0.1);
	glEnd();


	glBegin(GL_LINES);
	glVertex2f(0.5, -0.4);
	glVertex2f(0.5, -0.3);
	glVertex2f(0.4, -0.3);
	glVertex2f(0.6, -0.3);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(0.1, -0.4);
	glVertex2f(0.1, -0.3);
	glVertex2f(0.0, -0.3);
	glVertex2f(0.2, -0.3);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex2f(0.4 + a, -0.0 + b);
	glVertex2f(0.6 + a, -0.0 + b);
	glVertex2f(0.6 + a, -0.1 + b);
	glVertex2f(0.4 + a, -0.1 + b);
	glEnd();


	glBegin(GL_LINE_LOOP);
	glVertex2f(0.0 + a, -0.0 + b);
	glVertex2f(0.2 + a, -0.0 + b);
	glVertex2f(0.2 + a, -0.1 + b);
	glVertex2f(0.0 + a, -0.1 + b);
	glEnd();


	glBegin(GL_LINES);
	glVertex2f(0.5 + a, -0.0);
	glVertex2f(0.5, 0.1);

	glVertex2f(0.1 + a, -0.0);
	glVertex2f(0.1, 0.1);
	glEnd();


	glFlush();
}


void setup()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
}


void anim(int x)
{
	if (a <= 0.05)
	{
		a += 0.05;
	}
	else
	{
		a -= 0.1;
	}
	glutPostRedisplay();
	glutTimerFunc(1000, anim, 0);
}


int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(600,600);
	glutCreateWindow("Mozlef");
	glutDisplayFunc(Display);
	glutTimerFunc(1, anim, 0);
	setup();
	glutMainLoop();
	return 0;
}
