/**
 * From the OpenGL Programming wikibook: http://en.wikibooks.org/wiki/OpenGL_Programming
 * This file is in the public domain.
 * Contributors: Sylvain Beucler
 */
#include <stdio.h>
#include <stdlib.h>
 /* Use glew.h instead of gl.h to get all the GL prototypes declared */
#include <GL/glew.h>
/* Using the GLUT library for the base windowing setup */
#include <GL/freeglut.h>

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(0.5, 0.5, 0.5);
	glBegin(GL_TRIANGLES);
	glVertex3f(0.0, 0.5, 0);
	glVertex3f(-0.5, -0.5, 0);
	glVertex3f(0.5, -0.5, 0);
	glEnd();
	glFinish();
}



int main(int argc, char* argv[])
{

	glutInit(&argc, argv);
	glutCreateWindow(argv[0]);
	glClearColor(1.0, 1.0, 1.0, 1);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;

}

