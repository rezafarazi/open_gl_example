#include "stdafx.h"
#include <iostream>
#include "GL\glut.h"

using namespace std;

float loca=0.0, locb=0.0;
int i = 10000;
int score = 0;
int flag = 1;
float w = 0.9;
int c = 0;

float RandomFloat(float a, float b) 
{
	float random = ((float)rand()) / (float)RAND_MAX;
	float diff = b - a;
	float r = random * diff;
	return a + r;
}

void game(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	glPointSize(20);
	glColor3f(0.1,0.1,0.0);
	glBegin(GL_POINTS);
	loca = RandomFloat(-1.0, 1.0);
	locb = RandomFloat(-1.0, 1.0);
	glVertex2f(loca,locb);
	glEnd();
	
	
	w = 0.9;
	glLineWidth(2);
	glBegin(GL_LINES);
	for (int a = 0;a < score;a++)
	{
		glVertex2f(w, 0.9);
		glVertex2f(w, 0.82);
		w -= 0.02;
	}
	glEnd();


	if (flag==0)
	{		
		glColor3f(0.0,0.0,0.0);
		glBegin(GL_LINES);
		glVertex2f(0.92,0.86);
		glVertex2f(w, 0.86);
		glEnd();
		score = 0;
		i = 10000;
	}


	glutSwapBuffers();
}

void timer(int x)
{
	i -= 10;
	glutPostRedisplay();
	glutTimerFunc(i, timer, 0);	
}

float round_f(float var)
{
	float value = (int)(var * 100 + .5);
	return (float)value / 100;
}

void me(int btn, int e, int pow, int poh)
{
	if (c == 0)
	{
		if (btn == GLUT_LEFT_BUTTON)
		{
			float w = (pow - 500.0);
			w = w / 500.0;
			w += 0.5;
			w = round_f(w);

			float h = (poh - 500.0);
			h = h / 500.0;
			h += 0.5;
			h = round_f(h);

			float la = round_f(loca / 2.0);
			float lb = round_f(locb / 2.0);

			cout << la << "\t " << w << endl;

			if ((la + 0.1 >= w && la - 0.1 <= w))
			{
				cout << "OK" <<endl;
				flag = 1;
				c = 1;
				score++;
				glutTimerFunc(i,timer,0);
			}
			else
			{
				flag = 0;
				score = 0;
				i = 10000;
			}
		}
	}
	else
	{
		c = 0;
	}
}

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutCreateWindow("M");
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glutDisplayFunc(game);
	glutMouseFunc(me);
	glutTimerFunc(i,timer,0);
	glutMainLoop();
	return 0;
}
