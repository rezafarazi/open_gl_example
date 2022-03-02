#include "stdafx.h"
#include <iostream>
#include "GL\glut.h"

using namespace std;

int mat[3][3] = { {0,0,0},{0,0,0},{0,0,0} };
int x_and_o = 0;
int win = false;
float x_ = 0.65,y_=0.65;

void show(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	
	glBegin(GL_LINES);
	glVertex2f(0.35, 0.9);
	glVertex2f(0.35, -0.9);
	glVertex2f(-0.35, 0.9);
	glVertex2f(-0.35, -0.9);
	glVertex2f(0.9, 0.35);
	glVertex2f(-0.9, 0.35);
	glVertex2f(0.9, -0.35);
	glVertex2f(-0.9, -0.35);
	glEnd();

	if (mat[0][0]!=0)
	{
		if (mat[0][0] == 1)
		{
			glBegin(GL_LINES);
			glVertex2f(0.1 - x_, 0.1 + y_);
			glVertex2f(-0.1 - x_, -0.1 + y_);
			glVertex2f(-0.1 - x_, 0.1 + y_);
			glVertex2f(0.1 - x_, -0.1 + y_);
			glEnd();
		}
		else if (mat[0][0] == 2)
		{
			glBegin(GL_LINES);
			glVertex2f(-0.05 - x_, 0.0 + y_);
			glVertex2f(0.0 - x_, -0.05 + y_);
			glVertex2f(0.0 - x_, -0.05 + y_);
			glVertex2f(0.1 - x_, 0.15 + y_);
			glEnd();
		}
	}
	
	if (mat[0][1] != 0)
	{
		if (mat[0][1] == 1)
		{
			glBegin(GL_LINES);
			glVertex2f(0.1, 0.1 + y_);
			glVertex2f(-0.1, -0.1 + y_);
			glVertex2f(-0.1, 0.1 + y_);
			glVertex2f(0.1, -0.1 + y_);
			glEnd();
		}
		else if (mat[0][1] == 2)
		{
			glBegin(GL_LINES);
			glVertex2f(-0.05, 0.0 + y_);
			glVertex2f(0.0, -0.05 + y_);
			glVertex2f(0.0, -0.05 + y_);
			glVertex2f(0.1, 0.15 + y_);
			glEnd();
		}
	}

	if (mat[0][2] != 0)
	{
		if (mat[0][2] == 1)
		{
			glBegin(GL_LINES);
			glVertex2f(0.1 + x_, 0.1 + y_);
			glVertex2f(-0.1 + x_, -0.1 + y_);
			glVertex2f(-0.1 + x_, 0.1 + y_);
			glVertex2f(0.1 + x_, -0.1 + y_);
			glEnd();
		}
		else if (mat[0][2] == 2)
		{
			glBegin(GL_LINES);
			glVertex2f(-0.05 + x_, 0.0 + y_);
			glVertex2f(0.0 + x_, -0.05 + y_);
			glVertex2f(0.0 + x_, -0.05 + y_);
			glVertex2f(0.1 + x_, 0.15 + y_);
			glEnd();
		}
	}

	if (mat[1][0] != 0)
	{
		if (mat[1][0] == 1)
		{
			glBegin(GL_LINES);
			glVertex2f(0.1 - x_, 0.1);
			glVertex2f(-0.1 - x_, -0.1);
			glVertex2f(-0.1 - x_, 0.1);
			glVertex2f(0.1 - x_, -0.1);
			glEnd();
		}
		else if (mat[1][0] == 2)
		{
			glBegin(GL_LINES);
			glVertex2f(-0.05 - x_, 0.0);
			glVertex2f(0.0 - x_, -0.05);
			glVertex2f(0.0 - x_, -0.05);
			glVertex2f(0.1 - x_, 0.15);
			glEnd();
		}
	}

	if (mat[1][1] != 0)
	{
		if (mat[1][1] == 1)
		{
			glBegin(GL_LINES);
			glVertex2f(0.1,0.1);
			glVertex2f(-0.1, -0.1);
			glVertex2f(-0.1, 0.1);
			glVertex2f(0.1, -0.1);
			glEnd();
		}
		else if (mat[1][1] == 2)
		{
			glBegin(GL_LINES);
			glVertex2f(-0.05, 0.0);
			glVertex2f(0.0, -0.05);
			glVertex2f(0.0, -0.05);
			glVertex2f(0.1, 0.15);
			glEnd();
		}
	}

	if (mat[1][2] != 0)
	{
		if (mat[1][2] == 1)
		{
			glBegin(GL_LINES);
			glVertex2f(0.1 + x_, 0.1);
			glVertex2f(-0.1 + x_, -0.1);
			glVertex2f(-0.1 + x_, 0.1);
			glVertex2f(0.1 + x_, -0.1);
			glEnd();
		}
		else if (mat[1][2] == 2)
		{
			glBegin(GL_LINES);
			glVertex2f(-0.05 + x_, 0.0);
			glVertex2f(0.0 + x_, -0.05);
			glVertex2f(0.0 + x_, -0.05);
			glVertex2f(0.1 + x_, 0.15);
			glEnd();
		}
	}

	if (mat[2][0] != 0)
	{
		if (mat[2][0] == 1)
		{
			glBegin(GL_LINES);
			glVertex2f(0.1 - x_, 0.1 - y_);
			glVertex2f(-0.1 - x_, -0.1 - y_);
			glVertex2f(-0.1 - x_, 0.1 - y_);
			glVertex2f(0.1 - x_, -0.1 - y_);
			glEnd();
		}
		else if (mat[2][0] == 2)
		{
			glBegin(GL_LINES);
			glVertex2f(-0.05 - x_, 0.0 - y_);
			glVertex2f(0.0 - x_, -0.05 - y_);
			glVertex2f(0.0 - x_, -0.05 - y_);
			glVertex2f(0.1 - x_, 0.15 - y_);
			glEnd();
		}
	}

	if (mat[2][1] != 0)
	{
		if (mat[2][1] == 1)
		{
			glBegin(GL_LINES);
			glVertex2f(0.1 , 0.1 - y_);
			glVertex2f(-0.1 , -0.1 - y_);
			glVertex2f(-0.1 , 0.1 - y_);
			glVertex2f(0.1 , -0.1 - y_);
			glEnd();
		}
		else if (mat[2][1] == 2)
		{
			glBegin(GL_LINES);
			glVertex2f(-0.05 , 0.0 - y_);
			glVertex2f(0.0 , -0.05 - y_);
			glVertex2f(0.0 , -0.05 - y_);
			glVertex2f(0.1 , 0.15 - y_);
			glEnd();
		}
	}

	if (mat[2][2] != 0)
	{
		if (mat[2][2] == 1)
		{
			glBegin(GL_LINES);
			glVertex2f(0.1 + x_, 0.1 - y_);
			glVertex2f(-0.1 + x_, -0.1 - y_);
			glVertex2f(-0.1 + x_, 0.1 - y_);
			glVertex2f(0.1 + x_, -0.1 - y_);
			glEnd();
		}
		else if (mat[2][2] == 2)
		{
			glBegin(GL_LINES);
			glVertex2f(-0.05 + x_, 0.0 - y_);
			glVertex2f(0.0 + x_, -0.05 - y_);
			glVertex2f(0.0 + x_, -0.05 - y_);
			glVertex2f(0.1 + x_, 0.15 - y_);
			glEnd();
		}
	}

	if (win == 1)
	{
		glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
		glColor3f(0.0,0.0,0.0);
		glBegin(GL_QUADS);
		glVertex2f(1.0, 1.0);
		glVertex2f(-1.0, 1.0);
		glVertex2f(-1.0, -1.0);
		glVertex2f(1.0, -1.0);
		glEnd();

		glPolygonMode(GL_FRONT_AND_BACK, GL_LINES);
		glColor3f(1.0, 1.0, 1.0);
		if (x_and_o==1)
		{
			glBegin(GL_LINES);
			glVertex2f(0.2,0.2);
			glVertex2f(-0.2, -0.2);
			glVertex2f(-0.2, 0.2);
			glVertex2f(0.2, -0.2);
			glEnd();
		}
		else
		{
			glBegin(GL_LINES);
			glVertex2f(-0.07, 0.0);
			glVertex2f(0.0, -0.07);
			glVertex2f(0.0, -0.07);
			glVertex2f(0.14, 0.14);
			glEnd();
		}
	}

	glFlush();
}

