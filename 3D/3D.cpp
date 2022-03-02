#include "stdafx.h"
#include <iostream>
#include "GL\glut.h"
#include "math.h"

using namespace std;

//Global Variables Start
float h = 0.0, w = 0.0;
float wh = 0.0, ww = 0.0;
float bh = -0.9, bw = -0.9;
bool back = true;
bool Keyboard_Key_Pressed = false;
int Timer_Counter = 0;
int MOUSE_X = 0;
int POLYGUN = 0;
GLfloat light0_position[] = { 0,0,0,0 };
//Global Variables End

//Called when a key is pressed
void handleKeypress(unsigned char key, int x, int y) {
	switch (key) {
	case 27: //Escape key
		exit(0);
	}
}

//Initializes 3D rendering
void initRendering() {
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING); //Enable lighting
	glEnable(GL_LIGHT0); //Enable light #0
	glEnable(GL_LIGHT1); //Enable light #1
	glEnable(GL_NORMALIZE); //Automatically normalize normals
							//glShadeModel(GL_SMOOTH); //Enable smooth shading
}

//Called when the window is resized
void handleResize(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
}

float _angle = -70.0f;

//Draws the 3D scene
void drawScene() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(0.0f, 0.0f, -8.0f);

	//Add ambient light
	GLfloat ambientColor[] = { 0.2f, 0.2f, 0.2f, 1.0f }; //Color (0.2, 0.2, 0.2)
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);

	//Add positioned light
	GLfloat lightColor0[] = { 0.5f, 0.5f, 0.5f, 1.0f }; //Color (0.5, 0.5, 0.5)
	GLfloat lightPos0[] = { 4.0f, 0.0f, 8.0f, 1.0f }; //Positioned at (4, 0, 8)
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor0);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);

	//Add directed light
	GLfloat lightColor1[] = { 0.5f, 0.2f, 0.2f, 1.0f }; //Color (0.5, 0.2, 0.2)
														//Coming from the direction (-1, 0.5, 0.5)
	GLfloat lightPos1[] = { -1.0f, 0.5f, 0.5f, 0.0f };
	glLightfv(GL_LIGHT1, GL_DIFFUSE, lightColor1);
	glLightfv(GL_LIGHT1, GL_POSITION, lightPos1);

	glRotatef(_angle, 0.0f, 1.0f, 0.0f);
	glColor3f(1.0f, 1.0f, 0.0f);
	
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
					glVertex3f(0.85 + w, 0.7 + h, 0);
					glVertex3f(-0.85 + w, 0.7 + h, 0);
					//Top Line End

					//Bottom Line Start
					glVertex3f(-0.85 + w, 0.66 + h, 0);
					glVertex3f(0.85 + w, 0.66 + h, 0);
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
						glVertex3f(x2, y2,1.0f);
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
						glVertex3f(x2, y2,1.0f);
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
					glVertex3f(0.85 + w, 0.55  + h,1.0f);
					glVertex3f(-0.85 + w, 0.55  + h,1.0f);
					//Top Line End

					//Bottom Line Start
					glVertex3f(-0.85 + w, 0.51  + h,1.0f);
					glVertex3f(0.85 + w, 0.51  + h,1.0f);
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
						glVertex3f(x2, y2,1.0f);
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
						glVertex3f(x2, y2,1.0f);
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
							glVertex3f(left + w, 0.66  + h,1.0f);
							glVertex3f(left + (0.2) + w, 0.55  + h,1.0f);
						}
						//Left End

						//Left Start
						for (float left = -0.8;left <= 0.79;left += 0.2)
						{
							glVertex3f(left + w, 0.55  + h,1.0f);
							glVertex3f(left + (0.2) + w, 0.66  + h,1.0f);
						}
						//Left End

						//Right Start
						for (float Rigth = 0.8;Rigth >= -0.79;Rigth -= 0.2)
						{
							glVertex3f(Rigth + w, 0.66  + h,1.0f);
							glVertex3f(Rigth - (0.2) + w, 0.55  + h,1.0f);
						}
						//Right End

						//Right Start
						for (float Rigth = 0.8;Rigth >= -0.79;Rigth -= 0.2)
						{
							glVertex3f(Rigth + w, 0.55  + h,1.0f);
							glVertex3f(Rigth - (0.2) + w, 0.66  + h,1.0f);
						}
						//Right End
					}
					//Frist Lines End

					//Secend Lines Start
					{
						//Left Start
						for (float left = -0.8;left <= 0.79;left += 0.2)
						{
							glVertex3f((left + 0.05) + w, 0.66  + h,1.0f);
							glVertex3f(left + (0.2 + 0.05) + w, 0.55  + h,1.0f);
						}
						//Left End

						//Left Start
						for (float left = -0.8;left <= 0.79;left += 0.2)
						{
							glVertex3f((left + 0.05) + w, 0.55  + h,1.0f);
							glVertex3f(left + (0.2 + 0.05) + w, 0.66  + h,1.0f);
						}
						//Left End

						//Right Start
						for (float Rigth = 0.8;Rigth >= -0.79;Rigth -= 0.2)
						{
							glVertex3f((Rigth + 0.05) + w, 0.66  + h,1.0f);
							glVertex3f((Rigth - 0.2 + 0.05) + w, 0.55  + h,1.0f);
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
				glVertex3f(0.65 + w, 0.51  + h,1.0f);
				glVertex3f(0.35 + w, 0.51  + h,1.0f);
				glVertex3f(0.38 + w, 0.48  + h,1.0f);
				glVertex3f(0.63 + w, 0.48  + h,1.0f);
				glEnd();
			}
			//Top End

			//Bottom Start
			{
				glBegin(GL_LINE_LOOP);
				glVertex3f(0.78 + w, 0.48  + h,1.0f);
				glVertex3f(0.2 + w, 0.48  + h,1.0f);
				glVertex3f(0.2 + w, 0.435  + h,1.0f);
				glVertex3f(0.78 + w, 0.435  + h,1.0f);
				glEnd();
			}
			//Bottom End

			//Bottom 2 Start
			{
				glBegin(GL_QUADS);
				glVertex3f(0.92 + w, 0.435 + h, 0.5);
				glVertex3f(0.02 + w, 0.435 + h, 0.5);
				glVertex3f(0.02 + w, 0.40 + h, 0.5);
				glVertex3f(0.92 + w, 0.40 + h, 0.5);
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

					glVertex3f(-0.5 + w, 0.44  + h,1.0f);
					glVertex3f(-0.51 + w, 0.53  + h,1.0f);

					glVertex3f(-0.51 + w, 0.53  + h,1.0f);
					glVertex3f(-0.56 + w, 0.53  + h,1.0f);

					glVertex3f(-0.56 + w, 0.53  + h,1.0f);
					glVertex3f(-0.575 + w, 0.44  + h,1.0f);

					glEnd();
				}
				//1

				//2
				{
					glBegin(GL_LINES);

					//Bottom Start
					{
						glVertex3f(-0.72 + w, 0.44  + h,1.0f);
						glVertex3f(-0.72 + w, 0.465  + h,1.0f);

						glVertex3f(-0.72 + w, 0.465  + h,1.0f);
						glVertex3f(-0.635 + w, 0.465  + h,1.0f);

						glVertex3f(-0.635 + w, 0.465  + h,1.0f);
						glVertex3f(-0.635 + w, 0.44  + h,1.0f);
					}
					//Bottom End

					//Top Start
					{
						glVertex3f(-0.695 + w, 0.465  + h,1.0f);
						glVertex3f(-0.695 + w, 0.49  + h,1.0f);

						glVertex3f(-0.695 + w, 0.49  + h,1.0f);
						glVertex3f(-0.66 + w, 0.49  + h,1.0f);

						glVertex3f(-0.66 + w, 0.49  + h,1.0f);
						glVertex3f(-0.66 + w, 0.465  + h,1.0f);
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
						glVertex3f(0.89 + w, 0.40  + h,1.0f);
						glVertex3f(0.89 + w, 0.0  + h,1.0f);
						glVertex3f(0.04 + w, 0.0  + h,1.0f);
						glVertex3f(0.04 + w, 0.40  + h,1.0f);
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
								glVertex3f(Right + w, 0.035  + h,1.0f);
								glVertex3f(Left + 0.03 + w, 0.035  + h,1.0f);
								glVertex3f(Left + 0.03 + w, 0.37  + h,1.0f);
								glVertex3f(Right + w, 0.37  + h,1.0f);
								glEnd();

								Left = (Left + (0.256 / 2));
								glBegin(GL_QUADS);
								glVertex3f(Left + 0.0435 + w, 0.06  + h,1.0f);
								glVertex3f(Left + w, 0.06  + h,1.0f);
								glVertex3f(Left + w, 0.09  + h,1.0f);
								glVertex3f(Left + 0.0435 + w, 0.09  + h,1.0f);
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
					glVertex3f(0.89 + w, -0.02  + h,1.0f);
					glVertex3f(0.89 + w, 0.0  + h,1.0f);
					glVertex3f(0.04 + w, 0.0  + h,1.0f);
					glVertex3f(0.04 + w, -0.02  + h,1.0f);
					glEnd();
				}
				//Center Box End

				//Box Start
				{
					glBegin(GL_LINES);
					//Right
					{
						glVertex3f(0.89 + w, -0.02  + h,1.0f);
						glVertex3f(0.89 + w, -0.18  + h,1.0f);
					}
					//Right

					//Right Lines
					{
						glVertex3f(0.89 + w, -0.18  + h,1.0f);
						glVertex3f(0.91 + w, -0.18  + h,1.0f);

						glVertex3f(0.91 + w, -0.18  + h,1.0f);
						glVertex3f(0.91 + w, -0.26  + h,1.0f);

						glVertex3f(0.91 + w, -0.26  + h,1.0f);
						glVertex3f(0.83 + w, -0.26  + h,1.0f);

						glVertex3f(0.83 + w, -0.26  + h,1.0f);
						glVertex3f(0.83 + w, -0.18  + h,1.0f);

						glVertex3f(0.83 + w, -0.18  + h,1.0f);
						glVertex3f(0.89 + w, -0.18  + h,1.0f);
					}
					//Right End

					//Left
					{
						glVertex3f(0.04 + w, -0.02  + h,1.0f);
						glVertex3f(0.04 + w, -0.2  + h,1.0f);
					}
					//Left

					//Left Lines
					{
						glVertex3f(0.04 + w, -0.2  + h,1.0f);
						glVertex3f(0.06 + w, -0.2  + h,1.0f);

						glVertex3f(0.06 + w, -0.2  + h,1.0f);
						glVertex3f(0.06 + w, -0.23  + h,1.0f);

						glVertex3f(0.06 + w, -0.23  + h,1.0f);
						glVertex3f(0.04 + w, -0.23  + h,1.0f);

						glVertex3f(0.04 + w, -0.23  + h,1.0f);
						glVertex3f(0.04 + w, -0.25  + h,1.0f);
					}
					//Left Lines

					//Bottom And Lines
					{
						glVertex3f(0.04 + w, -0.25  + h,1.0f);
						glVertex3f(0.32 + w, -0.25  + h,1.0f);

						glVertex3f(0.68 + w, -0.25  + h,1.0f);
						glVertex3f(0.83 + w, -0.25  + h,1.0f);
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
							glVertex3f(x2, y2,1.0f);
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
							glVertex3f(x2, y2,1.0f);
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
							glVertex3f(x2, y2,1.0f);
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
							glVertex3f(x2, y2,1.0f);
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
							glVertex3f(x2, y2,1.0f);
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
							glVertex3f(x2, y2,1.0f);
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
					glVertex3f(0.04 + w, 0.385  + h,1.0f);
					glVertex3f(-0.3 + w, 0.385  + h,1.0f);
					glVertex3f(-0.3 + w, 0.325  + h,1.0f);
					glVertex3f(0.04 + w, 0.325  + h,1.0f);
					glEnd();
				}
				//Top End

				//Center Top Start
				{
					//Boarder Start
					{
						glBegin(GL_QUADS);
						glVertex3f(0.04 + w, 0.325  + h,1.0f);
						glVertex3f(-0.3 + w, 0.325  + h,1.0f);
						glVertex3f(-0.3 + w, 0.08  + h,1.0f);
						glVertex3f(0.04 + w, 0.08  + h,1.0f);
						glEnd();
					}
					//Boarder End

					//Inside Start
					{
						glBegin(GL_QUADS);
						glVertex3f(-0.28 + w, 0.3  + h,1.0f);
						glVertex3f(-0.14 + w, 0.3  + h,1.0f);
						glVertex3f(-0.14 + w, 0.105  + h,1.0f);
						glVertex3f(-0.28 + w, 0.105  + h,1.0f);
						glEnd();

						glBegin(GL_QUADS);
						glVertex3f(-0.12 + w, 0.3  + h,1.0f);
						glVertex3f(0.02 + w, 0.3  + h,1.0f);
						glVertex3f(0.02 + w, 0.105  + h,1.0f);
						glVertex3f(-0.12 + w, 0.105  + h,1.0f);
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
						glVertex3f(0.04 + w, 0.08  + h,1.0f);
						glVertex3f(-0.3 + w, 0.08  + h,1.0f);
						glVertex3f(-0.3 + w, -0.20  + h,1.0f);
						glVertex3f(0.04 + w, -0.20  + h,1.0f);
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
									glVertex3f(x2, y2,1.0f);
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
									glVertex3f(x2, y2,1.0f);
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
									glVertex3f(x2, y2,1.0f);
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
									glVertex3f(x2, y2,1.0f);
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
									glVertex3f(x2, y2,1.0f);
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
									glVertex3f(x2, y2,1.0f);
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
					glVertex3f(-0.3 + w, -0.23  + h,1.0f);
					glVertex3f(0.04 + w, -0.23  + h,1.0f);
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
						glVertex3f(-0.78 + w, 0.435  + h,1.0f);
						glVertex3f(-0.3 + w, 0.435  + h,1.0f);
						glEnd();
					}
					//Top Line End

					//Right Lines Start
					{
						glBegin(GL_LINES);
						glVertex3f(-0.3 + w, 0.435  + h,1.0f);
						glVertex3f(-0.3 + w, -0.2  + h,1.0f);

						glVertex3f(-0.32 + w, -0.2  + h,1.0f);
						glVertex3f(-0.3 + w, -0.2  + h,1.0f);

						glVertex3f(-0.32 + w, -0.2  + h,1.0f);
						glVertex3f(-0.32 + w, -0.23  + h,1.0f);

						glVertex3f(-0.32 + w, -0.23  + h,1.0f);
						glVertex3f(-0.3 + w, -0.23  + h,1.0f);

						glVertex3f(-0.3 + w, -0.23  + h,1.0f);
						glVertex3f(-0.3 + w, -0.25  + h,1.0f);
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
								glVertex3f(-0.3 + w, -0.25  + h,1.0f);
								glVertex3f(-0.4 + w, -0.25  + h,1.0f);
							}
							//Right Loops End

							//Left Loops Start
							{
								glVertex3f(-0.755 + w, -0.25  + h,1.0f);
								glVertex3f(-0.83 + w, -0.25  + h,1.0f);
							}
							//Left Loops End

							//Bottom Left Loops Start
							{
								glVertex3f(-0.83 + w, -0.25  + h,1.0f);
								glVertex3f(-0.83 + w, -0.25  + h,1.0f);
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
									glVertex3f(x2, y2,1.0f);
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
									glVertex3f(x2, y2,1.0f);
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
									glVertex3f(x2, y2,1.0f);
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
									glVertex3f(x2, y2,1.0f);
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
									glVertex3f(x2, y2,1.0f);
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
									glVertex3f(x2, y2,1.0f);
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

							glVertex3f(-0.83 + w, -0.25  + h,1.0f);
							glVertex3f(-0.83 + w, -0.26  + h,1.0f);

							glVertex3f(-0.83 + w, -0.26  + h,1.0f);
							glVertex3f(-0.92 + w, -0.26  + h,1.0f);

							glVertex3f(-0.92 + w, -0.26  + h,1.0f);
							glVertex3f(-0.92 + w, -0.18  + h,1.0f);

							glVertex3f(-0.92 + w, -0.18  + h,1.0f);
							glVertex3f(-0.83 + w, -0.18  + h,1.0f);

							glVertex3f(-0.83 + w, -0.18  + h,1.0f);
							glVertex3f(-0.83 + w, -0.26  + h,1.0f);

							glEnd();
						}
						//Bottom Left End

						//Light Start
						{
							//Boarder Start
							{
								glBegin(GL_LINES);

								glVertex3f(-0.86 + w, -0.18  + h,1.0f);
								glVertex3f(-0.86 + w, -0.0  + h,1.0f);

								glVertex3f(-0.86 + w, -0.0  + h,1.0f);
								glVertex3f(-0.91 + w, 0.03  + h,1.0f);

								glVertex3f(-0.91 + w, 0.03  + h,1.0f);
								glVertex3f(-0.91 + w, -0.18  + h,1.0f);

								glEnd();
							}
							//Boarder End

							//Inside Start
							{
								glLineWidth(1);
								glBegin(GL_LINES);
								for (float a = 0.0;a > -0.18;a -= 0.01)
								{
									glVertex3f(-0.86 + w, a  + h,1.0f);
									glVertex3f(-0.91 + w, a  + h,1.0f);
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

							glVertex3f(-0.91 + w, 0.03  + h,1.0f);
							glVertex3f(-0.78 + w, 0.435  + h,1.0f);

							glVertex3f(-0.85 + w, 0.13  + h,1.0f);
							glVertex3f(-0.766 + w, 0.385  + h,1.0f);

							glVertex3f(-0.766 + w, 0.385  + h,1.0f);
							glVertex3f(-0.79 + w, 0.385  + h,1.0f);

							glVertex3f(-0.85 + w, 0.13  + h,1.0f);
							glVertex3f(-0.884 + w, 0.13  + h,1.0f);

							glEnd();
						}
						//Front Window End

						//Center Window Start
						{
							glBegin(GL_LINES);

							glVertex3f(-0.82 + w, 0.13  + h,1.0f);
							glVertex3f(-0.736 + w, 0.385  + h,1.0f);

							glVertex3f(-0.736 + w, 0.385  + h,1.0f);
							glVertex3f(-0.55 + w, 0.385  + h,1.0f);

							glVertex3f(-0.55 + w, 0.13  + h,1.0f);
							glVertex3f(-0.55 + w, 0.385  + h,1.0f);

							glVertex3f(-0.55 + w, 0.13  + h,1.0f);
							glVertex3f(-0.82 + w, 0.13  + h,1.0f);

							glEnd();

						}
						//Center Window End

						//Back Window Start
						{
							glBegin(GL_LINES);

							glVertex3f(-0.52 + w, 0.13  + h,1.0f);
							glVertex3f(-0.52 + w, 0.385  + h,1.0f);

							glVertex3f(-0.52 + w, 0.385  + h,1.0f);
							glVertex3f(-0.33 + w, 0.385  + h,1.0f);

							glVertex3f(-0.33 + w, 0.385  + h,1.0f);
							glVertex3f(-0.33 + w, 0.13  + h,1.0f);

							glVertex3f(-0.33 + w, 0.13  + h,1.0f);
							glVertex3f(-0.52 + w, 0.13  + h,1.0f);

							glEnd();

						}
						//Back Window End
					}
					//Windows End

					//Double Lines On Inside Start
					{
						glBegin(GL_QUADS);
						glVertex3f(-0.86 + w, -0.02  + h,1.0f);
						glVertex3f(-0.86 + w, 0.0  + h,1.0f);
						glVertex3f(-0.3 + w, 0.0  + h,1.0f);
						glVertex3f(-0.3 + w, -0.02  + h,1.0f);
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


	glutSwapBuffers();
}

void update(int value) {
	_angle += 1.5f;
	if (_angle > 360) {
		_angle -= 360;
	}

	glutPostRedisplay();
	glutTimerFunc(25, update, 0);
}

int main(int argc, char** argv) {
	//Initialize GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(400, 400);

	//Create the window
	glutCreateWindow("Lighting - videotutorialsrock.com");
	initRendering();

	//Set handler functions
	glutDisplayFunc(drawScene);
	glutKeyboardFunc(handleKeypress);
	glutReshapeFunc(handleResize);

	glutTimerFunc(25, update, 0); //Add a timer

	glutMainLoop();
	return 0;
}
