#include "stdafx.h"
#include <iostream>
#include "GL\glut.h"
#include "math.h"

using namespace std;

//Global Variables Start
float h = 0.0, w = 0.3;
float wh = 0.0, ww = 0.0;
float bh = -0.9, bw = -0.9;
bool back = true;
bool Keyboard_Key_Pressed = false;
int Timer_Counter = 0;
int MOUSE_X = 0;
int POLYGUN = 0;

bool Play = true;
bool Generate_Block = true;
float RANDOM_POINT;
float Count = 0;
float Carspeed=30;
bool Can_Speed_Up = true;
float Num_Counter_h=-0.05, Num_Counter_w=-0.01;
float Top=0.7, Bottom=-0.4, Left=-0.615, Right=1.215;
//Global Variables End

//Get Check Crash Bus Start
bool crash()
{
	cout << RANDOM_POINT << endl;
	if (Play)
	{
		if ((RANDOM_POINT<Top  && RANDOM_POINT>Bottom)&&(Left>=-0.85 && Right <=-0.85))
		{
			cout <<RANDOM_POINT<<"\t"<<Top<<"\t"<<Bottom<<endl;
			Play = false;
			return true;
		}
	}
	return false;
}
//Get Check Crash Bus End

//Set Top Count Start
void SET_COUNT()
{
	if(Count==1)
	{
		glBegin(GL_LINES);
		glVertex2f(0.91 + Num_Counter_w,0.98 + Num_Counter_h);
		glVertex2f(0.91 + Num_Counter_w, 0.92 + Num_Counter_h);
		glEnd();

		glBegin(GL_QUADS);
		glVertex2f(0.83, 0.95);
		glVertex2f(0.97, 0.95);
		glVertex2f(0.97, 0.85);
		glVertex2f(0.83, 0.85);
		glEnd();
	}
	else if(Count==2)
	{
		glBegin(GL_LINES);
		glVertex2f(0.9 + Num_Counter_w, 0.98 + Num_Counter_h);
		glVertex2f(0.93 + Num_Counter_w, 0.98 + Num_Counter_h);

		glVertex2f(0.93 + Num_Counter_w, 0.98 + Num_Counter_h);
		glVertex2f(0.93 + Num_Counter_w, 0.95 + Num_Counter_h);

		glVertex2f(0.93 + Num_Counter_w, 0.95 + Num_Counter_h);
		glVertex2f(0.9 + Num_Counter_w, 0.95 + Num_Counter_h);

		glVertex2f(0.9 + Num_Counter_w, 0.95 + Num_Counter_h);
		glVertex2f(0.9 + Num_Counter_w, 0.92 + Num_Counter_h);

		glVertex2f(0.9 + Num_Counter_w, 0.92 + Num_Counter_h);
		glVertex2f(0.93 + Num_Counter_w, 0.92 + Num_Counter_h);
		glEnd();

		glBegin(GL_QUADS);
		glVertex2f(0.83, 0.95);
		glVertex2f(0.97, 0.95);
		glVertex2f(0.97, 0.85);
		glVertex2f(0.83, 0.85);
		glEnd();
	}
	else if (Count == 3)
	{
		glBegin(GL_LINES);

		glVertex2f(0.9 + Num_Counter_w, 0.98 + Num_Counter_h);
		glVertex2f(0.93 + Num_Counter_w, 0.98 + Num_Counter_h);

		glVertex2f(0.93 + Num_Counter_w, 0.98 + Num_Counter_h);
		glVertex2f(0.93 + Num_Counter_w, 0.95 + Num_Counter_h);

		glVertex2f(0.93 + Num_Counter_w, 0.95 + Num_Counter_h);
		glVertex2f(0.9 + Num_Counter_w, 0.95 + Num_Counter_h);

		glVertex2f(0.93 + Num_Counter_w, 0.95 + Num_Counter_h);
		glVertex2f(0.93 + Num_Counter_w, 0.92 + Num_Counter_h);

		glVertex2f(0.93 + Num_Counter_w, 0.92 + Num_Counter_h);
		glVertex2f(0.9 + Num_Counter_w, 0.92 + Num_Counter_h);

		glEnd();

		glBegin(GL_QUADS);
		glVertex2f(0.83, 0.95);
		glVertex2f(0.97, 0.95);
		glVertex2f(0.97, 0.85);
		glVertex2f(0.83, 0.85);
		glEnd();
	}
	else if (Count == 4)
	{
		glBegin(GL_LINES);

		glVertex2f(0.9 + Num_Counter_w, 0.98 + Num_Counter_h);
		glVertex2f(0.9 + Num_Counter_w, 0.95 + Num_Counter_h);

		glVertex2f(0.93 + Num_Counter_w, 0.98 + Num_Counter_h);
		glVertex2f(0.93 + Num_Counter_w, 0.95 + Num_Counter_h);

		glVertex2f(0.93 + Num_Counter_w, 0.95 + Num_Counter_h);
		glVertex2f(0.9 + Num_Counter_w, 0.95 + Num_Counter_h);

		glVertex2f(0.93 + Num_Counter_w, 0.95 + Num_Counter_h);
		glVertex2f(0.93 + Num_Counter_w, 0.92 + Num_Counter_h);


		glEnd();

		glBegin(GL_QUADS);
		glVertex2f(0.83, 0.95);
		glVertex2f(0.97, 0.95);
		glVertex2f(0.97, 0.85);
		glVertex2f(0.83, 0.85);
		glEnd();
	}
	else if (Count == 5)
	{
		glBegin(GL_LINES);
		glVertex2f(0.9 + Num_Counter_w, 0.98 + Num_Counter_h);
		glVertex2f(0.93 + Num_Counter_w, 0.98 + Num_Counter_h);

		glVertex2f(0.9 + Num_Counter_w, 0.98 + Num_Counter_h);
		glVertex2f(0.9 + Num_Counter_w, 0.95 + Num_Counter_h);

		glVertex2f(0.9 + Num_Counter_w, 0.95 + Num_Counter_h);
		glVertex2f(0.93 + Num_Counter_w, 0.95 + Num_Counter_h);

		glVertex2f(0.93 + Num_Counter_w, 0.95 + Num_Counter_h);
		glVertex2f(0.93 + Num_Counter_w, 0.92 + Num_Counter_h);

		glVertex2f(0.93 + Num_Counter_w, 0.92 + Num_Counter_h);
		glVertex2f(0.9 + Num_Counter_w, 0.92 + Num_Counter_h);
		glEnd();

		glBegin(GL_QUADS);
		glVertex2f(0.83, 0.95);
		glVertex2f(0.97, 0.95);
		glVertex2f(0.97, 0.85);
		glVertex2f(0.83, 0.85);
		glEnd();
	}
	else if (Count == 6)
	{
		glBegin(GL_LINES);
		glVertex2f(0.9 + Num_Counter_w, 0.98 + Num_Counter_h);
		glVertex2f(0.93 + Num_Counter_w, 0.98 + Num_Counter_h);

		glVertex2f(0.9 + Num_Counter_w, 0.98 + Num_Counter_h);
		glVertex2f(0.9 + Num_Counter_w, 0.95 + Num_Counter_h);

		glVertex2f(0.9 + Num_Counter_w, 0.95 + Num_Counter_h);
		glVertex2f(0.93 + Num_Counter_w, 0.95 + Num_Counter_h);

		glVertex2f(0.93 + Num_Counter_w, 0.95 + Num_Counter_h);
		glVertex2f(0.93 + Num_Counter_w, 0.92 + Num_Counter_h);

		glVertex2f(0.93 + Num_Counter_w, 0.92 + Num_Counter_h);
		glVertex2f(0.9 + Num_Counter_w, 0.92 + Num_Counter_h);

		glVertex2f(0.9 + Num_Counter_w, 0.92 + Num_Counter_h);
		glVertex2f(0.9 + Num_Counter_w, 0.95 + Num_Counter_h);

		glEnd();

		glBegin(GL_QUADS);
		glVertex2f(0.83, 0.95);
		glVertex2f(0.97, 0.95);
		glVertex2f(0.97, 0.85);
		glVertex2f(0.83, 0.85);
		glEnd();
	}
	else if (Count == 7)
	{
		glBegin(GL_LINES);

		glVertex2f(0.93 + Num_Counter_w, 0.92 + Num_Counter_h);
		glVertex2f(0.93 + Num_Counter_w, 0.98 + Num_Counter_h);

		glVertex2f(0.9 + Num_Counter_w, 0.98 + Num_Counter_h);
		glVertex2f(0.93 + Num_Counter_w, 0.98 + Num_Counter_h);

		glEnd();

		glBegin(GL_QUADS);
		glVertex2f(0.83, 0.95);
		glVertex2f(0.97, 0.95);
		glVertex2f(0.97, 0.85);
		glVertex2f(0.83, 0.85);
		glEnd();
	}
	else if (Count == 8)
	{
		glBegin(GL_LINES);
		glVertex2f(0.9 + Num_Counter_w, 0.98 + Num_Counter_h);
		glVertex2f(0.93 + Num_Counter_w, 0.98 + Num_Counter_h);

		glVertex2f(0.93 + Num_Counter_w, 0.98 + Num_Counter_h);
		glVertex2f(0.93 + Num_Counter_w, 0.95 + Num_Counter_h);

		glVertex2f(0.9 + Num_Counter_w, 0.98 + Num_Counter_h);
		glVertex2f(0.9 + Num_Counter_w, 0.95 + Num_Counter_h);

		glVertex2f(0.9 + Num_Counter_w, 0.95 + Num_Counter_h);
		glVertex2f(0.93 + Num_Counter_w, 0.95 + Num_Counter_h);

		glVertex2f(0.93 + Num_Counter_w, 0.95 + Num_Counter_h);
		glVertex2f(0.93 + Num_Counter_w, 0.92 + Num_Counter_h);

		glVertex2f(0.93 + Num_Counter_w, 0.92 + Num_Counter_h);
		glVertex2f(0.9 + Num_Counter_w, 0.92 + Num_Counter_h);

		glVertex2f(0.9 + Num_Counter_w, 0.92 + Num_Counter_h);
		glVertex2f(0.9 + Num_Counter_w, 0.95 + Num_Counter_h);

		glEnd();

		glBegin(GL_QUADS);
		glVertex2f(0.83, 0.95);
		glVertex2f(0.97, 0.95);
		glVertex2f(0.97, 0.85);
		glVertex2f(0.83, 0.85);
		glEnd();
	}
	else if (Count == 9)
	{
		glBegin(GL_LINES);
		glVertex2f(0.93 + Num_Counter_w, 0.98 + Num_Counter_h);
		glVertex2f(0.9 + Num_Counter_w, 0.98 + Num_Counter_h);

		glVertex2f(0.93 + Num_Counter_w, 0.98 + Num_Counter_h);
		glVertex2f(0.93 + Num_Counter_w, 0.95 + Num_Counter_h);

		glVertex2f(0.93 + Num_Counter_w, 0.95 + Num_Counter_h);
		glVertex2f(0.9 + Num_Counter_w, 0.95 + Num_Counter_h);

		glVertex2f(0.9 + Num_Counter_w, 0.98 + Num_Counter_h);
		glVertex2f(0.9 + Num_Counter_w, 0.95 + Num_Counter_h);

		glVertex2f(0.9 + Num_Counter_w, 0.92 + Num_Counter_h);
		glVertex2f(0.93 + Num_Counter_w, 0.92 + Num_Counter_h);

		glVertex2f(0.93 + Num_Counter_w, 0.92 + Num_Counter_h);
		glVertex2f(0.93 + Num_Counter_w, 0.95 + Num_Counter_h);

		glEnd();

		glBegin(GL_QUADS);
		glVertex2f(0.83, 0.95);
		glVertex2f(0.97, 0.95);
		glVertex2f(0.97, 0.85);
		glVertex2f(0.83, 0.85);
		glEnd();
	}
	else if (Count == 10)
	{
		//0
		{
			glBegin(GL_LINES);
			glVertex2f(0.91 + Num_Counter_w, 0.98 + Num_Counter_h);
			glVertex2f(0.94 + Num_Counter_w, 0.98 + Num_Counter_h);

			glVertex2f(0.94 + Num_Counter_w, 0.98 + Num_Counter_h);
			glVertex2f(0.94 + Num_Counter_w, 0.95 + Num_Counter_h);

			glVertex2f(0.91 + Num_Counter_w, 0.98 + Num_Counter_h);
			glVertex2f(0.91 + Num_Counter_w, 0.95 + Num_Counter_h);

			glVertex2f(0.94 + Num_Counter_w, 0.95 + Num_Counter_h);
			glVertex2f(0.94 + Num_Counter_w, 0.92 + Num_Counter_h);

			glVertex2f(0.94 + Num_Counter_w, 0.92 + Num_Counter_h);
			glVertex2f(0.91 + Num_Counter_w, 0.92 + Num_Counter_h);

			glVertex2f(0.91 + Num_Counter_w, 0.92 + Num_Counter_h);
			glVertex2f(0.91 + Num_Counter_w, 0.95 + Num_Counter_h);

			glEnd();
		}
		//0

		//1
		{
			glBegin(GL_LINES);
			glVertex2f(0.89 + Num_Counter_w, 0.92 + Num_Counter_h);
			glVertex2f(0.89 + Num_Counter_w, 0.98 + Num_Counter_h);
			glEnd();
		}
		//1

		glBegin(GL_QUADS);
		glVertex2f(0.83, 0.95);
		glVertex2f(0.97, 0.95);
		glVertex2f(0.97, 0.85);
		glVertex2f(0.83, 0.85);
		glEnd();
	}
}
//Set Top Count End

