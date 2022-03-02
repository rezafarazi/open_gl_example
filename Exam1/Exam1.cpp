#include "stdafx.h"
#include <iostream>
#include "GL\glut.h"
#include "math.h"

using namespace std;


void Display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.0);

	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	//Ladder Start
	{
		//Get Top Line Start
		{
			glBegin(GL_LINES);
			glLineWidth(50);
			{
				//Top Line Start
				glVertex2f(0.85, 0.7);
				glVertex2f(-0.85, 0.7);
				//Top Line End

				//Bottom Line Start
				glVertex2f(-0.85, 0.66);
				glVertex2f(0.85, 0.66);
				//Bottom Line End
			}
			glEnd();

			//Left Top Start
			{
				glPolygonMode(GL_FRONT_FACE, GL_LINE);
				glPointSize(2.0f);
				glBegin(GL_POINTS);
				double radius = 0.02;
				float x1 =  0.85, y1 = 0.681;
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
				glPolygonMode(GL_FRONT_FACE, GL_LINE);
				glPointSize(2.0f);
				glBegin(GL_POINTS);
				double radius = 0.02;
				float x1 = -0.85, y1 = 0.681;
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
				glVertex2f(0.85, 0.55);
				glVertex2f(-0.85, 0.55);
				//Top Line End

				//Bottom Line Start
				glVertex2f(-0.85, 0.51);
				glVertex2f(0.85, 0.51);
				//Bottom Line End
			}
			glEnd();

			//Left Bottom Start
			{
				glPolygonMode(GL_FRONT_FACE, GL_LINE);
				glPointSize(2.0f);
				glBegin(GL_POINTS);
				double radius = 0.02;
				float x1 = 0.85, y1 = 0.53;
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
				glPolygonMode(GL_FRONT_FACE, GL_LINE);
				glPointSize(2.0f);
				glBegin(GL_POINTS);
				double radius = 0.02;
				float x1 = -0.85, y1 = 0.53;
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
					glVertex2f(left, 0.66);
					glVertex2f(left += 0.2, 0.55);
				}
				//Left End

				//Left Start
				for (float left = -0.8;left <= 0.79;left += 0.2)
				{
					glVertex2f(left, 0.55);
					glVertex2f(left += 0.2, 0.66);
				}
				//Left End

				//Right Start
				for (float Rigth = 0.8;Rigth >= -0.79;Rigth -= 0.2)
				{
					glVertex2f(Rigth, 0.66);
					glVertex2f(Rigth -= 0.2, 0.55);
				}
				//Right End

				//Right Start
				for (float Rigth = 0.8;Rigth >= -0.79;Rigth -= 0.2)
				{
					glVertex2f(Rigth, 0.55);
					glVertex2f(Rigth -= 0.2, 0.66);
				}
				//Right End
			}
			//Frist Lines End

			//Secend Lines Start
			{
				//Left Start
				for (float left = -0.8;left <= 0.79;left += 0.2)
				{
					glVertex2f((left + 0.05), 0.66);
					glVertex2f(left + (0.2 + 0.05), 0.55);
				}
				//Left End

				//Left Start
				for (float left = -0.8;left <= 0.79;left += 0.2)
				{
					glVertex2f((left + 0.05), 0.55);
					glVertex2f(left + (0.2 + 0.05), 0.66);
				}
				//Left End

				//Right Start
				for (float Rigth = 0.8;Rigth >= -0.79;Rigth -= 0.2)
				{
					glVertex2f((Rigth + 0.05), 0.66);
					glVertex2f((Rigth - 0.2 + 0.05), 0.55);
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
			glVertex2f(0.65, 0.51);
			glVertex2f(0.35, 0.51);
			glVertex2f(0.38, 0.48);
			glVertex2f(0.63, 0.48);
			glEnd();
		}
		//Top End

		//Bottom Start
		{
			glBegin(GL_LINE_LOOP);
			glVertex2f(0.78, 0.48);
			glVertex2f(0.2, 0.48);
			glVertex2f(0.2, 0.435);
			glVertex2f(0.78, 0.435);
			glEnd();
		}
		//Bottom End

		//Bottom 2 Start
		{
			glBegin(GL_QUADS);
			glVertex2f(0.92, 0.435);
			glVertex2f(0.02, 0.435);
			glVertex2f(0.02, 0.40);
			glVertex2f(0.92, 0.40);
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

				glVertex2f(-0.5, 0.44);
				glVertex2f(-0.51, 0.53);

				glVertex2f(-0.51, 0.53);
				glVertex2f(-0.56, 0.53);

				glVertex2f(-0.56, 0.53);
				glVertex2f(-0.575, 0.44);

				glEnd();
			}
			//1

			//2
			{
				glBegin(GL_LINES);

				//Bottom Start
				{
					glVertex2f(-0.72, 0.44);
					glVertex2f(-0.72, 0.465);

					glVertex2f(-0.72, 0.465);
					glVertex2f(-0.635, 0.465);

					glVertex2f(-0.635, 0.465);
					glVertex2f(-0.635, 0.44);
				}
				//Bottom End

				//Top Start
				{
					glVertex2f(-0.695, 0.465);
					glVertex2f(-0.695, 0.49);

					glVertex2f(-0.695, 0.49);
					glVertex2f(-0.66, 0.49);

					glVertex2f(-0.66, 0.49);
					glVertex2f(-0.66, 0.465);
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
					glVertex2f(0.89, 0.40);
					glVertex2f(0.89, 0.0);
					glVertex2f(0.04, 0.0);
					glVertex2f(0.04, 0.40);
					glEnd();
				}
				//Out Side End

				//Inside Start
				{
					//Boxs Start
					{
						for (float a = 0.065; a < 0.7 ; a+=0.256)
						{
							glBegin(GL_QUADS);
							float Left = a ;
							float Right = Left + 0.265;
							glVertex2f(Right, 0.035);
							glVertex2f(Left + 0.03, 0.035);
							glVertex2f(Left + 0.03, 0.37);
							glVertex2f(Right, 0.37);
							glEnd();

							Left = (Left + (0.256 / 2));
							glBegin(GL_QUADS); 
							glVertex2f(Left+0.0435, 0.06);
							glVertex2f(Left, 0.06);
							glVertex2f(Left, 0.09);
							glVertex2f(Left+ 0.0435, 0.09);
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
				glVertex2f(0.89, -0.02);
				glVertex2f(0.89, 0.0);
				glVertex2f(0.04, 0.0);
				glVertex2f(0.04, -0.02);
				glEnd();
			}
			//Center Box End

			//Box Start
			{
				glBegin(GL_LINES);
				//Right
				{
					glVertex2f(0.89, -0.02);
					glVertex2f(0.89, -0.18);
				}
				//Right

				//Right Lines
				{
					glVertex2f(0.89, -0.18);
					glVertex2f(0.91, -0.18);	

					glVertex2f(0.91, -0.18);
					glVertex2f(0.91, -0.26);

					glVertex2f(0.91, -0.26);
					glVertex2f(0.83, -0.26);

					glVertex2f(0.83, -0.26);
					glVertex2f(0.83, -0.18);

					glVertex2f(0.83, -0.18);
					glVertex2f(0.89, -0.18);
				}
				//Right End

				//Left
				{
					glVertex2f(0.04, -0.02);
					glVertex2f(0.04, -0.2);
				}
				//Left

				//Left Lines
				{
					glVertex2f(0.04, -0.2);
					glVertex2f(0.06, -0.2);

					glVertex2f(0.06, -0.2);
					glVertex2f(0.06, -0.23);

					glVertex2f(0.06, -0.23);
					glVertex2f(0.04, -0.23);

					glVertex2f(0.04, -0.23);
					glVertex2f(0.04, -0.25);
				}
				//Left Lines

				//Bottom And Lines
				{
					glVertex2f(0.04, -0.25);
					glVertex2f(0.32, -0.25);					

					glVertex2f(0.68, -0.25);
					glVertex2f(0.83, -0.25);
				}
				//Bottom And Lines

				glEnd();
			}
			//Box End

			//Bottom Loops Start
			{
				//Inside Cricle 1 Start
				{
					glPolygonMode(GL_FRONT_FACE, GL_LINE);
					glPointSize(2.5f);
					glBegin(GL_POINTS);
					double radius = 0.18;
					float x1 = 0.5, y1 = -0.25;
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
				glPolygonMode(GL_FRONT_FACE, GL_LINE);
				glPointSize(1.5f);
				glBegin(GL_POINTS);
				double radius = 0.212;
				float x1 = 0.5, y1 = -0.25;
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
					glPolygonMode(GL_FRONT_FACE, GL_LINE);
					glPointSize(2.5f);
					glBegin(GL_POINTS);
					double radius = 0.15;
					float x1 = 0.5, y1 = -0.25;
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
					glPolygonMode(GL_FRONT_FACE, GL_LINE);
					glPointSize(0.5f);
					glBegin(GL_POINTS);
					double radius = 0.06;
					float x1 = 0.5, y1 = -0.25;
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
					glPolygonMode(GL_FRONT_FACE, GL_LINE);
					glPointSize(0.5f);
					glBegin(GL_POINTS);
					double radius = 0.04;
					float x1 = 0.5, y1 = -0.25;
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
					glPolygonMode(GL_FRONT_FACE, GL_LINE);
					glPointSize(0.5f);
					glBegin(GL_POINTS);
					double radius = 0.02;
					float x1 = 0.5, y1 = -0.25;
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
				glVertex2f(0.04, 0.385);
				glVertex2f(-0.3, 0.385);
				glVertex2f(-0.3, 0.325);
				glVertex2f(0.04, 0.325);
				glEnd();
			}
			//Top End

			//Center Top Start
			{
				//Boarder Start
				{
					glBegin(GL_QUADS);
					glVertex2f(0.04, 0.325);
					glVertex2f(-0.3, 0.325);
					glVertex2f(-0.3, 0.08);
					glVertex2f(0.04, 0.08);
					glEnd();
				}
				//Boarder End

				//Inside Start
				{
					glBegin(GL_QUADS);
					glVertex2f(-0.28, 0.3);
					glVertex2f(-0.14, 0.3);
					glVertex2f(-0.14, 0.105);
					glVertex2f(-0.28, 0.105);
					glEnd();

					glBegin(GL_QUADS);
					glVertex2f(-0.12, 0.3);
					glVertex2f(0.02, 0.3);
					glVertex2f(0.02, 0.105);
					glVertex2f(-0.12, 0.105);
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
					glVertex2f(0.04, 0.08);
					glVertex2f(-0.3, 0.08);
					glVertex2f(-0.3, -0.20);
					glVertex2f(0.04, -0.20);
					glEnd();
				}
				//Boarder End

				//Inside Start
				{
					//Top
					{
						//Cricle 1 Start
						{
							glPolygonMode(GL_FRONT_FACE, GL_LINE);
							glPointSize(3.0f);
							glBegin(GL_POINTS);
							double radius = 0.035;
							float x1 = -0.015, y1 = 0.0;
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
							glPolygonMode(GL_FRONT_FACE, GL_LINE);
							glPointSize(3.0f);
							glBegin(GL_POINTS);
							double radius = 0.035;
							float x1 = -0.13, y1 = 0.0;
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
						glPolygonMode(GL_FRONT_FACE, GL_LINE);
						glPointSize(3.0f);
						glBegin(GL_POINTS);
						double radius = 0.035;
						float x1 = -0.245, y1 = 0.0;
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
							glPolygonMode(GL_FRONT_FACE, GL_LINE);
							glPointSize(3.0f);
							glBegin(GL_POINTS);
							double radius = 0.035;
							float x1 = -0.015, y1 = -0.11;
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
							glPolygonMode(GL_FRONT_FACE, GL_LINE);
							glPointSize(3.0f);
							glBegin(GL_POINTS);
							double radius = 0.035;
							float x1 = -0.13, y1 = -0.11;
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
							glPolygonMode(GL_FRONT_FACE, GL_LINE);
							glPointSize(3.0f);
							glBegin(GL_POINTS);
							double radius = 0.035;
							float x1 = -0.245, y1 = -0.11;
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
				glVertex2f(-0.3, -0.23);
				glVertex2f(0.04, -0.23);
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
					glVertex2f(-0.78, 0.435);
					glVertex2f(-0.3, 0.435);
					glEnd();
				}
				//Top Line End

				//Right Lines Start
				{
					glBegin(GL_LINES);
					glVertex2f(-0.3, 0.435);
					glVertex2f(-0.3, -0.2);

					glVertex2f(-0.32, -0.2);
					glVertex2f(-0.3, -0.2);

					glVertex2f(-0.32, -0.2);
					glVertex2f(-0.32, -0.23);

					glVertex2f(-0.32, -0.23);
					glVertex2f(-0.3, -0.23);

					glVertex2f(-0.3, -0.23);
					glVertex2f(-0.3, -0.25);
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
							glVertex2f(-0.3, -0.25);
							glVertex2f(-0.4, -0.25);
						}
						//Right Loops End

						//Left Loops Start
						{
							glVertex2f(-0.755, -0.25);
							glVertex2f(-0.83, -0.25);
						}
						//Left Loops End

						//Bottom Left Loops Start
						{
							glVertex2f(-0.83, -0.25);
							glVertex2f(-0.83, -0.25);
						}
						//Bottom Left Loops End

						glEnd();
					}
					//Bottom Lines End

					//Bottom Loops Start
					{
						//Inside Cricle 1 Start
						{
							glPolygonMode(GL_FRONT_FACE, GL_LINE);
							glPointSize(2.5f);
							glBegin(GL_POINTS);
							double radius = 0.18;
							float x1 = -0.58, y1 = -0.25;
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
						glPolygonMode(GL_FRONT_FACE, GL_LINE);
						glPointSize(1.5f);
						glBegin(GL_POINTS);
						double radius = 0.212;
						float x1 = -0.58, y1 = -0.25;
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
							glPolygonMode(GL_FRONT_FACE, GL_LINE);
							glPointSize(2.5f);
							glBegin(GL_POINTS);
							double radius = 0.15;
							float x1 = -0.58, y1 = -0.25;
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
							glPolygonMode(GL_FRONT_FACE, GL_LINE);
							glPointSize(0.5f);
							glBegin(GL_POINTS);
							double radius = 0.06;
							float x1 = -0.58, y1 = -0.25;
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
							glPolygonMode(GL_FRONT_FACE, GL_LINE);
							glPointSize(0.5f);
							glBegin(GL_POINTS);
							double radius = 0.04;
							float x1 = -0.58, y1 = -0.25;
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
							glPolygonMode(GL_FRONT_FACE, GL_LINE);
							glPointSize(0.5f);
							glBegin(GL_POINTS);
							double radius = 0.02;
							float x1 = -0.58, y1 = -0.25;
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

						glVertex2f(-0.83, -0.25);
						glVertex2f(-0.83, -0.26);

						glVertex2f(-0.83, -0.26);
						glVertex2f(-0.92, -0.26);

						glVertex2f(-0.92, -0.26);
						glVertex2f(-0.92, -0.18);

						glVertex2f(-0.92, -0.18);
						glVertex2f(-0.83, -0.18);

						glVertex2f(-0.83, -0.18);
						glVertex2f(-0.83, -0.26);

						glEnd();
					}
					//Bottom Left End

					//Light Start
					{
						//Boarder Start
						{
							glBegin(GL_LINES);

							glVertex2f(-0.86, -0.18);
							glVertex2f(-0.86, -0.0);

							glVertex2f(-0.86, -0.0);
							glVertex2f(-0.91, 0.03);

							glVertex2f(-0.91, 0.03);
							glVertex2f(-0.91, -0.18);

							glEnd();
						}
						//Boarder End

						//Inside Start
						{
							glLineWidth(1);
							glBegin(GL_LINES);
							for (float a=0.0;a>-0.18;a-=0.01)
							{
								glVertex2f(-0.86, a);
								glVertex2f(-0.91, a);
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

						glVertex2f(-0.91, 0.03);
						glVertex2f(-0.78, 0.435);

						glVertex2f(-0.85, 0.13);
						glVertex2f(-0.766, 0.385);

						glVertex2f(-0.766, 0.385);
						glVertex2f(-0.79, 0.385);

						glVertex2f(-0.85, 0.13);
						glVertex2f(-0.884, 0.13);

						glEnd();
					}
					//Front Window End

					//Center Window Start
					{
						glBegin(GL_LINES);

						glVertex2f(-0.82, 0.13);
						glVertex2f(-0.736, 0.385);

						glVertex2f(-0.736, 0.385);
						glVertex2f(-0.55, 0.385);

						glVertex2f(-0.55, 0.13);
						glVertex2f(-0.55, 0.385);

						glVertex2f(-0.55, 0.13);
						glVertex2f(-0.82, 0.13);

						glEnd();

					}
					//Center Window End

					//Back Window Start
					{
						glBegin(GL_LINES);

						glVertex2f(-0.52, 0.13);
						glVertex2f(-0.52, 0.385);

						glVertex2f(-0.52, 0.385);
						glVertex2f(-0.33, 0.385);

						glVertex2f(-0.33, 0.385);
						glVertex2f(-0.33, 0.13);

						glVertex2f(-0.33, 0.13);
						glVertex2f(-0.52, 0.13);

						glEnd();

					}
					//Back Window End
				}
				//Windows End

				//Double Lines On Inside Start
				{
					glBegin(GL_QUADS);
					glVertex2f(-0.86, -0.02);
					glVertex2f(-0.86, 0.0);
					glVertex2f(-0.3, 0.0);
					glVertex2f(-0.3, -0.02);
					glEnd();
				}
				//Double Lines On Inside End

			}
			//Main Boarder End
		}
		//Front Track End

	}
	//Track End


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
	glutInitWindowSize(700, 700);
	glutCreateWindow("Reza Fta");
	glutDisplayFunc(Display);
	setup();
	glutMainLoop();
	return 0;
}
