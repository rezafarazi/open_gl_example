#include "stdafx.h"
#include <iostream>
#include "GL\glut.h"

using namespace std;

void Display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	
	
	glPointSize(14);
	glBegin(GL_POINTS);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(0.2f,0.2f);
	glEnd();
	
	glFlush();
}


void setup()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
}


int main(int argc ,char *argv[])
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(400,400);
	glutCreateWindow("Reza Fta");
	glutDisplayFunc(Display);
	glMatrixMode(GL_MODELVIEW);
	setup();
	glutMainLoop();
    return 0;
}