//Display Render Function Start
void Display(void)
{
	//Get GLUT BUFFERS Start
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glColor3f(0.0, 0.0, 0.0);
	}
	//Get GLUT BUFFERS End	

	//Get Polygon Start
	{
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	}
	//Get Polygon End

	//Crash Check Start
	{
		if (crash())		
		{
			glLineWidth(1);
			glBegin(GL_LINES);

			//E Start
			{
				glVertex2f(-0.25, 0.1);
				glVertex2f(-0.25, -0.1);

				glVertex2f(-0.25, 0.1);
				glVertex2f(-0.15, 0.1);

				glVertex2f(-0.25, 0.0);
				glVertex2f(-0.15, 0.0);


				glVertex2f(-0.25, -0.1);
				glVertex2f(-0.15, -0.1);
			}
			//E End

			//N Start
			{
				glVertex2f(-0.1, 0.1);
				glVertex2f(-0.1, -0.1);

				glVertex2f(-0.1, 0.1);
				glVertex2f(0.02, -0.1);

				glVertex2f(0.02, -0.1);
				glVertex2f(0.02, 0.1);
			}
			//N End

			//D Start
			{
				glVertex2f(0.07, 0.1);
				glVertex2f(0.07, -0.1);

				glVertex2f(0.07, 0.1);
				glVertex2f(0.2, 0.1);

				glVertex2f(0.2, 0.1);
				glVertex2f(0.2, -0.1);

				glVertex2f(0.2, -0.1);
				glVertex2f(0.07, -0.1);
			}
			//D End

			glEnd();

			glFlush();
			return;
		}
	}
	//Crash Check End

	//Bus Start
	{
		//Ladder Start
		{
			//Get Top Line Start
			{
				glBegin(GL_LINES);
				glLineWidth(50);
				{
					//Top Line Start
					glVertex2f(0.85 + w, 0.7 + h);
					glVertex2f(-0.85 + w, 0.7 + h);
					//Top Line End

					//Bottom Line Start
					glVertex2f(-0.85 + w, 0.66 + h);
					glVertex2f(0.85 + w, 0.66 + h);
					//Bottom Line End
				}
				glEnd();

				//Left Top Start
				{

					glPointSize(2.0f);
					glBegin(GL_POINTS);
					double radius = 0.02;
					float x1 = 0.85 + w, y1 = 0.681 + h;
					for (float angle = 0.0f;angle < 3.0f;angle += 0.01)
					{
						float x2 = x1 + sin(angle) * radius;
						float y2 = y1 + cos(angle) * radius;
						glVertex2f(x2, y2);
					}
					glEnd();
				}
				//Left Top End

				//Right Top Start
				{

					glPointSize(2.0f);
					glBegin(GL_POINTS);
					double radius = 0.02;
					float x1 = -0.85 + w, y1 = 0.681 + h;
					for (float angle = -3.0f;angle < 0.0f;angle += 0.01)
					{
						float x2 = x1 + sin(angle) * radius;
						float y2 = y1 + cos(angle) * radius;
						glVertex2f(x2, y2);
					}
					glEnd();
				}
				//Right Top End
			}
			//Get Top Line End

			//Get Bottom Line Start
			{
				glBegin(GL_LINES);
				glLineWidth(50);
				{
					//Top Line Start
					glVertex2f(0.85 + w, 0.55 + h);
					glVertex2f(-0.85 + w, 0.55 + h);
					//Top Line End

					//Bottom Line Start
					glVertex2f(-0.85 + w, 0.51 + h);
					glVertex2f(0.85 + w, 0.51 + h);
					//Bottom Line End
				}
				glEnd();

				//Left Bottom Start
				{

					glPointSize(2.0f);
					glBegin(GL_POINTS);
					double radius = 0.02;
					float x1 = 0.85 + w, y1 = 0.53 + h;
					for (float angle = 0.0f;angle < 3.0f;angle += 0.01)
					{
						float x2 = x1 + sin(angle) * radius;
						float y2 = y1 + cos(angle) * radius;
						glVertex2f(x2, y2);
					}
					glEnd();
				}
				//Left Bottom End

				//Right Bottom Start
				{

					glPointSize(2.0f);
					glBegin(GL_POINTS);
					double radius = 0.02;
					float x1 = -0.85 + w, y1 = 0.53 + h;
					for (float angle = -3.0f;angle < 0.0f;angle += 0.01)
					{
						float x2 = x1 + sin(angle) * radius;
						float y2 = y1 + cos(angle) * radius;
						glVertex2f(x2, y2);
					}
					glEnd();
				}
				//Right Bottom End
			}
			//Get Bottom Line End

			//Between Lines Start
			{
				glLineWidth(3.0f);
				glBegin(GL_LINES);
				{
					//Frist Lines Start
					{
						//Left Start
						for (float left = -0.8;left <= 0.79;left += 0.2)
						{
							glVertex2f(left + w, 0.66 + h);
							glVertex2f(left + (0.2) + w, 0.55 + h);
						}
						//Left End

						//Left Start
						for (float left = -0.8;left <= 0.79;left += 0.2)
						{
							glVertex2f(left + w, 0.55 + h);
							glVertex2f(left + (0.2) + w, 0.66 + h);
						}
						//Left End

						//Right Start
						for (float Rigth = 0.8;Rigth >= -0.79;Rigth -= 0.2)
						{
							glVertex2f(Rigth + w, 0.66 + h);
							glVertex2f(Rigth - (0.2) + w, 0.55 + h);
						}
						//Right End

						//Right Start
						for (float Rigth = 0.8;Rigth >= -0.79;Rigth -= 0.2)
						{
							glVertex2f(Rigth + w, 0.55 + h);
							glVertex2f(Rigth - (0.2) + w, 0.66 + h);
						}
						//Right End
					}
					//Frist Lines End

					//Secend Lines Start
					{
						//Left Start
						for (float left = -0.8;left <= 0.79;left += 0.2)
						{
							glVertex2f((left + 0.05) + w, 0.66 + h);
							glVertex2f(left + (0.2 + 0.05) + w, 0.55 + h);
						}
						//Left End

						//Left Start
						for (float left = -0.8;left <= 0.79;left += 0.2)
						{
							glVertex2f((left + 0.05) + w, 0.55 + h);
							glVertex2f(left + (0.2 + 0.05) + w, 0.66 + h);
						}
						//Left End

						//Right Start
						for (float Rigth = 0.8;Rigth >= -0.79;Rigth -= 0.2)
						{
							glVertex2f((Rigth + 0.05) + w, 0.66 + h);
							glVertex2f((Rigth - 0.2 + 0.05) + w, 0.55 + h);
						}
						//Right End

					}
					//Secend Lines End

				}
				glEnd();
			}
			//Between Lines End

		}
		//Ladder End

		//Under Ladder Right Start
		{
			//Top Start
			{
				glBegin(GL_LINE_LOOP);
				glVertex2f(0.65 + w, 0.51 + h);
				glVertex2f(0.35 + w, 0.51 + h);
				glVertex2f(0.38 + w, 0.48 + h);
				glVertex2f(0.63 + w, 0.48 + h);
				glEnd();
			}
			//Top End

			//Bottom Start
			{
				glBegin(GL_LINE_LOOP);
				glVertex2f(0.78 + w, 0.48 + h);
				glVertex2f(0.2 + w, 0.48 + h);
				glVertex2f(0.2 + w, 0.435 + h);
				glVertex2f(0.78 + w, 0.435 + h);
				glEnd();
			}
			//Bottom End

			//Bottom 2 Start
			{
				glBegin(GL_QUADS);
				glVertex2f(0.92 + w, 0.435 + h);
				glVertex2f(0.02 + w, 0.435 + h);
				glVertex2f(0.02 + w, 0.40 + h);
				glVertex2f(0.92 + w, 0.40 + h);
				glEnd();
			}
			//Bottom 2 End
		}
		//Under Ladder Right End

		//Under Ladder Left Start
		{
			//Stand Ladder Start
			{
				//1
				{
					glBegin(GL_LINES);

					glVertex2f(-0.5 + w, 0.44 + h);
					glVertex2f(-0.51 + w, 0.53 + h);

					glVertex2f(-0.51 + w, 0.53 + h);
					glVertex2f(-0.56 + w, 0.53 + h);

					glVertex2f(-0.56 + w, 0.53 + h);
					glVertex2f(-0.575 + w, 0.44 + h);

					glEnd();
				}
				//1

				//2
				{
					glBegin(GL_LINES);

					//Bottom Start
					{
						glVertex2f(-0.72 + w, 0.44 + h);
						glVertex2f(-0.72 + w, 0.465 + h);

						glVertex2f(-0.72 + w, 0.465 + h);
						glVertex2f(-0.635 + w, 0.465 + h);

						glVertex2f(-0.635 + w, 0.465 + h);
						glVertex2f(-0.635 + w, 0.44 + h);
					}
					//Bottom End

					//Top Start
					{
						glVertex2f(-0.695 + w, 0.465 + h);
						glVertex2f(-0.695 + w, 0.49 + h);

						glVertex2f(-0.695 + w, 0.49 + h);
						glVertex2f(-0.66 + w, 0.49 + h);

						glVertex2f(-0.66 + w, 0.49 + h);
						glVertex2f(-0.66 + w, 0.465 + h);
					}
					//Top End

					glEnd();
				}
				//2
			}
			//Stand Ladder End
		}
		//Under Ladder Left End

		//Track Start
		{
			//Back Track Start
			{
				//Top Box Start
				{
					//Out Side Start
					{
						glBegin(GL_QUADS);
						glVertex2f(0.89 + w, 0.40 + h);
						glVertex2f(0.89 + w, 0.0 + h);
						glVertex2f(0.04 + w, 0.0 + h);
						glVertex2f(0.04 + w, 0.40 + h);
						glEnd();
					}
					//Out Side End

					//Inside Start
					{
						//Boxs Start
						{
							for (float a = 0.065; a < 0.7; a += 0.256)
							{
								glBegin(GL_QUADS);
								float Left = a;
								float Right = Left + 0.265;
								glVertex2f(Right + w, 0.035 + h);
								glVertex2f(Left + 0.03 + w, 0.035 + h);
								glVertex2f(Left + 0.03 + w, 0.37 + h);
								glVertex2f(Right + w, 0.37 + h);
								glEnd();

								Left = (Left + (0.256 / 2));
								glBegin(GL_QUADS);
								glVertex2f(Left + 0.0435 + w, 0.06 + h);
								glVertex2f(Left + w, 0.06 + h);
								glVertex2f(Left + w, 0.09 + h);
								glVertex2f(Left + 0.0435 + w, 0.09 + h);
								glEnd();
							}
						}
						//Boxs End
					}
					//Inside End

				}
				//Top Box End

				//Center Box Start
				{
					glBegin(GL_QUADS);
					glVertex2f(0.89 + w, -0.02 + h);
					glVertex2f(0.89 + w, 0.0 + h);
					glVertex2f(0.04 + w, 0.0 + h);
					glVertex2f(0.04 + w, -0.02 + h);
					glEnd();
				}
				//Center Box End

				//Box Start
				{
					glBegin(GL_LINES);
					//Right
					{
						glVertex2f(0.89 + w, -0.02 + h);
						glVertex2f(0.89 + w, -0.18 + h);
					}
					//Right

					//Right Lines
					{
						glVertex2f(0.89 + w, -0.18 + h);
						glVertex2f(0.91 + w, -0.18 + h);

						glVertex2f(0.91 + w, -0.18 + h);
						glVertex2f(0.91 + w, -0.26 + h);

						glVertex2f(0.91 + w, -0.26 + h);
						glVertex2f(0.83 + w, -0.26 + h);

						glVertex2f(0.83 + w, -0.26 + h);
						glVertex2f(0.83 + w, -0.18 + h);

						glVertex2f(0.83 + w, -0.18 + h);
						glVertex2f(0.89 + w, -0.18 + h);
					}
					//Right End

					//Left
					{
						glVertex2f(0.04 + w, -0.02 + h);
						glVertex2f(0.04 + w, -0.2 + h);
					}
					//Left

					//Left Lines
					{
						glVertex2f(0.04 + w, -0.2 + h);
						glVertex2f(0.06 + w, -0.2 + h);

						glVertex2f(0.06 + w, -0.2 + h);
						glVertex2f(0.06 + w, -0.23 + h);

						glVertex2f(0.06 + w, -0.23 + h);
						glVertex2f(0.04 + w, -0.23 + h);

						glVertex2f(0.04 + w, -0.23 + h);
						glVertex2f(0.04 + w, -0.25 + h);
					}
					//Left Lines

					//Bottom And Lines
					{
						glVertex2f(0.04 + w, -0.25 + h);
						glVertex2f(0.32 + w, -0.25 + h);

						glVertex2f(0.68 + w, -0.25 + h);
						glVertex2f(0.83 + w, -0.25 + h);
					}
					//Bottom And Lines

					glEnd();
				}
				//Box End

				//Bottom Loops Start
				{
					//Inside Cricle 1 Start
					{
						glPointSize(2.5f);
						glBegin(GL_POINTS);
						double radius = 0.18;
						float x1 = 0.5 + w, y1 = -0.25 + h;
						for (float angle = -1.55f;angle < 1.53f;angle += 0.01)
						{
							float x2 = x1 + sin(angle) * radius;
							float y2 = y1 + cos(angle) * radius;
							glVertex2f(x2, y2);
						}
						glEnd();
					}
					//Inside Cricle 1 End

					//Inside Cricle 2 Start
					{

						glPointSize(1.5f);
						glBegin(GL_POINTS);
						double radius = 0.212;
						float x1 = 0.5 + w, y1 = -0.25 + h;
						for (float angle = -1.55f;angle < 1.53f;angle += 0.01)
						{
							float x2 = x1 + sin(angle) * radius;
							float y2 = y1 + cos(angle) * radius;
							glVertex2f(x2, y2);
						}
						glEnd();
					}
					//Inside Cricle 2 End

					//Inside Cricle 3 Start
					{

						glPointSize(2.5f);
						glBegin(GL_POINTS);
						double radius = 0.15;
						float x1 = 0.5 + w, y1 = -0.25 + h;
						for (float angle = -1.55f;angle < 5.0f;angle += 0.01)
						{
							float x2 = x1 + sin(angle) * radius;
							float y2 = y1 + cos(angle) * radius;
							glVertex2f(x2, y2);
						}
						glEnd();
					}
					//Inside Cricle 3 End

					//Inside Cricle 4 Start
					{

						glPointSize(0.5f);
						glBegin(GL_POINTS);
						double radius = 0.06;
						float x1 = 0.5 + w, y1 = -0.25 + h;
						for (float angle = -1.55f;angle < 5.0f;angle += 0.01)
						{
							float x2 = x1 + sin(angle) * radius;
							float y2 = y1 + cos(angle) * radius;
							glVertex2f(x2, y2);
						}
						glEnd();
					}
					//Inside Cricle 4 End

					//Inside Cricle 4 Start
					{

						glPointSize(0.5f);
						glBegin(GL_POINTS);
						double radius = 0.04;
						float x1 = 0.5 + w, y1 = -0.25 + h;
						for (float angle = -1.55f;angle < 5.0f;angle += 0.01)
						{
							float x2 = x1 + sin(angle) * radius;
							float y2 = y1 + cos(angle) * radius;
							glVertex2f(x2, y2);
						}
						glEnd();
					}
					//Inside Cricle 4 End

					//Inside Cricle 5 Start
					{

						glPointSize(0.5f);
						glBegin(GL_POINTS);
						double radius = 0.02;
						float x1 = 0.5 + w, y1 = -0.25 + h;
						for (float angle = -1.55f;angle < 5.0f;angle += 0.01)
						{
							float x2 = x1 + sin(angle) * radius;
							float y2 = y1 + cos(angle) * radius;
							glVertex2f(x2, y2);
						}
						glEnd();
					}
					//Inside Cricle 5 End

				}
				//Bottom Loops End
			}
			//Back Track End

			//Center Track Start
			{
				//Top Start
				{
					glBegin(GL_QUADS);
					glVertex2f(0.04 + w, 0.385 + h);
					glVertex2f(-0.3 + w, 0.385 + h);
					glVertex2f(-0.3 + w, 0.325 + h);
					glVertex2f(0.04 + w, 0.325 + h);
					glEnd();
				}
				//Top End

				//Center Top Start
				{
					//Boarder Start
					{
						glBegin(GL_QUADS);
						glVertex2f(0.04 + w, 0.325 + h);
						glVertex2f(-0.3 + w, 0.325 + h);
						glVertex2f(-0.3 + w, 0.08 + h);
						glVertex2f(0.04 + w, 0.08 + h);
						glEnd();
					}
					//Boarder End

					//Inside Start
					{
						glBegin(GL_QUADS);
						glVertex2f(-0.28 + w, 0.3 + h);
						glVertex2f(-0.14 + w, 0.3 + h);
						glVertex2f(-0.14 + w, 0.105 + h);
						glVertex2f(-0.28 + w, 0.105 + h);
						glEnd();

						glBegin(GL_QUADS);
						glVertex2f(-0.12 + w, 0.3 + h);
						glVertex2f(0.02 + w, 0.3 + h);
						glVertex2f(0.02 + w, 0.105 + h);
						glVertex2f(-0.12 + w, 0.105 + h);
						glEnd();
					}
					//Inside End
				}
				//Center Top End

				//Center Bottom Start
				{
					//Boarder Start
					{
						glBegin(GL_QUADS);
						glVertex2f(0.04 + w, 0.08 + h);
						glVertex2f(-0.3 + w, 0.08 + h);
						glVertex2f(-0.3 + w, -0.20 + h);
						glVertex2f(0.04 + w, -0.20 + h);
						glEnd();
					}
					//Boarder End

					//Inside Start
					{
						//Top
						{
							//Cricle 1 Start
							{

								glPointSize(3.0f);
								glBegin(GL_POINTS);
								double radius = 0.035;
								float x1 = -0.015 + w, y1 = 0.0 + h;
								for (float angle = -1.55f;angle < 5.0f;angle += 0.01)
								{
									float x2 = x1 + sin(angle) * radius;
									float y2 = y1 + cos(angle) * radius;
									glVertex2f(x2, y2);
								}
								glEnd();
							}
							//Cricle 1 End

							//Cricle 2 Start
							{

								glPointSize(3.0f);
								glBegin(GL_POINTS);
								double radius = 0.035;
								float x1 = -0.13 + w, y1 = 0.0 + h;
								for (float angle = -1.55f;angle < 5.0f;angle += 0.01)
								{
									float x2 = x1 + sin(angle) * radius;
									float y2 = y1 + cos(angle) * radius;
									glVertex2f(x2, y2);
								}
								glEnd();
							}
							//Cricle 2 End

							//Cricle 3 Start
							{

								glPointSize(3.0f);
								glBegin(GL_POINTS);
								double radius = 0.035;
								float x1 = -0.245 + w, y1 = 0.0 + h;
								for (float angle = -1.55f;angle < 5.0f;angle += 0.01)
								{
									float x2 = x1 + sin(angle) * radius;
									float y2 = y1 + cos(angle) * radius;
									glVertex2f(x2, y2);
								}
								glEnd();
							}
							//Cricle 3 End
						}
						//Top

						//Bottom
						{
							//Cricle 1 Start
							{

								glPointSize(3.0f);
								glBegin(GL_POINTS);
								double radius = 0.035;
								float x1 = -0.015 + w, y1 = -0.11 + h;
								for (float angle = -1.55f;angle < 5.0f;angle += 0.01)
								{
									float x2 = x1 + sin(angle) * radius;
									float y2 = y1 + cos(angle) * radius;
									glVertex2f(x2, y2);
								}
								glEnd();
							}
							//Cricle 1 End

							//Cricle 2 Start
							{

								glPointSize(3.0f);
								glBegin(GL_POINTS);
								double radius = 0.035;
								float x1 = -0.13 + w, y1 = -0.11 + h;
								for (float angle = -1.55f;angle < 5.0f;angle += 0.01)
								{
									float x2 = x1 + sin(angle) * radius;
									float y2 = y1 + cos(angle) * radius;
									glVertex2f(x2, y2);
								}
								glEnd();
							}
							//Cricle 2 End

							//Cricle 3 Start
							{

								glPointSize(3.0f);
								glBegin(GL_POINTS);
								double radius = 0.035;
								float x1 = -0.245 + w, y1 = -0.11 + h;
								for (float angle = -1.55f;angle < 5.0f;angle += 0.01)
								{
									float x2 = x1 + sin(angle) * radius;
									float y2 = y1 + cos(angle) * radius;
									glVertex2f(x2, y2);
								}
								glEnd();
							}
							//Cricle 3 End
						}
						//Bottom
					}
					//Inside End
				}
				//Center Bottom End

				//Bottom Start
				{
					glBegin(GL_LINES);
					glVertex2f(-0.3 + w, -0.23 + h);
					glVertex2f(0.04 + w, -0.23 + h);
					glEnd();
				}
				//Bottom End
			}
			//Center Track End

			//Front Track Start
			{
				//Main Boarder Start
				{
					//Top Line Start
					{
						glBegin(GL_LINES);
						glVertex2f(-0.78 + w, 0.435 + h);
						glVertex2f(-0.3 + w, 0.435 + h);
						glEnd();
					}
					//Top Line End

					//Right Lines Start
					{
						glBegin(GL_LINES);
						glVertex2f(-0.3 + w, 0.435 + h);
						glVertex2f(-0.3 + w, -0.2 + h);

						glVertex2f(-0.32 + w, -0.2 + h);
						glVertex2f(-0.3 + w, -0.2 + h);

						glVertex2f(-0.32 + w, -0.2 + h);
						glVertex2f(-0.32 + w, -0.23 + h);

						glVertex2f(-0.32 + w, -0.23 + h);
						glVertex2f(-0.3 + w, -0.23 + h);

						glVertex2f(-0.3 + w, -0.23 + h);
						glVertex2f(-0.3 + w, -0.25 + h);
						glEnd();
					}
					//Right Lines End

					//Bottom Lines Start
					{
						//Bottom Lines Start
						{
							glBegin(GL_LINES);

							//Right Loops Start
							{
								glVertex2f(-0.3 + w, -0.25 + h);
								glVertex2f(-0.4 + w, -0.25 + h);
							}
							//Right Loops End

							//Left Loops Start
							{
								glVertex2f(-0.755 + w, -0.25 + h);
								glVertex2f(-0.83 + w, -0.25 + h);
							}
							//Left Loops End

							//Bottom Left Loops Start
							{
								glVertex2f(-0.83 + w, -0.25 + h);
								glVertex2f(-0.83 + w, -0.25 + h);
							}
							//Bottom Left Loops End

							glEnd();
						}
						//Bottom Lines End

						//Bottom Loops Start
						{
							//Inside Cricle 1 Start
							{

								glPointSize(2.5f);
								glBegin(GL_POINTS);
								double radius = 0.18;
								float x1 = -0.58 + w, y1 = -0.25 + h;
								for (float angle = -1.55f;angle < 1.53f;angle += 0.01)
								{
									float x2 = x1 + sin(angle) * radius;
									float y2 = y1 + cos(angle) * radius;
									glVertex2f(x2, y2);
								}
								glEnd();
							}
							//Inside Cricle 1 End

							//Inside Cricle 2 Start
							{

								glPointSize(1.5f);
								glBegin(GL_POINTS);
								double radius = 0.212;
								float x1 = -0.58 + w, y1 = -0.25 + h;
								for (float angle = -1.55f;angle < 1.53f;angle += 0.01)
								{
									float x2 = x1 + sin(angle) * radius;
									float y2 = y1 + cos(angle) * radius;
									glVertex2f(x2, y2);
								}
								glEnd();
							}
							//Inside Cricle 2 End

							//Inside Cricle 3 Start
							{

								glPointSize(2.5f);
								glBegin(GL_POINTS);
								double radius = 0.15;
								float x1 = -0.58 + w, y1 = -0.25 + h;
								for (float angle = -1.55f;angle < 5.0f;angle += 0.01)
								{
									float x2 = x1 + sin(angle) * radius;
									float y2 = y1 + cos(angle) * radius;
									glVertex2f(x2, y2);
								}
								glEnd();
							}
							//Inside Cricle 3 End

							//Inside Cricle 4 Start
							{

								glPointSize(0.5f);
								glBegin(GL_POINTS);
								double radius = 0.06;
								float x1 = -0.58 + w, y1 = -0.25 + h;
								for (float angle = -1.55f;angle < 5.0f;angle += 0.01)
								{
									float x2 = x1 + sin(angle) * radius;
									float y2 = y1 + cos(angle) * radius;
									glVertex2f(x2, y2);
								}
								glEnd();
							}
							//Inside Cricle 4 End

							//Inside Cricle 4 Start
							{

								glPointSize(0.5f);
								glBegin(GL_POINTS);
								double radius = 0.04;
								float x1 = -0.58 + w, y1 = -0.25 + h;
								for (float angle = -1.55f;angle < 5.0f;angle += 0.01)
								{
									float x2 = x1 + sin(angle) * radius;
									float y2 = y1 + cos(angle) * radius;
									glVertex2f(x2, y2);
								}
								glEnd();
							}
							//Inside Cricle 4 End

							//Inside Cricle 5 Start
							{

								glPointSize(0.5f);
								glBegin(GL_POINTS);
								double radius = 0.02;
								float x1 = -0.58 + w, y1 = -0.25 + h;
								for (float angle = -1.55f;angle < 5.0f;angle += 0.01)
								{
									float x2 = x1 + sin(angle) * radius;
									float y2 = y1 + cos(angle) * radius;
									glVertex2f(x2, y2);
								}
								glEnd();
							}
							//Inside Cricle 5 End
						}
						//Bottom Loops End
					}
					//Bottom Lines End

					//Left Lines Start
					{
						//Bottom Left Start
						{
							glBegin(GL_LINES);

							glVertex2f(-0.83 + w, -0.25 + h);
							glVertex2f(-0.83 + w, -0.26 + h);

							glVertex2f(-0.83 + w, -0.26 + h);
							glVertex2f(-0.92 + w, -0.26 + h);

							glVertex2f(-0.92 + w, -0.26 + h);
							glVertex2f(-0.92 + w, -0.18 + h);

							glVertex2f(-0.92 + w, -0.18 + h);
							glVertex2f(-0.83 + w, -0.18 + h);

							glVertex2f(-0.83 + w, -0.18 + h);
							glVertex2f(-0.83 + w, -0.26 + h);

							glEnd();
						}
						//Bottom Left End

						//Light Start
						{
							//Boarder Start
							{
								glBegin(GL_LINES);

								glVertex2f(-0.86 + w, -0.18 + h);
								glVertex2f(-0.86 + w, -0.0 + h);

								glVertex2f(-0.86 + w, -0.0 + h);
								glVertex2f(-0.91 + w, 0.03 + h);

								glVertex2f(-0.91 + w, 0.03 + h);
								glVertex2f(-0.91 + w, -0.18 + h);

								glEnd();
							}
							//Boarder End

							//Inside Start
							{
								glLineWidth(1);
								glBegin(GL_LINES);
								for (float a = 0.0;a > -0.18;a -= 0.01)
								{
									glVertex2f(-0.86 + w, a + h);
glVertex2f(-0.91 + w, a + h);
								}
								glEnd();
								glLineWidth(3.0f);
							}
							//Inside End
						}
						//Light End

					}
					//Left Lines End

					//Windows Start
					{
					//Front Window Start
						{
							glBegin(GL_LINES);

							glVertex2f(-0.91 + w, 0.03 + h);
							glVertex2f(-0.78 + w, 0.435 + h);

							glVertex2f(-0.85 + w, 0.13 + h);
							glVertex2f(-0.766 + w, 0.385 + h);

							glVertex2f(-0.766 + w, 0.385 + h);
							glVertex2f(-0.79 + w, 0.385 + h);

							glVertex2f(-0.85 + w, 0.13 + h);
							glVertex2f(-0.884 + w, 0.13 + h);

							glEnd();
						}
						//Front Window End

						//Center Window Start
						{
							glBegin(GL_LINES);

							glVertex2f(-0.82 + w, 0.13 + h);
							glVertex2f(-0.736 + w, 0.385 + h);

							glVertex2f(-0.736 + w, 0.385 + h);
							glVertex2f(-0.55 + w, 0.385 + h);

							glVertex2f(-0.55 + w, 0.13 + h);
							glVertex2f(-0.55 + w, 0.385 + h);

							glVertex2f(-0.55 + w, 0.13 + h);
							glVertex2f(-0.82 + w, 0.13 + h);

							glEnd();

						}
						//Center Window End

						//Back Window Start
						{
							glBegin(GL_LINES);

							glVertex2f(-0.52 + w, 0.13 + h);
							glVertex2f(-0.52 + w, 0.385 + h);

							glVertex2f(-0.52 + w, 0.385 + h);
							glVertex2f(-0.33 + w, 0.385 + h);

							glVertex2f(-0.33 + w, 0.385 + h);
							glVertex2f(-0.33 + w, 0.13 + h);

							glVertex2f(-0.33 + w, 0.13 + h);
							glVertex2f(-0.52 + w, 0.13 + h);

							glEnd();

						}
						//Back Window End
					}
					//Windows End

					//Double Lines On Inside Start
					{
						glBegin(GL_QUADS);
						glVertex2f(-0.86 + w, -0.02 + h);
						glVertex2f(-0.86 + w, 0.0 + h);
						glVertex2f(-0.3 + w, 0.0 + h);
						glVertex2f(-0.3 + w, -0.02 + h);
						glEnd();
					}
					//Double Lines On Inside End

				}
				//Main Boarder End
			}
			//Front Track End

		}
		//Track End
	}
	//Bus End

	//Get Block Start
	{
		if (Play)
			{
				if (Generate_Block)
				{
					float point1 = (1.0 + rand()) / RAND_MAX;
					float point2 = (1.0 - rand()) / RAND_MAX;
					float point = (abs(point1) < abs(point2)) ? point1 : point2;
					RANDOM_POINT = point;
					Generate_Block = false;
				}
				glPointSize(100);
				glBegin(GL_POINTS);
				glColor3f(0.0f, 0.0f, 0.0f);
				glVertex2f(-0.85, RANDOM_POINT);
				glEnd();
			}
	}	
	//Get Block End

	//Bus Area Start
	{
		/*glBegin(GL_QUADS);
		glVertex2f(Right,Top);
		glVertex2f(Left, Top);
		glVertex2f(Left, Bottom);
		glVertex2f(Right, Bottom);
		glEnd();*/
	}
	//Bus Area End

	//Set Count Start
	{
		SET_COUNT();
	}
	//Set Count End

	glFlush();
}
//Display Render Function End

