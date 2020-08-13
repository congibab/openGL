#include <stdio.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/glm.hpp>

#include <iostream>

using namespace std;

GLfloat off_set_x = 0;
GLfloat off_set_y = 0;

GLfloat camera_x = 0;
GLfloat camera_y = 0;


void display()
{
	glLineWidth(1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3d(1.0, 0.0, 0.0);

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{	
			glBegin(GL_LINE_LOOP);
			glVertex2d(i - 0.5 - off_set_x, j + 0.5 - off_set_y);
			glVertex2d(i - 0.5 - off_set_x, j - 0.5 - off_set_y);
			glVertex2d(i + 0.5 - off_set_x, j - 0.5 - off_set_y);
			glVertex2d(i + 0.5 - off_set_x, j + 0.5 - off_set_y);
			glEnd();
		}
	}
	glFinish();
}

void reshape(GLint w, GLint h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//glOrtho(0.0, 40.0, 0.0, 40.0, -1.0, 1.0);
	glOrtho(-w / 50.0, w / 50.0, -h / 50.0, h / 50.0, -1.0, 1.0);
	
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
		cout << "Input key a" << endl;
		break;
	case 'd':
	case 'D':
		off_set_x -= 0.5;
		glutPostRedisplay();
		cout << "Input key d" << endl;
		break;
	case 'w':
	case 'W':
		off_set_y -= 0.5;
		glutPostRedisplay();
		cout << "Input key w" << endl;
		break;
	case 's':
	case 'S':
		off_set_y += 0.5;
		glutPostRedisplay();
		cout << "Input key s" << endl;
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