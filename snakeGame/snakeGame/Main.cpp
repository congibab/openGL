#include <stdio.h>
#include <GL/glew.h>
#include <GL/freeglut.h>

#include <iostream>

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3d(1.0, 0.0, 0.0);
	glBegin(GL_LINE_LOOP);
	glVertex2d(-0.5, 0.5);
	glVertex2d(-0.5, -0.5);
	glVertex2d(0.5, -0.5);
	glVertex2d(0.5, 0.5);
	glEnd();
	glFinish();
}

void reshape(GLint w, GLint h)
{
	glViewport(0, 0, w, h);
	glLoadIdentity();
	glOrtho(-w / 200.0, w / 200.0, -h / 200.0, h / 200.0, -1.0, 1.0);
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'q':
	case 'Q':
		std::cout << "test" << std::endl;
		break;
	case '\033':
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