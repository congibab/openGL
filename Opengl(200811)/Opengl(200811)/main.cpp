
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>

#include <GL/glew.h>
#include <GL/freeglut.h>

#include <iostream>
#include "common.h"

using namespace std;

GLuint program;
GLint attribute_coord2d;

int Init_resources()
{
	GLint compile_ok = GL_FALSE, link_ok = GL_FALSE;
	
	GLuint vs = glCreateShader(GL_VERTEX_SHADER);
	const char* vs_source=
	
	#ifdef GL_ES_VERSION_2_0
		"#version 100\n"  // OpenGL ES 2.0
	#else
		"#version 120\n"  // OpenGL 2.1
	#endif
			"attribute vec2 coord2d;                  "
			"void main(void) {                        "
			"  gl_Position = vec4(coord2d, 0.0, 1.0); "
			"}";
	glShaderSource(vs, 1, &vs_source, NULL);
	glCompileShader(vs);
	glGetShaderiv(vs, GL_COMPILE_STATUS, &compile_ok);
	if (!compile_ok)
	{
		cout << "Error iin vertex shadder" << endl;
		return 0;
	}
	GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
	const char *fs_source =

	#ifdef GL_ES_VERSION_2_0
			"#version 100\n"  // OpenGL ES 2.0
	#else
			"#version 120\n"  // OpenGL 2.1
	#endif
			"void main(void) {        "
			"  gl_FragColor[0] = 0.0; "
			"  gl_FragColor[1] = 0.0; "
			"  gl_FragColor[2] = 1.0; "
			"}";
	glShaderSource(fs, 1, &fs_source, NULL);
	glCompileShader(fs);
	glGetShaderiv(fs, GL_COMPILE_STATUS, &compile_ok);
	if (!compile_ok)
	{
		cout << "Error iin vertex shadder" << endl;
		return 0;
	}

	program = glCreateProgram();
	glAttachShader(program, vs);
	glAttachShader(program, fs);
	glLinkProgram(program);
	glGetProgramiv(program, GL_LINK_STATUS, &link_ok);
	if (!link_ok)
	{
		cout << "glLinkProgram:";
		return 0;
	}

	const char* attribute_name = "coord2d";
	attribute_coord2d = glGetAttribLocation(program, attribute_name);
	if (attribute_coord2d == -1)
	{
		cout << "Could not bind attribute" << attribute_name << endl;
		return 0;
	}
	return 1;
}

void display(void)
{
	glClearColor(1.0, 1.0, 1.0, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	
	glUseProgram(program);
	glEnableVertexAttribArray(attribute_coord2d);
	GLfloat triangle_vertices[] =
	{
		0.8f,  0.8f,
	   -0.8f, -0.8f,
		0.8f, -0.8f,
	};

	glVertexAttribPointer(
		attribute_coord2d,
		2,
		GL_FLOAT,
		GL_FALSE,
		0,
		triangle_vertices
	);

	glDrawArrays(GL_TRIANGLES, 0, 3);

	glDisableVertexAttribArray(attribute_coord2d);
	glutSwapBuffers();
}

void display2()
{
	glClear(GL_COLOR_BUFFER_BIT);
	

	for (int i = 0; i < 10; i++)
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
	}
	//glColor3f(0.5, 0.5, 0.5);
	//
	//glBegin(GL_LINE_LOOP);
	//glVertex3f(-0.5, -0.5, 0);
	//glVertex3f(0.5, -0.5, 0);
	//glVertex3f(0.5, 0.5, 0);
	//glVertex3f(-0.5, 0.5, 0);
	//glEnd();

	//glBegin(GL_LINE_LOOP);
	//glVertex3f(0.5, -0.5, 0);
	//glVertex3f(1.5, -0.5, 0);
	//glVertex3f(1.5, 0.5, 0);
	//glVertex3f(0.5, 0.5, 0);
	//glEnd();

	glFlush();
}

void free_resource()
{
	glDeleteProgram(program);
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
	
	glutDisplayFunc(display2);
	glutReshapeFunc(Reshape);
	glutMainLoop();

	//GLenum glew_status = glewInit();
	//if (glew_status != GLEW_OK)
	//{
	//	cout << "Error:" << glewGetErrorString(glew_status) << endl;
	//	return 1;
	//}
	//Common c;

	//if (Init_resources())
	//{
	//	glutDisplayFunc(display);
	//	glutReshapeFunc(Reshape);
	//	glutMainLoop();
	//}

	//free_resource();
	return 0;

}

