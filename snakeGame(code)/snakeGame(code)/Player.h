#pragma once

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <iostream>
#include <vector>
#include <string>

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
	std::vector<Vector2D> v;
	int index = 0;

	bool chack_Direction(Vector2D Dir);
	void collision();
public:
	void Init(GLint x, GLint y);
	void update();
	void draw();
	void Input(unsigned char key, int x, int y);
	void push_back();

	Vector2D GetPos() { return pos; };
	Vector2D Gettemp_pos() { return temp_pos; };
	Vector2D GetDir() { return Direction; };
	void SetPos(Vector2D position) { pos = position; };
};