//Setup For Start
void setup()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
}
//Setup For Start 

//Main Animation Timer Start
void Loop(int x)
{
	//Return Shape Start
	{
		//Exit From Left Start
		{
			if (w < -2.0)
			{
				//Change Car Posotion Start
				w = 2.0;
				Right = 1.085;
				Left = 2.915;
				//Change Car Posotion End


				//Car Speed On Exit From Window Time Start
				if (Can_Speed_Up)
				{
					if (Carspeed == 0)
					{
						Can_Speed_Up = false;
					}

					if (Carspeed >= 1)
					{
						Carspeed-=2.9;
					}
					Generate_Block = true;
					Count ++;
					cout << Count << endl;
				}
				//Car Speed On Exit From Window Time End
			}
		}
		//Exit From Left End

		//Up And Bottom Display Exit Event Start
		{
			if (h < -2.0)
			{
				h = 2.0;

				Top = 2.7;
				Bottom = 1.6;
			}

			if (h > 2.0)
			{
				h = -2.0;

				Top = -1.3;
				Bottom = -2.4;
			}
		}
		//Up And Bottom Display Exit Event End
	}
	//Return Shape End

	//Action Bus Start
	{
		if (back)
		{
			h += 0.00;
			w += 0.01;
			Top += 0.00;
			Bottom += 0.00;
			Left += 0.01;
			Right += 0.01;

			if (w > 0.9)
			{
				back = false;

				glutPostRedisplay();
				glutTimerFunc(1000, Loop, 0);

				return;
			}
		}
		else
		{
			h += 0.00;
			w -= 0.01;

			Top += 0.00;
			Bottom += 0.00;
			Left -= 0.01;
			Right -= 0.01;

		}
	}
	//Action Bus End

	//Functions For Actions Start
	if(Can_Speed_Up && Play)
	{
		glutPostRedisplay();
		glutTimerFunc(Carspeed, Loop, 0);
	}
	//Functions For Actions End

}
//Main Animation Timer End