void s()
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
}

int check_matrix()
{

	if (mat[0][0]!=0 && mat[0][1]!=0 && mat[0][2] != 0)
	{
		if (mat[0][0] == mat[0][1] && mat[0][2] == mat[0][1])
		{
			return 1;
		}
	}

	if (mat[1][0] != 0 && mat[1][1] != 0 && mat[1][2] != 0)
	{
		if (mat[1][0] == mat[1][1] && mat[1][2] == mat[1][1])
		{
			return 1;
		}
	}

	if (mat[2][0] != 0 && mat[2][1] != 0 && mat[2][2] != 0)
	{
		if (mat[2][0] == mat[2][1] && mat[2][2] == mat[2][1])
		{
			return 1;
		}
	}

	if (mat[0][0] != 0 && mat[1][0] != 0 && mat[2][0] != 0)
	{
		if (mat[0][0] == mat[1][0] && mat[1][0] == mat[2][0])
		{
			return 1;
		}
	}
	
	if (mat[0][1] != 0 && mat[1][1] != 0 && mat[2][1] != 0)
	{
		if (mat[0][1] == mat[1][1] && mat[1][1] == mat[2][1])
		{
			return 1;
		}
	}

	if (mat[0][2] != 0 && mat[1][2] != 0 && mat[2][2] != 0)
	{
		if (mat[0][2] == mat[1][2] && mat[1][2] == mat[2][2])
		{
			return 1;
		}
	}

	if (mat[0][0] != 0 && mat[1][1] != 0 && mat[2][2] != 0)
	{
		if (mat[0][0] == mat[1][1] && mat[1][1] == mat[2][2])
		{
			return 1;
		}
	}
	
	if (mat[0][2] != 0 && mat[1][1] != 0 && mat[2][0] != 0)
	{
		if (mat[0][2] == mat[1][1] && mat[1][1] == mat[2][0])
		{
			return 1;
		}
	}

	return 0;
}

