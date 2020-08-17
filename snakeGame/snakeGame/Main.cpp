#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/glm.hpp>
#include <FreeImage.h>
#include <iostream>


#include "TextureManager.h"

using namespace std;

TextureManager texturemanager;

GLfloat off_set_x = 0;
GLfloat off_set_y = 0;

GLfloat camera_x = 0;
GLfloat camera_y = 0;

GLuint textureid;
GLuint test;
GLuint test1;

void display()
{


	glClear(GL_COLOR_BUFFER_BIT);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, test1);
	glBegin(GL_POLYGON);
	glTexCoord2f(0, 0); glVertex2d(0, 0);
	glTexCoord2f(0, 1); glVertex2d(0, 10);
	glTexCoord2f(1, 1); glVertex2d(10, 10);
	glTexCoord2f(1, 0); glVertex2d(10, 0);
	glBindTexture(GL_TEXTURE_2D, 0);
	glDisable(GL_TEXTURE_2D);
	glEnd();

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureid);
	glBegin(GL_POLYGON);
	glTexCoord2f(0, 0); glVertex2d(10, 10);
	glTexCoord2f(0, 1); glVertex2d(10, 20);
	glTexCoord2f(1, 1); glVertex2d(20, 20);
	glTexCoord2f(1, 0); glVertex2d(20, 10);
	glBindTexture(GL_TEXTURE_2D, 0);
	glDisable(GL_TEXTURE_2D);

	glEnd();

	//for (int i = 0; i < 20; i++)
	//{
	//	for (int j = 0; j < 20; j++)
	//	{	
	//		glBegin(GL_LINE_LOOP);
	//		glVertex2d(i - 0.5 - off_set_x, j + 0.5 - off_set_y);
	//		glVertex2d(i - 0.5 - off_set_x, j - 0.5 - off_set_y);
	//		glVertex2d(i + 0.5 - off_set_x, j - 0.5 - off_set_y);
	//		glVertex2d(i + 0.5 - off_set_x, j + 0.5 - off_set_y);
	//		glEnd();
	//	}
	//}

	glFinish();
}

void reshape(GLint w, GLint h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, w / 25, 0.0, h / 25, -1.0, 1.0);
	//glOrtho(-w / 50.0, w / 50.0, -h / 50.0, h / 50.0, -1.0, 1.0);
	
	cout << "width:" << w << " height:" << h << endl;
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
		off_set_x += 0.5;
		glutPostRedisplay();
		break;
	case 'd':
	case 'D':
		off_set_x -= 0.5;
		glutPostRedisplay();
		break;
	case 'w':
	case 'W':
		off_set_y -= 0.5;
		glutPostRedisplay();
		break;
	case 's':
	case 'S':
		off_set_y += 0.5;
		glutPostRedisplay();
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

void init()
{
	glClearColor(1.0, 1.0, 1.0, 0);
	textureid = texturemanager.CreateTexture("maitetsu.jpg");
	test = texturemanager.LoadGLTextures("maitetsu.jpg");
	test1 = texturemanager.LoadGLTextures("opengl.jpg");
}

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowPosition(1200, 100);
	glutInitWindowSize(500,500);
	glutCreateWindow("Snake Game");
	
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	init();
	glutMainLoop();

	return 0;
}