//Menu Start
void MENU(int Value)
{
	switch (Value)
	{
	case 0:
		exit(0);
		break;
	default:
		Count = 0;
		Play = true;
		back = true;
		Top = 0.7, Bottom = -0.4, Left = -0.615, Right = 1.215;
		h = 0.0, w = 0.3;
		glutTimerFunc(1, Loop, 0);
		break;
	}
	glutPostRedisplay();
}
//Menu End

//Menu Generator Start
void MENU_GENERATOR()
{
	glutCreateMenu(MENU);
	glutAddMenuEntry("Start/Restart", 1);
	glutAddMenuEntry("Exit", 0);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}
//Menu Generator End

//Reshape Function Start
void Reshape(int x, int y)
{
	glMatrixMode(GL_MODELVIEW);
}
//Reshape Function End

//KeyBoard Event For Spicial Keys Start
void KEYBOARD_SPC(int Key, int x, int y)
{
	//Use Arrow Keys For Event Start
	switch (Key)
	{
	case 101:
		h += 0.1;
		Top += 0.1;
		Bottom += 0.1;
		Left += 0.00;
		Right += 0.00;
		break;
	case 103:
		h -= 0.1;
		Top -= 0.1;
		Bottom -= 0.1;
		Left += 0.00;
		Right += 0.00;
		break;
	case 102:
		w += 0.1;
		Top += 0.00;
		Bottom += 0.00;
		Left += 0.1;
		Right += 0.1;
		break;
	case 100:
		w -= 0.1;
		Top += 0.00;
		Bottom += 0.00;
		Left -= 0.1;
		Right -= 0.1;
		break;
	}
	//Use Arrow Keys For Event End
	glutPostRedisplay();
}
//KeyBoard Event For Spicial Keys End

//Timer For Mouse Event Start
void MOUSE_TIMER(int x)
{
	MOUSE_X = 0;
}
//Timer For Mouse Event End

//Mouse Main Event Function Start
void MOUSE(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON)
	{
		if (MOUSE_X != 0)
		{
			if (MOUSE_X < x)
			{
				glutTimerFunc(1, Loop, 0);
				return;
			}
		}
		glutTimerFunc(500, MOUSE_TIMER, 0);
		MOUSE_X = x;
	}
}
//Mouse Main Event Function End

//Main Function Start
int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(700, 700);
	glutCreateWindow("Reza Fta");
	glutDisplayFunc(Display);
	glutReshapeFunc(Reshape);
	glutMouseFunc(MOUSE);
	glutSpecialFunc(KEYBOARD_SPC);	
	setup();
	MENU_GENERATOR();
	glutMainLoop();
	return 0;
}
//Main Function End