void set_mat(int x,int y)
{
	if (mat[x][y] == 0)
	{
		if (x_and_o==1)
			mat[x][y] = 1;
		else
			mat[x][y] = 2;
	}
}

void keyboard(int key,int x,int y)
{
	if (win == 0)
	{
		switch (key)
		{
		case GLUT_KEY_F1:
			set_mat(0, 0);
			break;
		case GLUT_KEY_F2:
			set_mat(0, 1);
			break;
		case GLUT_KEY_F3:
			set_mat(0, 2);
			break;
		case GLUT_KEY_F4:
			set_mat(1, 0);
			break;
		case GLUT_KEY_F5:
			set_mat(1, 1);
			break;
		case GLUT_KEY_F6:
			set_mat(1, 2);
			break;
		case GLUT_KEY_F7:
			set_mat(2, 0);
			break;
		case GLUT_KEY_F8:
			set_mat(2, 1);
			break;
		case GLUT_KEY_F9:
			set_mat(2, 2);
			break;
		}

		if ((win=check_matrix())==0)
		{
			if (x_and_o==1)
				x_and_o = 0;
			else
				x_and_o = 1;
		}
	}
	else
	{
		if (key == GLUT_KEY_F12)
		{
			mat[0][0] = 0;
			mat[0][1] = 0;
			mat[0][2] = 0;
			mat[1][0] = 0;
			mat[1][1] = 0;
			mat[1][2] = 0;
			mat[2][0] = 0;
			mat[2][1] = 0;
			mat[2][2] = 0;
			win = 0;
		}
	}
	glutPostRedisplay();
}

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutCreateWindow("Reza Fta");
	glutDisplayFunc(show);
	glutSpecialFunc(keyboard);
	s();
	glutMainLoop();
	return 0;
}
