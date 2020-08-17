
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>

#include <GL/glew.h>
#include <GL/freeglut.h>

#include <iostream>
#include "common.h"
#include "TextureManager.h"

using namespace std;

float x_pos = 0.0f;
float y_pos = 0.0f;

TextureManager tex;

void display()
{
	GLuint img = tex.LoadGLTextures("opengl.jpg");
	GLuint img1 = tex.LoadGLTextures("maitetsu.jpg");

	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(x_pos, y_pos, 1,
			  x_pos, y_pos, 0,
				0, 1, 0);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, img1);
	glBegin(GL_POLYGON);
	glTexCoord2f(0, 0); glVertex2d(-5, -10);
	glTexCoord2f(0, 1); glVertex2d(-5, 10);
	glTexCoord2f(1, 1); glVertex2d(5, 10);
	glTexCoord2f(1, 0); glVertex2d(5, -10);
	glDisable(GL_TEXTURE_2D);
	glEnd();


	//glEnable(GL_TEXTURE_2D);
	//glBindTexture(GL_TEXTURE_2D, img);
	//glBegin(GL_QUADS);
	//glTexCoord2f(0, 0); glVertex2d(4, 4);
	//glTexCoord2f(0, 1); glVertex2d(4, 6);
	//glTexCoord2f(1, 1); glVertex2d(6, 6);
	//glTexCoord2f(1, 0); glVertex2d(6, 4);
	//glDisable(GL_TEXTURE_2D);
	//glEnd();


	/*for (int i = 0; i < 10; i++)
	{
		glColor3f(0.5, 0.5, 0.5);
		for (int j = 0; j < 10; j++)
		{
			glBegin(GL_LINE_LOOP);
			glVertex3f(i*0.2-0.2 -1.0, j*0.2-0.2 -1.0, 0);
			glVertex3f(i*0.2+0.2 -1.0, j*0.2-0.2 -1.0, 0);
			glVertex3f(i*0.2+0.2 -1.0, j*0.2+0.2 -1.0, 0);
			glVertex3f(i*0.2-0.2 -1.0, j*0.2+0.2 -1.0, 0);
			glEnd();
		}
	}*/
	glFlush();
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'q':
	case 'Q':
		cout << "Input key q" << endl;
		break;
		//================================
	case 'a':
	case 'A':
		x_pos += 0.1f;
		glutPostRedisplay();
		cout << "off_set (" << x_pos << " , " << y_pos << ")" << endl;

		break;
	case 'd':
	case 'D':
		x_pos -= 0.1f;
		glutPostRedisplay();
		cout << "off_set (" << x_pos << " , " << y_pos << ")" << endl;
		break;
	case 'w':
	case 'W':
		y_pos -= 0.1f;
		glutPostRedisplay();
		cout << "off_set (" << x_pos << " , " << y_pos << ")" << endl;
		break;
	case 's':
	case 'S':
		y_pos += 0.1f;
		glutPostRedisplay();
		cout << "off_set (" << x_pos << " , " << y_pos << ")" << endl;
		break;
		//--------------------------------
	case 27:
		cout << "Input key Esc" << endl;
		exit(0);
		break;
	default:
		break;
	}

}

void Reshape(int NewWidth, int NewHeight)
{
	glViewport(0, 0, NewWidth, NewHeight);
	GLfloat WidthFactor = (GLfloat)NewWidth / (GLfloat)300;
	GLfloat HeightFactor = (GLfloat)NewHeight / (GLfloat)300;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0*WidthFactor, 1.0*WidthFactor, -1.0* HeightFactor, 1.0 * HeightFactor, -1.0, 1.0);
	
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitContextVersion(2, 0);
	glutInitDisplayMode(GLUT_RGBA);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(1200, 100);
	glutCreateWindow("open GL");
	
	glutDisplayFunc(display);
	glutReshapeFunc(Reshape);
	glutKeyboardFunc(keyboard);
	

	glutMainLoop();

	return 0;

}

