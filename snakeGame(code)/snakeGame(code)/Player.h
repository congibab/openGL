#pragma once

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <iostream>

struct Vector2D
{
	GLint x;
	GLint y;
};


class Player
{
private:
	Vector2D pos;
	Vector2D temp_pos;
	Vector2D Direction;
public:
	void Init(GLint x, GLint y);
	void update();
	void draw();
	void Input(unsigned char key, int x, int y);

	Vector2D GetPos() { return pos; };
	Vector2D Gettemp_pos() { return temp_pos; };
	Vector2D SetPos(Vector2D position) { pos = position; };
};

