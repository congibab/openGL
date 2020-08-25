#pragma once
#include <GL/glew.h>
#include <GL/freeglut.h>

struct Vector2D
{
	GLint x;
	GLint y;
};


class player
{
private:
	Vector2D vector2D;
	Vector2D Direction;

	bool collision();
	void main();
public:
	void Setvector2D(Vector2D pos);
	void SetDirection(Vector2D dir);
	Vector2D Getvector2D();

	void Init(GLint x, GLint y);
	void draw();
	Vector2D GetplayerPos();
};

